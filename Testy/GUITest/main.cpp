#include "refactorerwindow.h"
#include <QApplication>
#include <refactorer.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RefactorerWindow w;
    w.show();

    return a.exec();
}
