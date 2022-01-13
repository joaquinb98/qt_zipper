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

#include "qt_zipper/QtZipper.h"
#include <iostream>
#include "qt_zipper/JlCompress.h"



namespace qt_zipper
{

QtZipper::QtZipper(QObject *parent) : QObject(parent)
{
    
}

QtZipper::~QtZipper()
{
}


void QtZipper::selectFolderToZip(const QString &pcd_path)
{
    if(compressFolder(pcd_path, "/home/jborrego/Documents/titles/prueba.zip"))
    {
        std::cout << "Compression correcta \n";
    }
    else
        std::cout << "Compression fallida \n";

    // decompressFolder("/home/jborrego/Documents/titles/prueba.zip", "/home/jborrego/Documents/titles/");


}


bool QtZipper::compressFolder(const QString& sourceFolder, const QString& destinationFile)
{
    if(JlCompress::compressDir(destinationFile, sourceFolder))
    {
        std::cout << "correctly created " << destinationFile.toStdString() << std::endl;
        return true;
    }
    else
    {
        std::cout << "Could not create: " << destinationFile.toStdString() << std::endl; 
        return false;
    }
}
 
bool QtZipper::compress(QString sourceFolder, QString prefex)
{

}
 
bool QtZipper::decompressFolder(QString sourceFile, QString )
{

}

} // namespace gcs
