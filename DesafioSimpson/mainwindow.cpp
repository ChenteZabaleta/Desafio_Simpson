#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
    , heroe(nullptr)
{
    ui->setupUi(this);

    // Configurar la escena
    crearEscena();

    //Crear temporizador
    timer = new QTimer(this);

    // Crear el héroe y agregarlo a la escena
    heroe = new Heroe(1, QPointF(100, 100), 70.0, "://hit_barto.png");
    heroe->setGeometria(heroe->boundingRect());
    scene->addItem(heroe);

    // Configurar la vista de la escena
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setFocus();

    connect(timer, &QTimer::timeout, [this](){
        if (heroe) {
            heroe->actualizarEstadoHeroe( );
        }
    });

    timer->start(16);
}

void MainWindow::crearEscena()
{
    // Establece las dimensiones de la escena
    scene->setSceneRect(0, 0, 600, 450); // Por ejemplo, una escena de 800x600

    // Puedes agregar elementos iniciales a la escena aquí
    // Ejemplo: Agregar un fondo
    QGraphicsRectItem* fondo = new QGraphicsRectItem(scene->sceneRect());
    fondo->setBrush(Qt::lightGray); // Cambia el color de fondo
    scene->addItem(fondo);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete timer;
    delete heroe;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (heroe) {
        heroe->keyPressEvent(event);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (heroe) {
        heroe->keyReleaseEvent(event);
    }
}
