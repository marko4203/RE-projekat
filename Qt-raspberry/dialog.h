#pragma once
#include <QDialog>
#include <QLineEdit>

class Dialog : public QDialog {
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
    QString getUrl() const;
private:
    QLineEdit *ipEdit;
};
