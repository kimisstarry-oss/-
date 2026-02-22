#include "nowsee.h"
#include "ui_nowsee.h"
#include <QFile>
#include <QCameraInfo>
#include <QDateTime>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QUrl>

Nowsee::Nowsee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Nowsee),
    m_camera(nullptr),
    m_imageCapture(nullptr),
    m_mediaRecorder(nullptr),
    m_videoWidget(nullptr),
    m_recordTimer(new QTimer(this)),
    m_recordSeconds(0),
    m_isRecording(false)
{
    ui->setupUi(this);

    ui->label->setText("<img src = 'qrc:/image/摄像机.png' width = '35' height = '35'> "
                       "<span style='font-size:30px;'>实时画面监控</span>");

    ui->frame_video->setStyleSheet(
        "background-color: black;"
        "border: 2px solid #3498db;"
        "border-radius: 5px;"
    );

    ui->label_status->setStyleSheet(
                "font-size: 14px;"
                "color: #e74c3c;"
                "font-weight: bold;");

    ui->label_recordTime->setStyleSheet(
                "font-size: 14px;"
                "color: #e74c3c;"
                "font-weight: bold;");

    QFile file(":/qss/component/style.qss");
    if(file.open(QFile::ReadOnly)){
        QByteArray arr = file.readAll();
        this->setStyleSheet(arr);
    }

//--------------------------------------样式----------------------------------------------
    // 初始化视频显示区域
    m_videoWidget = new QVideoWidget(ui->frame_video);
    QVBoxLayout *frameLayout = new QVBoxLayout(ui->frame_video);
    frameLayout->setContentsMargins(0, 0, 0, 0);
    frameLayout->addWidget(m_videoWidget);

    // 初始禁用按钮
    ui->pushButton_stop->setEnabled(false);
    ui->pushButton_capture->setEnabled(false);
    ui->pushButton_record->setEnabled(false);

    // 连接信号槽（Qt Designer会自动连接on_控件名_clicked，这里显式连接其他信号）
    connect(ui->pushButton_start, &QPushButton::clicked, this, &Nowsee::on_pushButton_start_clicked);
    connect(ui->pushButton_stop, &QPushButton::clicked, this, &Nowsee::on_pushButton_stop_clicked);
    connect(ui->pushButton_capture, &QPushButton::clicked, this, &Nowsee::on_pushButton_capture_clicked);
    connect(ui->pushButton_record, &QPushButton::clicked, this, &Nowsee::on_pushButton_record_clicked);
    connect(m_recordTimer, &QTimer::timeout, this, &Nowsee::updateRecordTime);

    // 初始化摄像头
    setupCamera();
}

Nowsee::~Nowsee()
{
    if (m_camera && m_camera->state() != QCamera::UnloadedState) {
            m_camera->stop();
        }
    delete ui;
}

void Nowsee::setupCamera()
{
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

    if (cameras.isEmpty()) {
        ui->label_status->setText("未检测到摄像头");
        return;
    }

    // 使用第一个摄像头
    QCameraInfo cameraInfo = cameras.first();
    m_camera = new QCamera(cameraInfo, this);
    m_camera->setViewfinder(m_videoWidget);

    // 图像捕获
    m_imageCapture = new QCameraImageCapture(m_camera, this);
    m_imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);

    // 视频录制
    m_mediaRecorder = new QMediaRecorder(m_camera, this);

    // 设置视频参数
    QVideoEncoderSettings videoSettings;
    videoSettings.setCodec("video/mp4");
    videoSettings.setResolution(640, 480);
    videoSettings.setQuality(QMultimedia::HighQuality);
    videoSettings.setFrameRate(30.0);
    m_mediaRecorder->setVideoSettings(videoSettings);

    // 连接信号
    connect(m_camera, QOverload<QCamera::Error>::of(&QCamera::error),
            this, &Nowsee::cameraError);
    connect(m_camera, &QCamera::stateChanged,
            this, &Nowsee::cameraStateChanged);
    connect(m_imageCapture, &QCameraImageCapture::imageSaved,
            this, &Nowsee::imageSaved);
    connect(m_mediaRecorder, QOverload<QMediaRecorder::Error>::of(&QMediaRecorder::error),
            this, &Nowsee::recorderError);
}

void Nowsee::on_pushButton_start_clicked()
{
    if (m_camera) {
        m_camera->start();
        ui->label_status->setText("摄像头启动中...");
        ui->label_status->setStyleSheet("font-size: 14px; color: #f39c12; font-weight: bold;");
    }
}

void Nowsee::on_pushButton_stop_clicked()
{
    if (m_isRecording) {
        stopRecording();
    }

    if (m_camera && m_camera->state() != QCamera::UnloadedState) {
        m_camera->stop();
    }
}

