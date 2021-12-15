#include "weblogic.h"
#include <QMessageBox>
#include <mainwindow.h>
#include <string>
#include <QObject>
#include <QString>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>

WebLogic::WebLogic(QWidget *parentWindow)
{
    this->window = parentWindow;
    this->initRequests();
}

WebLogic::~WebLogic()
{
}

void WebLogic::initRequests()
{
    this->zlpRequest = QNetworkRequest(QUrl("https://httpbin.org/get"));
    this->zlpRequest.setRawHeader("User-Agent", "Mozilla/5.0");
    this->webModelRequst = QNetworkRequest(QUrl("http://0.0.0.0:8080/api/webModel"));
}


void WebLogic::GetZLP()
{
    // call web api
    this->zlpReply = this->manager.get(zlpRequest);

    QObject::connect(this->zlpReply, &QNetworkReply::finished, [&]()
    {
        QByteArray data = this->zlpReply->readAll();
        this->zlpHandleResponse(data);

    });
}

void WebLogic::zlpHandleResponse(QByteArray jsonResponse)
{
    QMessageBox::about(this->window, "Ответ", QString::fromUtf8(jsonResponse));

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonResponse);
}
