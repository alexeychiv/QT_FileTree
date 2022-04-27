#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "filetreewidget.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

    FileTreeWidget* fileTreeWidget;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


};
#endif // MAINWINDOW_H
