#include "pHacha.h"

pHacha::pHacha(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    float dt,
    float masa,
    QPointF velocidad,
    QPointF aceleracion,
    float coefElasticidad
    ) : Proyectil(posicion, geometria, spritePath, visible, destruir, dt, masa, velocidad, aceleracion, coefElasticidad) {}

TipoObjeto pHacha::colisionConPersonaje() {
    return TipoObjeto::pHacha; // Lógica de colisión con un personaje
}

TipoObjeto pHacha::colisionConObstaculo() {
    this->setVelocidad(QPointF(0, 0)); // Detener el proyectil
    return TipoObjeto::pHacha; // Lógica de colisión con un obstáculo
}
