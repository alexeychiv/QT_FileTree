#include "filetreewidget.h"

FileTreeWidget::FileTreeWidget(QWidget *parent) : QWidget(parent), fileFinder(nullptr)
{
    vBoxLayoutMain = new QVBoxLayout(this);

    lineEditCurrentPath = new QLineEdit(this);
    lineEditSearchFile = new QLineEdit(this);
    fileTreeView = new QTreeView(this);
    foundFilesListWidget = new QListWidget(this);


    vBoxLayoutMain->addWidget(lineEditCurrentPath);
    vBoxLayoutMain->addWidget(lineEditSearchFile);
    vBoxLayoutMain->addWidget(fileTreeView);
    vBoxLayoutMain->addWidget(foundFilesListWidget);

    fileSystemModel.setRootPath(QDir::rootPath());
    fileSystemModel.setIconProvider(&fileIconProvider);

    fileTreeView->setModel(&fileSystemModel);
    fileTreeView->hideColumn(1);
    fileTreeView->hideColumn(2);
    fileTreeView->hideColumn(3);

    connect(fileTreeView, &QTreeView::clicked, this, &FileTreeWidget::onFileTreeItemClicked);
    connect(lineEditSearchFile, &QLineEdit::editingFinished, this, &FileTreeWidget::onSearchFileEntered);
}

void FileTreeWidget::onFileTreeItemClicked(const QModelIndex &index)
{
    QFileInfo fileInfo = fileSystemModel.fileInfo(index);
    lineEditCurrentPath->setText(fileInfo.absoluteFilePath());
}

void FileTreeWidget::onSearchFileEntered()
{
    if (fileFinder != nullptr)
        delete fileFinder;

    fileFinder = new FileFinder(
                lineEditSearchFile->text(),
                lineEditCurrentPath->text(),
                this
            );

    connect(fileFinder, &FileFinder::searchComplete, this, &FileTreeWidget::onSearchFinished);
    fileFinder->run();
}

void FileTreeWidget::onSearchFinished(const QStringList& files)
{
    foundFilesListWidget->clear();
    foundFilesListWidget->addItems(files);
}
