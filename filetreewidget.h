#ifndef FILETREEWIDGET_H
#define FILETREEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTreeView>

#include <QFileSystemModel>
#include <QFileIconProvider>

class FileTreeWidget : public QWidget
{
    Q_OBJECT

    QVBoxLayout* vBoxLayoutMain;
    QLineEdit* lineEditCurrentPath;
    QTreeView* fileTreeView;

    QFileSystemModel fileSystemModel;
    QFileIconProvider fileIconProvider;

public:
    explicit FileTreeWidget(QWidget *parent = nullptr);

public slots:
    void onFileTreeItemClicked(const QModelIndex &index);

};

#endif // FILETREEWIDGET_H
