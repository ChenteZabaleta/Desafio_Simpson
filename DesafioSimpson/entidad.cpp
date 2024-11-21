#include "entidad.h"

Entidad::Entidad(
    TipoObjeto tipo,
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    bool solido,
    float dt
    ) : tipo(tipo),
    posicion(posicion),
    geometria(geometria),
    rutaSprite(spritePath),
    sprite(QPixmap(spritePath)),
    visible(visible),
    destruir(destruir),
    solido(solido),
    dt(dt) {}

// Getters
TipoObjeto Entidad::getTipo() const { return tipo; }
QPointF Entidad::getPosicion() const { return posicion; }
QRectF Entidad::getGeometria() const { return geometria; }
QString Entidad::getRutaSprite() const { return rutaSprite; }
QPixmap Entidad::getSprite() const { return sprite; }
bool Entidad::isVisible() const { return visible; }
bool Entidad::isDestruir() const { return destruir; }
bool Entidad::getSolido() const { return solido; }
float Entidad::getDeltaTime() const { return dt; }

// Setters
void Entidad::setTipo(TipoObjeto tipo) { this->tipo = tipo; }
void Entidad::setPosicion(const QPointF &pos) { this->posicion = pos; }
void Entidad::setGeometria(const QRectF &geo) { this->geometria = geo; }
void Entidad::setRutaSprite(const QString &ruta) { this->rutaSprite = ruta; this->sprite = QPixmap(ruta); }
void Entidad::setSprite(const QPixmap &spr) { this->sprite = spr; }
void Entidad::setVisible(bool vis) { this->visible = vis; }
void Entidad::setDestruir(bool des) { this->destruir = des; }
void Entidad::setSolido(bool nuevoSolido) { solido = nuevoSolido; }
void Entidad::setDeltaTime(float delta) { this->dt = delta; }

QRectF Entidad::boundingRect() const { return sprite.rect(); }

void Entidad::actualizar(float deltaTime) {
    dt = deltaTime;
    if (!visible) { destruir = true;}
}

void Entidad::cambiarSprite(QString nuevoSpritePath)
{

}


