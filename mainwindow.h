#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <iostream>
#include <QMouseEvent>
#include <QTextEdit>
#include "mdiwidget/jv_mdiarea.h"
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_addBtn_clicked();

    void on_cascadeBtn_clicked();

    void on_tileBtn_clicked();

    void on_delBtn_clicked();

private:
    Ui::MainWindow *ui;
    vector<QMdiSubWindow *> mdivec;

   JVMdiArea* m_MdiArea = nullptr;


};

#endif
