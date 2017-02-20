#ifndef REPMAINWINDOW_H
#define REPMAINWINDOW_H

#include <QMainWindow>

#include <QtMultimedia>
#include <QtMultimediaWidgets>

#include <QMediaPlayer>

#include <QString>
#include <QFileDialog>
#include <QUrl>
#include <QList>

#include <cstdio>

namespace Ui {
class RepMainWindow;
}

class RepMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RepMainWindow(QWidget *parent = 0);
    ~RepMainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RepMainWindow *ui;
    bool rep;
    bool web;
    bool pau;
    QMediaPlayer* player;
    QMediaPlaylist* playlist;
    QCamera* camera;
};

#endif // REPMAINWINDOW_H
