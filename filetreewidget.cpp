#include "filetreewidget.h"

FileTreeWidget::FileTreeWidget(QWidget *parent) : QWidget(parent)
{
    vBoxLayoutMain = new QVBoxLayout(this);

    lineEditCurrentPath = new QLineEdit(this);
    fileTreeView = new QTreeView(this);

    vBoxLayoutMain->addWidget(lineEditCurrentPath);
    vBoxLayoutMain->addWidget(fileTreeView);


    fileSystemModel.setRootPath(QDir::rootPath());
    fileSystemModel.setIconProvider(&fileIconProvider);

    fileTreeView->setModel(&fileSystemModel);
    fileTreeView->hideColumn(1);
    fileTreeView->hideColumn(2);
    fileTreeView->hideColumn(3);

    connect(fileTreeView, &QTreeView::clicked, this, &FileTreeWidget::onFileTreeItemClicked);
}

void FileTreeWidget::onFileTreeItemClicked(const QModelIndex &index)
{
    QFileInfo fileInfo = fileSystemModel.fileInfo(index);
    lineEditCurrentPath->setText(fileInfo.absoluteFilePath());
}
