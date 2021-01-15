//请拷贝动态链接库(libmpv.dll.a和mpv-1.dll)

#ifndef MPV_QT_H
#define MPV_QT_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <client.h> //MPV库头文件

class MpvPlayer:public QWidget{
    Q_OBJECT

public:
    MpvPlayer(QWidget *parent);
    virtual ~MpvPlayer();
    void create_mpvPlayer(QWidget *videoWin);   //创建mpvPlayer
    void setProperty(const QString &name, const QString &value);    //设置MPV属性
    QString getProperty(const QString &name) const; //获得mpv属性
    void play(QString filename);    //播放

private slots:
    void on_mpv_events();   //事件信号，被wakeup()调用(通过mpv_events信号)

signals:
    void mpv_events();  //触发on_mpv_events()槽函数的信号
    void mpv_palyEnd(); //播放结束信号

private:
    mpv_handle *mpv;
    void handle_mpv_event(mpv_event *event);    //处理mpv事件
};

#endif // MPV_QT_H