void Nowsee::on_pushButton_capture_clicked()
{
    if (m_imageCapture && m_camera->state() == QCamera::ActiveState) {
        QString fileName = getSavePath("image");
        m_imageCapture->capture(fileName);
        ui->label_status->setText("正在抓拍照片...");
    }
}

void Nowsee::on_pushButton_record_clicked()
{
    if (!m_isRecording) {
        startRecording();
    } else {
        stopRecording();
    }
}

void Nowsee::startRecording()
{
    if (m_mediaRecorder && m_camera->state() == QCamera::ActiveState) {
        QString filePath = getSavePath("video");
        m_mediaRecorder->setOutputLocation(QUrl::fromLocalFile(filePath));
        m_mediaRecorder->record();

        m_isRecording = true;
        m_recordSeconds = 0;
        m_recordTimer->start(1000);

        ui->pushButton_record->setText("停止录制");
        ui->label_recordTime->setVisible(true);
        ui->label_recordTime->setText("录制中: 00:00");
        ui->label_status->setText("视频录制中...");
        ui->label_status->setStyleSheet("font-size: 14px; color: #e74c3c; font-weight: bold;");
    }
}

void Nowsee::stopRecording()
{
    if (m_mediaRecorder && m_isRecording) {
        m_mediaRecorder->stop();
        m_isRecording = false;
        m_recordTimer->stop();

        ui->pushButton_record->setText("视频录制");
        ui->label_recordTime->setVisible(false);
        ui->label_status->setText("视频录制已停止");
        ui->label_status->setStyleSheet("font-size: 14px; color: #2ecc71; font-weight: bold;");
    }
}

void Nowsee::updateRecordTime()
{
    m_recordSeconds++;
    int minutes = m_recordSeconds / 60;
    int seconds = m_recordSeconds % 60;
    ui->label_recordTime->setText(QString("录制中: %1:%2")
                               .arg(minutes, 2, 10, QLatin1Char('0'))
                               .arg(seconds, 2, 10, QLatin1Char('0')));
}

QString Nowsee::getSavePath(const QString &type)
{
    QString baseDir;
    QString subDir;

    if (type == "image") {
        baseDir = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
        subDir = "/RK3568_Capture";
    } else {
        baseDir = QStandardPaths::writableLocation(QStandardPaths::MoviesLocation);
        subDir = "/RK3568_Record";
    }

    if (baseDir.isEmpty()) {
        baseDir = QDir::currentPath();
    }

    QDir dir(baseDir + subDir);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");

    if (type == "image") {
        return dir.filePath("capture_" + timestamp + ".jpg");
    } else {
        return dir.filePath("record_" + timestamp + ".mp4");
    }
}

void Nowsee::cameraStateChanged(QCamera::State state)
{
    QString stateText, color;

    switch (state) {
    case QCamera::UnloadedState:
        stateText = "摄像头未加载";
        color = "#e74c3c";
        ui->pushButton_start->setEnabled(true);
        ui->pushButton_stop->setEnabled(false);
        ui->pushButton_capture->setEnabled(false);
        ui->pushButton_record->setEnabled(false);
        break;
    case QCamera::LoadedState:
        stateText = "摄像头已加载";
        color = "#f39c12";
        ui->pushButton_start->setEnabled(true);
        ui->pushButton_stop->setEnabled(false);
        ui->pushButton_capture->setEnabled(false);
        ui->pushButton_record->setEnabled(false);
        break;
    case QCamera::ActiveState:
        stateText = "摄像头运行中";
        color = "#2ecc71";
        ui->pushButton_start->setEnabled(false);
        ui->pushButton_stop->setEnabled(true);
        ui->pushButton_capture->setEnabled(true);
        ui->pushButton_record->setEnabled(true);
        break;
    }

    ui->label_status->setText("状态：" + stateText);
    ui->label_status->setStyleSheet(QString("font-size: 14px; color: %1; font-weight: bold;").arg(color));
}

void Nowsee::cameraError(QCamera::Error error)
{
    Q_UNUSED(error);
    ui->label_status->setText("摄像头错误: " + m_camera->errorString());
    ui->label_status->setStyleSheet("font-size: 14px; color: #e74c3c; font-weight: bold;");
}

void Nowsee::imageSaved(int id, const QString &fileName)
{
    Q_UNUSED(id);
    ui->label_status->setText("照片已保存: " + QFileInfo(fileName).fileName());
    ui->label_status->setStyleSheet("font-size: 14px; color: #2ecc71; font-weight: bold;");
    QMessageBox::information(this, "抓拍成功", "照片已保存到:\n" + fileName);
}

void Nowsee::recorderError(QMediaRecorder::Error error)
{
    Q_UNUSED(error);
    ui->label_status->setText("录制错误: " + m_mediaRecorder->errorString());
    ui->label_status->setStyleSheet("font-size: 14px; color: #e74c3c; font-weight: bold;");

    if (m_isRecording) {
        stopRecording();
    }
}
