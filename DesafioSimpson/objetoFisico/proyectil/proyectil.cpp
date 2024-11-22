#include "proyectil.h"

// Constructor
Proyectil::Proyectil(
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
    ) : ObjetoFisico(
          posicion,
          geometria,
          spritePath,
          visible,
          destruir,
          dt,
          masa,
          velocidad,
          aceleracion,
          coefElasticidad) {}

void Proyectil::actualizar(float deltaTime) {
    // Actualización de la física del proyectil
    setVelocidad( getAceleracion() * deltaTime);
    setPosicion(getPosicion() + getVelocidad() * deltaTime);
    ObjetoFisico::actualizar(deltaTime);
}
