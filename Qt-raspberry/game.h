#pragma once
#include <QWidget>
#include <QNetworkAccessManager>

class Game : public QWidget {
    Q_OBJECT
public:
    explicit Game(const QString &url, QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *) override;
private slots:
    void onReply(QNetworkReply *r);
    void poll();
private:
    int x = 300, y = 300;
    QString url;
    QNetworkAccessManager *nam;
};
