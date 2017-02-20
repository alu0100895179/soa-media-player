#include "repmainwindow.h"
#include "ui_repmainwindow.h"

RepMainWindow::RepMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RepMainWindow),
    rep(false),
    pau(false),
    web(false),
    player(NULL),
    playlist(NULL),
    camera(NULL)
{
    ui->setupUi(this);
}

RepMainWindow::~RepMainWindow()
{
    delete camera;
    delete player;
    delete playlist;

    delete ui;
}

void RepMainWindow::on_pushButton_clicked()
{

    if (!rep){

        web=false;
        delete camera;

        ui->pushButton->setText("||");
        rep=true;

        if(pau){

            player->play();
            player->setPlaybackRate(1);

            pau=false;
        }
        else{

            player = new QMediaPlayer;
            QString filename = QFileDialog::getOpenFileName(this, "Open a File","","Video File (*.avi);(*.mp4)");

            player->setMedia(QUrl::fromLocalFile(filename));
            player->setVideoOutput(ui->widget);
            player->play();
            player->setPlaybackRate(1);

            pau=false;

        }
    }

    else{
        rep=false;

        ui->pushButton->setText("▶");

        player->pause();
        pau=true;

    }
}

void RepMainWindow::on_pushButton_3_clicked()
{
    if(rep){
        ui->pushButton->setText("▶");
        rep=false;
        player->stop();
    }
    else{
        delete camera;
        web=false;
    }
}

void RepMainWindow::on_pushButton_4_clicked()
{
    if(rep){
        if(player->playbackRate()>1)
            player->setPlaybackRate(1);
        else
            if(player->playbackRate()==1)
                player->setPlaybackRate(-0.2);
            else
                if(player->playbackRate()==-0.2)
                    player->setPlaybackRate(-0.5);
                else
                    player->setPlaybackRate(-1.0);
    }
}

void RepMainWindow::on_pushButton_5_clicked()
{
    if(rep){
        if(player->playbackRate()<0)
            player->setPlaybackRate(1);
        else
            if(player->playbackRate()==1)
                player->setPlaybackRate(1.4);
            else
                if(player->playbackRate()==1.4)
                    player->setPlaybackRate(1.8);
                    else
                        player->setPlaybackRate(2.5);

    }
}

void RepMainWindow::on_pushButton_2_clicked()
{
    if(!web){
        rep=false;
        delete player;
        delete playlist;
        ui->pushButton->setText("▶");

        camera = new QCamera;

        QList<QByteArray> devices = QCamera::availableDevices();
        qDebug() << "Capturando de... "
                 << QCamera::deviceDescription(devices[0]);

        camera->setViewfinder(ui->widget);
        camera->setCaptureMode(QCamera::CaptureViewfinder);
        camera->start();

        web=true;

    }
}
