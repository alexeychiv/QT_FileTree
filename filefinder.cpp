#include "filefinder.h"

FileFinder::FileFinder(const QString &fileName, const QString &path, QObject *parent)
    :
        QThread(parent),
        fileName(fileName),
        path(QDir::cleanPath(path))
{
}

void FileFinder::run()
{
    if (fileName.isEmpty() || path.isEmpty())
    {
        emit searchComplete(QStringList());
        return;
    }


    QStringList filter;
    filter << fileName;

    QDirIterator it(
        path,
        filter,
        QDir::AllEntries | QDir::NoSymLinks | QDir::NoDotAndDotDot,
        QDirIterator::Subdirectories
    );

    QStringList files;

    while (it.hasNext())
        files << it.next();

    emit searchComplete(files);
}


