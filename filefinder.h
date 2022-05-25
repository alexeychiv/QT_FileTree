#ifndef FILEFINDER_H
#define FILEFINDER_H

#include <QObject>
#include <QThread>
#include <QDir>
#include <QDirIterator>

class FileFinder : public QThread
{
    Q_OBJECT

    QString fileName;
    QString path;

public:
    explicit FileFinder(
            const QString& fileName,
            const QString& path,
            QObject *parent = nullptr
        );

    void run();

signals:
    void searchComplete(const QStringList& foundFiles);
};

#endif // FILEFINDER_H
