#include "game.h"
#include <QPainter>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

const int STEP = 10;

Game::Game(const QString &url, QWidget *parent) : QWidget(parent), url(url) {
    setFixedSize(600, 600);
    nam = new QNetworkAccessManager(this);
    connect(nam, &QNetworkAccessManager::finished, this, &Game::onReply);
    poll(); // kick off the first request
}

void Game::poll() {
    nam->get(QNetworkRequest(QUrl(url)));
}

void Game::onReply(QNetworkReply *r) {
    if (r->error() == QNetworkReply::NoError) {
        int code = r->readAll().trimmed().toInt();
        if (code == 1 || code == 2 || code == 8) y -= STEP;
        if (code == 4 || code == 5 || code == 6) y += STEP;
        if (code == 7)                           x -= STEP;
        if (code == 3)                           x += STEP;
        x = qBound(0, x, 580);
        y = qBound(0, y, 580);
        update();
    }
    r->deleteLater();
    poll(); // immediately request the next one
}

void Game::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.fillRect(rect(), Qt::black);
    p.setBrush(Qt::green);
    p.setPen(Qt::NoPen);
    p.drawEllipse(x, y, 20, 20);
}
