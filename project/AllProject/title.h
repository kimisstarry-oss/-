#ifndef TITLE_H
#define TITLE_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class Title;
}

class Title : public QWidget
{
    Q_OBJECT

public:
    explicit Title(QWidget *parent = nullptr);
    void setConnectionStatus(bool connected);
    void setGatewayName(const QString &name);//设置网关名称并更新标题栏显示。
    ~Title();
signals:
    void connectionStatusChanged(bool connected);

private slots:
    void updateConnectionAnimation();//更新链接动画
private:
    void updateStatusIcon();//更新状态图标

private:
    Ui::Title *ui;

    //状态变量
    bool m_isConnected;
    QString m_gatewayName;
    QTimer *m_animationTimer;
    int m_animationStep;
};

#endif // TITLE_H
