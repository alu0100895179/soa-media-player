#ifndef REPMAINWINDOW_H
#define REPMAINWINDOW_H

#include <QMainWindow>

#include <QtMultimedia>
#include <QtMultimediaWidgets>

#include <QMediaPlayer>

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

private:
    Ui::RepMainWindow *ui;
};

#endif // REPMAINWINDOW_H
