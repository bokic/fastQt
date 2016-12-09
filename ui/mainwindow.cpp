#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    mTabWidget = new QTabWidget;
    setCentralWidget(mTabWidget);

    setMenuBar(new QMenuBar());

    menuBar()->addMenu("File")->addAction("Open file");

    addFile("/home/sacha/test.fastq");

    addToolBar("test")->addAction("run", this, SLOT(run()));

    resize(600,400);

}

MainWindow::~MainWindow()
{

}

void MainWindow::addFile(const QString &filename)
{

    MainAnalyseWidget * w = new MainAnalyseWidget(filename);
    mainList.append(w);
    mTabWidget->addTab(w, w->windowIcon(), w->windowTitle());

}

void MainWindow::run()
{

    mainList.first()->launch();

}


