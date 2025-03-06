#include "notepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("Esis S.r.l.");
    QCoreApplication::setOrganizationDomain("esis-italia.com");
    QCoreApplication::setApplicationName("Notepad");

    app.setWindowIcon(QIcon(":/icons/notepad.ico"));

    Notepad notepad;
    notepad.show();

    return app.exec();
}
