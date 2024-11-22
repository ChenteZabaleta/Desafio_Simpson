#include "pCanica.h"

pCanica::pCanica(
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

TipoObjeto pCanica::colisionConPersonaje() {
    return TipoObjeto::Canica; // Lógica de colisión con un personaje (puede ser extendida)
}

TipoObjeto pCanica::colisionConObstaculo() {
    this->setVelocidad(QPointF(0, 0)); // Detener el proyectil
    return TipoObjeto::Canica; // Lógica de colisión con un obstáculo
}
