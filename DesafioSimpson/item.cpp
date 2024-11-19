#include "item.h"
#include <QPixmap>

// Constructor
Item::Item(int id,
           const QPointF& pos,
           float masa,
           const QString& spritePath,
           bool vis,
           QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent),
    ID(id),
    posicion(pos),
    masa(masa),
    rutaSprite(spritePath),
    visible(vis),
    destruir(false),
    estadoColision(EstadoColision::SinColision) {



    QPixmap pixmap(spritePath);
    if (!pixmap.isNull()) {
        setPixmap(pixmap);  // Establecer el sprite principal
        sprite = pixmap;
        geometria = pixmap.rect();
    } else {
        qDebug() << "No se pudo cargar la imagen del héroe: " << spritePath;
    }


}

// Destructor virtual
Item::~Item() = default;

// Métodos getters
int Item::getID() const {return ID;}
QPointF Item::getPosicion() const {return posicion;}
QRectF Item::getGeometria() const {return geometria;}
float Item::getMasa() const {return masa;}
QString Item::getSprite() const {return rutaSprite;}
bool Item::isVisible() const {return visible;}
bool Item::isDestruir() const {return destruir;}
EstadoColision Item::getEstadoColision() const {return estadoColision;}


// Métodos setters
void Item::setID(int id) {ID = id;}
void Item::setPosicion(const QPointF& pos) {posicion = pos;}
void Item::setGeometria(const QRectF& geom) {geometria = geom;}
void Item::setMasa(float m) {masa = m;}
void Item::setSprite(const QString& spritePath) {rutaSprite = spritePath;}
void Item::setVisible(bool vis) {visible = vis;}
void Item::setDestruir(bool destr) {destruir = destr;}
void Item::setEstadoColision(EstadoColision estado) {estadoColision = estado;}



//Métodos funcionales
QRectF Item::boundingRect() const {return sprite.rect();}


