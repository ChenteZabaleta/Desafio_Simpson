#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))

{
    ui->setupUi(this);


    // Configurar la vista de la escena
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setFocus();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}


