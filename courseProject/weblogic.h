#ifndef WEBLOGIC_H
#define WEBLOGIC_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


class WebLogic
{
public:
    WebLogic(QWidget *parentWindow = nullptr);
    void GetZLP();

private:
    ~WebLogic();
    QWidget *window;
    QNetworkAccessManager manager;
    QNetworkRequest zlpRequest;
    QNetworkRequest webModelRequst;
    void initRequests();
    void zlpHandleResponse(QByteArray jsonResponse);
    QNetworkReply *zlpReply;
    QNetworkReply *webModelReply;

};


#endif // WEBLOGIC_H
