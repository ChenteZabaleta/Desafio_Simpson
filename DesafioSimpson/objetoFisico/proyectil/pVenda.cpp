#include "pVenda.h"

pVenda::pVenda(
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

TipoObjeto pVenda::colisionConPersonaje() {
    return TipoObjeto::pVenda; // Lógica de colisión con un personaje
}

TipoObjeto pVenda::colisionConObstaculo() {
    this->setVelocidad(QPointF(0, 0)); // Detener el proyectil
    return TipoObjeto::pVenda; // Lógica de colisión con un obstáculo
}
