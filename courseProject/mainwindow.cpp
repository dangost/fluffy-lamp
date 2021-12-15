#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <weblogic.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap zlpPicture("C:/Users/danil/Desktop/courseMIAPR/courseProject/images/zlp.png");
    QPixmap netModelPicture("C:/Users/danil/Desktop/courseMIAPR/courseProject/images/netModel.png");

    this->ui->zlpPicLabel->setPixmap(zlpPicture.scaled(
                                         ui->zlpPicLabel->width(),
                                         ui->zlpPicLabel->height(),
                                         Qt::KeepAspectRatio)
                                     );
    this->ui->netModelPicLabel->setPixmap(netModelPicture.scaled(
                                              ui->netModelPicLabel->width(),
                                              ui->netModelPicLabel->height(),
                                              Qt::KeepAspectRatio)
                                          );
    this->webManager = new WebLogic(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_aboutProgramMenuAction_triggered()
{
    QMessageBox::about(this, "О Программе", "Курсовая работа. Решает какую-то хуйню\t");
}


void MainWindow::on_aboutAuthorMenuAction_triggered()
{
    QMessageBox::about(this, "Об авторе", "Хороший автор. В разгоне. Не после майнинга. Энергоэффективный. Заблокирован автоматический сон");
}


void MainWindow::on_exitMenuAction_triggered()
{
    exit(0);
}


void MainWindow::on_zlpSolveButton_clicked()
{
    this->webManager->GetZLP();  // call web api and print result on QMessageBox
}


void MainWindow::on_netModelSolveButton_clicked()
{
    QMessageBox::about(this, "Решение Сетевой модели", "Ещё раз говорю, никто блять не знает решения. Вы там темы задачи в киосках покупаете?");
}

