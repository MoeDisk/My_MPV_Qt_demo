#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextEdit>
#include "mpv_qt.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();   //播放停止
    void on_pauseButton_clicked();  //暂停恢复
    void on_recordButton_clicked(); //录制
    void paltEnd_slot();   //接收播放结束信号槽参数

private:
    Ui::MainWindow *ui;

    QTextEdit *log;
    void append_log(const QString &text);

    bool isPlay();  //判断是否播放中
    bool isRecord(); //判断是否录制中

    MpvPlayer *mpvPlayer;
    bool m_isPlay;
    bool m_isRecord;
};

#endif // MAINWINDOW_H
