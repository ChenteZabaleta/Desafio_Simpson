#include "item.h"
#include <QPixmap>

// Constructor
Item::Item(int id, const QPointF& pos, const QRectF& geom, float masa, const QString& spritePath, bool vis, QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent), ID(id), posicion(pos), geometria(geom), masa(masa), sprite(spritePath),
    visible(vis), destruir(false), estadoColision(EstadoColision::SinColision) {
    setPixmap(QPixmap(spritePath)); // Carga la imagen del sprite
    setPos(pos);                    // Establece la posición en la escena
}

// Destructor virtual
Item::~Item() = default;

// Métodos para acceder a los atributos
int Item::getID() const {
    return ID;
}

QPointF Item::getPosicion() const {
    return posicion;
}

QRectF Item::getGeometria() const {
    return geometria;
}

float Item::getMasa() const {
    return masa;
}

QString Item::getSprite() const {
    return sprite;
}

bool Item::isVisible() const {
    return visible;
}

bool Item::isDestruir() const {
    return destruir;
}

EstadoColision Item::getEstadoColision() const {
    return estadoColision;
}

// Métodos para modificar los atributos
void Item::setID(int id) {
    ID = id;
}

void Item::setPosicion(const QPointF& pos) {
    posicion = pos;
    setPos(pos);
}

void Item::setGeometria(const QRectF& geom) {
    geometria = geom;
}

void Item::setMasa(float m) {
    masa = m;
}

void Item::setSprite(const QString& spritePath) {
    sprite = spritePath;
    setPixmap(QPixmap(spritePath));
}

void Item::setVisible(bool vis) {
    visible = vis;
    setOpacity(vis ? 1.0 : 0.0);
}

void Item::setDestruir(bool destr) {
    destruir = destr;
}

void Item::setEstadoColision(EstadoColision estado) {
    estadoColision = estado;
}

// Método para obtener los límites de colisión
QRectF Item::boundingRect() const {
    return geometria;
}
