#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mpvPlayer = new MpvPlayer(ui->displayWidget);
    m_isPlay=false;
    m_isRecord=false;

    connect(mpvPlayer, &MpvPlayer::mpv_palyEnd, this, &MainWindow::paltEnd_slot);

    statusBar();

//    QMainWindow *log_window = new QMainWindow(this);
//    log = new QTextEdit(log_window);
//    log->setReadOnly(true);
//    log_window->setCentralWidget(log);
//    log_window->setWindowTitle("mpv log window");
//    log_window->setMinimumSize(500, 50);
//    log_window->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//判断是否播放中
bool MainWindow::isPlay(){
    return m_isPlay;
}
//判断是否录制中
bool MainWindow::isRecord(){
    return m_isRecord;
}
//播放停止
void MainWindow::on_playButton_clicked(){
    QString videoName=QFileDialog::getOpenFileName(this);
    //判断是否播放中
    if(!isPlay()){
        m_isPlay=true;
        ui->playButton->setText("Stop");
        mpvPlayer->play(videoName); //播放
    }
    else{
        m_isPlay=false;
        ui->playButton->setText("Play");
        ui->pauseButton->setText("Pause");
        mpvPlayer->setProperty("pause","no");
        mpvPlayer->play(" ");   //播放空视频达到停止效果
    }
}
//暂停恢复视频
void MainWindow::on_pauseButton_clicked(){
    if(!isPlay()){
        QMessageBox::warning(this,tr("!"),tr("No Stream!"),QMessageBox::Abort);
        return;
    }
//录制时禁止暂停
    if(isRecord()){
        QMessageBox::warning(this,tr("!"),tr("Cannot pause during recording"),QMessageBox::Abort);
        return;
    }
//判断是否暂停
    QString paused=mpvPlayer->getProperty("pause");
	//根据暂停状态判断暂停或播放
    if(paused=="no"){
        ui->pauseButton->setText("Recovery");
        mpvPlayer->setProperty("pause","yes");
    }
    else if(paused=="yes"){
        ui->pauseButton->setText("Pause");
        mpvPlayer->setProperty("pause","no");
    }
}

void MainWindow::on_recordButton_clicked(){
	//读流时才能录制
    if(!isPlay()){
        QMessageBox::warning(this,tr("!"),tr("No stream"),QMessageBox::Abort);
        return;
    }
	//暂停时不能录制
    QString paused=mpvPlayer->getProperty("pause");
    if(paused=="yes"){
        QMessageBox::warning(this,tr("!"),tr("Cannot record while pausing"),QMessageBox::Abort);
        return;
    }
    if(!isRecord()){
		//录制开始
        m_isRecord=true;
        ui->recordButton->setText("Recording");
        mpvPlayer->setProperty("stream-record","./output.mp4");
    }else{
		//录制停止
        m_isRecord=false;
        ui->recordButton->setText("Record");
        mpvPlayer->setProperty("stream-record"," ");
    }
}

//接收播放结束信号槽函数
void MainWindow::paltEnd_slot(){
    m_isPlay=false;
    ui->playButton->setText("Play");
}
