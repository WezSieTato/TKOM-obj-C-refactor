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
//    setSelectionInfo();
    MethodRefactorer refactorer;

    try{
        std::string inter = ui->interfaceText->toPlainText().toStdString();
        std::string impl = ui->interfaceText->toPlainText().toStdString();
        refactorer(inter, impl, startPos(), endPos());
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
