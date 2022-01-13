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

#include "qt_zipper/MainWindowUi.h"
#include "qt_zipper/QtZipper.h"

#include <QStatusBar>
#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>

namespace qt_zipper
{
MainWindowUi::MainWindowUi() : _qtZipper(std::make_unique<QtZipper>())
{
    createMenu();
    statusBar()->showMessage(tr("Ready"));

    connect(this,            &MainWindowUi::selectFolderToZip,
            _qtZipper.get(), &QtZipper::selectFolderToZip);
}

MainWindowUi::~MainWindowUi()
{
  
}

void MainWindowUi::createMenu()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&Menu"));
    
    QAction *selectionAct = new QAction(tr("&Select Folder to Zip"), this);
    selectionAct->setStatusTip(tr("Select Folder to Zip"));
    connect(selectionAct, &QAction::triggered, [=]() 
        { 
            auto folderPath = QFileDialog::getExistingDirectory(
                this, tr("Open Folder"), QDir::homePath(),   
                QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
            if(folderPath.isEmpty())
                return;

            Q_EMIT selectFolderToZip(folderPath);
            statusBar()->showMessage(tr("Showing folder: ") + folderPath); 
        });
    
    fileMenu->addAction(selectionAct);
}
}
