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

    ui->pushButton_4->setText("«");
    ui->pushButton_5->setText("»");

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
            QString filename = QFileDialog::getOpenFileName(this, "Open a File","","Video File (*.mp4 *.avi)");

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

        ui->pushButton_4->setText("«");
        ui->pushButton_5->setText("»");
    }
    else{
        delete camera;
        web=false;
    }
}

void RepMainWindow::on_pushButton_4_clicked()
{
    if(rep){
        if(player->playbackRate()>1){
            player->setPlaybackRate(1);
            ui->pushButton_4->setText("«");
            ui->pushButton_5->setText("»");
        }
        else
            if(player->playbackRate()==1){
                player->setPlaybackRate(-1);
                ui->pushButton_4->setText("««");
            }
            else
                if(player->playbackRate()==-1){
                    player->setPlaybackRate(-1.5);
                    ui->pushButton_4->setText("«««");
                }
                else
                    if(player->playbackRate()==-1.5){
                        player->setPlaybackRate(-2.0);
                        ui->pushButton_4->setText("««««");

                    }
    }
}

void RepMainWindow::on_pushButton_5_clicked()
{
    if(rep){
        if(player->playbackRate()<0){
            player->setPlaybackRate(1);
            ui->pushButton_4->setText("«");
            ui->pushButton_5->setText("»");
        }
        else
            if(player->playbackRate()==1){
                player->setPlaybackRate(1.4);
                ui->pushButton_5->setText("»»");
            }
            else
                if(player->playbackRate()==1.4){
                    player->setPlaybackRate(1.8);
                    ui->pushButton_5->setText("»»»");
                }
                    else
                        if(player->playbackRate()==1.8){
                            player->setPlaybackRate(2.5);
                            ui->pushButton_5->setText("»»»»");
                        }

    }
}

void RepMainWindow::on_pushButton_2_clicked()
{
    if(!web){
        rep=false;
        delete player;
        delete playlist;
        ui->pushButton->setText("▶");
        ui->pushButton_4->setText("«");
        ui->pushButton_5->setText("»");

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
