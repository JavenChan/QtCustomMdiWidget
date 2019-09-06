#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_MdiArea = new JVMdiArea(ui->centralWidget);
    ui->verticalLayout->addWidget(m_MdiArea);
    m_MdiArea->setMouseTracking(true);

    for(int i=0; i<4; i++)
    {
        m_MdiArea->addChartWindow(new QTextEdit("Doraemon Cat"));
    }
        m_MdiArea->tileSubWindows();

        ui->verticalLayout->setDirection(QBoxLayout::BottomToTop);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addBtn_clicked()
{
    QTextEdit *edit = new QTextEdit("New Nobita");
    m_MdiArea->addChartWindow(edit);
    m_MdiArea->tileSubWindows();

}

void MainWindow::on_cascadeBtn_clicked()
{
    m_MdiArea->cascadeSubWindows();
}

void MainWindow::on_tileBtn_clicked()
{
    m_MdiArea->tileSubWindows();
}

void MainWindow::on_delBtn_clicked()
{
    QMdiSubWindow *widget = m_MdiArea->currentSubWindow();
    if(widget != nullptr)
        m_MdiArea->removeSubWindow((QWidget *)widget);
}
