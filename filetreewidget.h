#ifndef FILETREEWIDGET_H
#define FILETREEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTreeView>
#include <QListWidget>


#include <QFileSystemModel>
#include <QFileIconProvider>

#include "filefinder.h"


class FileTreeWidget : public QWidget
{
    Q_OBJECT

    QVBoxLayout* vBoxLayoutMain;
    QLineEdit* lineEditCurrentPath;
    QLineEdit* lineEditSearchFile;
    QTreeView* fileTreeView;
    QListWidget* foundFilesListWidget;

    QFileSystemModel fileSystemModel;
    QFileIconProvider fileIconProvider;

    FileFinder* fileFinder;

public:
    explicit FileTreeWidget(QWidget *parent = nullptr);

public slots:
    void onFileTreeItemClicked(const QModelIndex &index);
    void onSearchFileEntered();
    void onSearchFinished(const QStringList& files);
};

#endif // FILETREEWIDGET_H
