#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800, 600);
    setWindowTitle("File Tree");

    fileTreeWidget = new FileTreeWidget(this);
    setCentralWidget(fileTreeWidget);
}

MainWindow::~MainWindow()
{

}

