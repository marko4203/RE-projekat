#include "dialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

Dialog::Dialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Connect");
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("ESP32 IP address:"));
    ipEdit = new QLineEdit("10.1.147.171", this);
    layout->addWidget(ipEdit);
    QPushButton *btn = new QPushButton("Start", this);
    layout->addWidget(btn);
    connect(btn, &QPushButton::clicked, this, &QDialog::accept);
}

QString Dialog::getUrl() const {
    return "http://" + ipEdit->text() + "/ctrl";
}
