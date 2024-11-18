#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include "heroe.h" // Incluye la clase Heroe

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override; // Detectar teclas presionadas
    void keyReleaseEvent(QKeyEvent *event) override; // Detectar teclas liberadas

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QTimer* timer;

    Heroe* heroe; // Referencia al héroe

    void agregarObjeto(QPoint pos, const QString &rutaImagen);
    void crearEscena();
};
#endif // MAINWINDOW_H
