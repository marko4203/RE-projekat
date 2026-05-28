#include <QApplication>
#include "dialog.h"
#include "game.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    Dialog d;
    if (d.exec() == QDialog::Accepted) {
        Game g(d.getUrl());
        g.show();
        return app.exec();
    }
    return 0;
}
