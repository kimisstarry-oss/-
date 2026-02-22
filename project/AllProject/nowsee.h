#ifndef NOWSEE_H
#define NOWSEE_H

#include <QWidget>
#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QVideoWidget>
#include <QTimer>

namespace Ui {
class Nowsee;
}

class Nowsee : public QWidget
{
    Q_OBJECT

public:
    explicit Nowsee(QWidget *parent = nullptr);
    ~Nowsee();



private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_capture_clicked();

    void on_pushButton_record_clicked();

    void updateRecordTime();                // 更新录制时间

    // 摄像头状态处理
    void cameraStateChanged(QCamera::State state);
    void cameraError(QCamera::Error error);

    // 图像捕获处理
    void imageSaved(int id, const QString &fileName);

    // 视频录制处理
    void recorderError(QMediaRecorder::Error error);

private:
    void setupCamera();
    void startRecording();
    void stopRecording();
    QString getSavePath(const QString &type);
private:
    Ui::Nowsee *ui;
    QCamera *m_camera;
    QCameraImageCapture *m_imageCapture;
    QMediaRecorder *m_mediaRecorder;
    QVideoWidget *m_videoWidget;
    QTimer *m_recordTimer;

    int m_recordSeconds;
    bool m_isRecording;
};

#endif // NOWSEE_H
