#include "objetofisico.h"

ObjetoFisico::ObjetoFisico(
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
    ) : Entidad(TipoObjeto::Generico, posicion, geometria, spritePath, visible, destruir, dt),
    masa(masa),
    velocidad(velocidad),
    aceleracion(aceleracion),
    coefElasticidad(coefElasticidad) {}

// Getters
float ObjetoFisico::getMasa() const { return masa; }
QPointF ObjetoFisico::getVelocidad() const { return velocidad; }
QPointF ObjetoFisico::getAceleracion() const { return aceleracion; }
QPointF ObjetoFisico::getMomentum() const { return QPointF(masa * velocidad.x(), masa * velocidad.y()); }
float ObjetoFisico::getCoefElasticidad() const { return coefElasticidad; }

// Setters
void ObjetoFisico::setMasa(float masa) { this->masa = masa; }
void ObjetoFisico::setVelocidad(const QPointF &velocidad) { this->velocidad = velocidad; }
void ObjetoFisico::setAceleracion(const QPointF &aceleracion) { this->aceleracion = aceleracion; }
void ObjetoFisico::setCoefElasticidad(float coef) { coefElasticidad = (coef < 0) ? 0 : (coef > 1 ? 1 : coef); }

// Actualización física
void ObjetoFisico::actualizar(float deltaTime) {
    // Actualiza la velocidad en función de la aceleración
    velocidad += aceleracion * deltaTime;

    // Actualiza la posición en función de la velocidad
    setPosicion(getPosicion() + velocidad * deltaTime);

    Entidad::actualizar(deltaTime); // Llama al método de la clase base si es necesario
}
