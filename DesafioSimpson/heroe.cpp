#include "heroe.h"
#include <QKeyEvent>

// Constructor
Heroe::Heroe(int id, const QPointF& pos, const QRectF& geom, float masa, const QString& spritePath, bool vis, QGraphicsItem* parent)
    : Personaje(id, pos, geom, masa, spritePath, vis, parent),
    vida(100), energia(100), herramientaActual(0), inventarioAbierto(false) {
}

// Destructor
Heroe::~Heroe() {
}

// Gestión de teclas presionadas
void Heroe::keyPressEvent(QKeyEvent* event) {
    teclas[event->key()] = true;

    if (event->key() == Qt::Key_Left) {
        setVelocidadX(-getVelocidadMax());
    }
    else if (event->key() == Qt::Key_Right) {
        setVelocidadX(getVelocidadMax());
    }
    else if (event->key() == Qt::Key_Space) {
        saltar();
    }
    else if (event->key() == Qt::Key_A) {
        cambiarHerramienta();
    }
    else if (event->key() == Qt::Key_S) {
        usarHerramienta();
    }
    else if (event->key() == Qt::Key_I) {
        abrirCerrarInventario();
    }
}

// Gestión de teclas liberadas
void Heroe::keyReleaseEvent(QKeyEvent* event) {
    teclas[event->key()] = false;

    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_Right) {
        detenerMovimiento();
    }
}

// Cambiar de herramienta
void Heroe::cambiarHerramienta() {
    herramientaActual++;
    if (herramientaActual > 3) {  // Supongamos que hay 4 herramientas
        herramientaActual = 0;
    }
}

// Usar la herramienta actual
void Heroe::usarHerramienta() {
    // Implementación de lo que hace cada herramienta, dependiendo del valor de herramientaActual
    switch (herramientaActual) {
    case 0:
        // Herramienta 0: Por ejemplo, un pico
        break;
    case 1:
        // Herramienta 1: Por ejemplo, una pala
        break;
    case 2:
        // Herramienta 2: Por ejemplo, una espada
        break;
    case 3:
        // Herramienta 3: Por ejemplo, un martillo
        break;
    }
}

// Abrir o cerrar el inventario
void Heroe::abrirCerrarInventario() {
    inventarioAbierto = !inventarioAbierto;
    // Aquí puedes mostrar/ocultar el inventario en la UI
}

// Actualizar el estado del héroe (vida, energía, etc.)
void Heroe::actualizarEstadoHeroe() {
    // Por ejemplo, reducir la energía al moverse o saltar
    if (estaEnMovimiento() || estaSaltando()) {
        setEnergia(getEnergia() - 1);
    }
}

// Getters y setters para vida y energía
int Heroe::getVida() const {
    return vida;
}

void Heroe::setVida(int nuevaVida) {
    vida = nuevaVida;
}

int Heroe::getEnergia() const {
    return energia;
}

void Heroe::setEnergia(int nuevaEnergia) {
    energia = nuevaEnergia;
}
