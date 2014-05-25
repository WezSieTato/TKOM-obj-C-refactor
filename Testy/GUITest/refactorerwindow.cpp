#include "refactorerwindow.h"
#include "ui_refactorerwindow.h"

#include <methodrefactorer.h>

RefactorerWindow::RefactorerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RefactorerWindow)
{
    ui->setupUi(this);
}

RefactorerWindow::~RefactorerWindow()
{
    delete ui;
}

void RefactorerWindow::setSelectionInfo()
{
    QString sel = "Selection ";
    sel += QString::number( startPos());
    sel += " - ";
    sel += QString::number( endPos() );
     statusBar()->showMessage(sel);
}

void RefactorerWindow::on_actionMethodRefactor_triggered()
{
    MethodRefactorer refactorer;

    try{
        std::string inter = ui->interfaceText->toPlainText().toStdString();
        std::string impl = ui->interfaceText->toPlainText().toStdString();
        if(!refactorer(inter, impl, startPos(), endPos()))
            statusBar()->showMessage("Nie przeprowadzono refaktoryzacji błędne zaznaczenie lub refaktoryzacja nie potrzebna");
    } catch (std::exception &e){
        statusBar()->showMessage(QString(e.what()));
    }
}

unsigned RefactorerWindow::startPos()
{
    return ui->interfaceText->textCursor().selectionStart();
}

unsigned RefactorerWindow::endPos()
{
    return ui->interfaceText->textCursor().selectionEnd();
}

void RefactorerWindow::on_actionShowSelection_triggered()
{
    setSelectionInfo();
}
