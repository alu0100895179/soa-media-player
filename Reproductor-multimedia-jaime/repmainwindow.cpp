#include "repmainwindow.h"
#include "ui_repmainwindow.h"

RepMainWindow::RepMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RepMainWindow)
{
    ui->setupUi(this);
}

RepMainWindow::~RepMainWindow()
{
    delete ui;
}

void RepMainWindow::on_pushButton_clicked()
{
    QMediaPlaylist* playlist;

    playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl("http://clips.vorwaerts-gmbh.de/VfE.webm"));
    playlist->setCurrentIndex(1);

    QMediaPlayer* player;
    player = new QMediaPlayer;
    player->setPlaylist(playlist);

    QVideoWidget* videoWidget;
    videoWidget = new QVideoWidget;
    player->setVideoOutput(ui->widget);
    ui->widget->show();

    player->play();
}
