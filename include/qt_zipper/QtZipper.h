//---------------------------------------------------------------------------------------------------------------------
//  POINTCLOUD RVIZ RELOAD APP
//---------------------------------------------------------------------------------------------------------------------
//  Copyright 2021 Marco A. Montes Grova (a.k.a. mgrova) marrcogrova@gmail.com
//---------------------------------------------------------------------------------------------------------------------
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
//  and associated documentation files (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge, publish, distribute,
//  sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies or substantial
//  portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
//  OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//---------------------------------------------------------------------------------------------------------------------

#ifndef QtZipper_H_
#define QtZipper_H_

#include <QObject>
#include <QColor>
#include <QVBoxLayout>
#include <QDebug>
#include <QVector3D>

#include <QFile>
#include <QObject>
#include <QDir>
#include <QDataStream>

#include <quazip5/zip.h>

namespace qt_zipper
{
class QtZipper : public QObject
{
Q_OBJECT
public:
	QtZipper(QObject *parent = nullptr);
	~QtZipper();

    bool compressFolder(const QString&, const QString& );
 
    //A function that deserializes data from the compressed file and
    //creates any needed subfolders before saving the file
    bool decompressFolder(QString sourceFile, QString destinationFolder);

public Q_SLOTS: 
	void selectFolderToZip(const QString &);


private:
 
    bool compress(QString sourceFolder, QString prefex);

    tm_zip aaaaa;
};
	
}

#endif
