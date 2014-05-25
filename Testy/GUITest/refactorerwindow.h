#ifndef REFACTORERWINDOW_H
#define REFACTORERWINDOW_H

#include <QMainWindow>

namespace Ui {
class RefactorerWindow;
}

class RefactorerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RefactorerWindow(QWidget *parent = 0);
    ~RefactorerWindow();

    void setSelectionInfo();
private slots:
    void on_actionMethodRefactor_triggered();

    void on_actionShowSelection_triggered();

private:
    Ui::RefactorerWindow *ui;

    unsigned startPos();
    unsigned endPos();
};

#endif // REFACTORERWINDOW_H
