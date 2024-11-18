#include "heroe.h"
#include "qgraphicsscene.h"
#include <QKeyEvent>
#include <iostream>

// Constructor
Heroe::Heroe(int id,
             const QPointF& pos,
             const QRectF& geom,
             float masa,
             const QString& spritePath,
             bool vis,
             QGraphicsItem* parent)
    : Personaje(id, pos, geom, masa, spritePath, vis, parent),
    vida(100), energia(100), herramientaActual(0), inventarioAbierto(false) {

    QPixmap pixmap(spritePath);
    if (!pixmap.isNull()) {
        setPixmap(pixmap);  // Establecer el sprite principal
    } else {
        qDebug() << "No se pudo cargar la imagen del héroe: " << spritePath;
    }
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
    std::cout <<"pres";
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
    if (herramientaActual > 2) {  // Cambiando entre las 3 herramientas
        herramientaActual = 0;
    }
}

// Usar la herramienta actual
void Heroe::usarHerramienta() {
    // Implementación de lo que hace cada herramienta, dependiendo del valor de herramientaActual
    switch (herramientaActual) {
    case 0:
        // Herramienta 0:
        break;
    case 1:
        // Herramienta 1:
        break;
    case 2:
        // Herramienta 2:
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
    // Actualización de velocidad en X
       // Aplicar gravedad en el eje Y si el héroe no está en el suelo
    if (!getEnSuelo()) {
        setVelocidadY(getVelocidadY() + 9.8f * 0.016f);  // Aplicar gravedad
    } else {
        if (getVelocidadY() > 0) {
            setVelocidadY(0);  // Detener la velocidad en Y si tocó el suelo
        }
    }

    // Actualizar la posición basándonos en la velocidad
    QPointF nuevaPosicion = pos() + QPointF(getVelocidadX(), getVelocidadY());
    setPos(nuevaPosicion);  // Establecer la nueva posición del héroe

    // Actualización de la vida y energía (ejemplo)



    // Actualizar estado de colisión
    colisionConSuelo();  // Verificar colisión con el suelo, por ejemplo
}

void Heroe::colisionCon(Item* otroItem)
{
    // Verifica el tipo de objeto con el que colisiona
    if (otroItem) {
        qDebug() << "El héroe ha colisionado con un ítem de ID:" << otroItem->getID();

        // Aquí puedes agregar lógica específica, por ejemplo:
        // - Si el ítem es un enemigo, reducir la vida
        // - Si es un objeto recolectable, recogerlo
    }
}

void Heroe::colisionConSuelo()
{
    // Obtener la posición del héroe y la altura de su rectángulo de colisión
    QRectF rect = boundingRect();  // Usar boundingRect() para obtener el rectángulo de colisión
    QPointF posicionHéroe = pos();

    // Verifica si el personaje está tocando el "suelo"
    // Este es un ejemplo simple, puede que necesites ajustarlo según la física de tu juego.
    if (posicionHéroe.y() + rect.height() >= scene()->sceneRect().bottom()) {
        setEnSuelo(true);  // El héroe está tocando el suelo

    } else {
        setEnSuelo(false);  // El héroe no está en el suelo
    }
    actualizarEstado();
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
