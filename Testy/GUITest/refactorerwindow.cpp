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
    QString sel = "Inter: ";
    sel += QString::number( startPos());
    sel += " - ";
    sel += QString::number( endPos() );
    sel += " Impl: ";
    sel += QString::number( ui->implementationText->textCursor().selectionStart());
    sel += " - ";
    sel += QString::number( ui->implementationText->textCursor().selectionEnd() );
     statusBar()->showMessage(sel);
}

void RefactorerWindow::on_actionMethodRefactor_triggered()
{
    MethodRefactorer refactorer;

    try{
        std::string inter = ui->interfaceText->toPlainText().toStdString();
        std::string impl = ui->implementationText->toPlainText().toStdString();
        if(!refactorer(inter, impl, startPos(), endPos()))
            statusBar()->showMessage
                    ("Nie przeprowadzono refaktoryzacji błędne zaznaczenie lub refaktoryzacja nie potrzebna");
        else {
            if (ui->interfaceText->toPlainText().toStdString() != inter)
                ui->interfaceText->setPlainText(QString(inter.c_str()));
            ui->implementationText->setPlainText(QString(impl.c_str()));
        }
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
