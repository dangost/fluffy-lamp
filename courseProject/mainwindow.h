#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <weblogic.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_aboutProgramMenuAction_triggered();

    void on_aboutAuthorMenuAction_triggered();

    void on_exitMenuAction_triggered();

    void on_zlpSolveButton_clicked();

    void on_netModelSolveButton_clicked();

private:
    Ui::MainWindow *ui;
    WebLogic *webManager;
};
#endif // MAINWINDOW_H
