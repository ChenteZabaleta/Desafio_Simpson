#ifndef OBJETOFISICO_H
#define OBJETOFISICO_H


#include "entidad.h"
#include <QPointF>

class ObjetoFisico : public Entidad {
public:
    ObjetoFisico(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = "",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016,
        float masa = 1.0,
        QPointF velocidad = QPointF(0, 0),
        QPointF aceleracion = QPointF(0, 0),
        float coefElasticidad = 0.5
        );

    // Getters
    float getMasa() const;
    QPointF getVelocidad() const;
    QPointF getAceleracion() const;
    QPointF getMomentum() const; // Calculado dinámicamente
    float getCoefElasticidad() const;

    // Setters
    void setMasa(float masa);
    void setVelocidad(const QPointF &velocidad);
    void setAceleracion(const QPointF &aceleracion);
    void setCoefElasticidad(float coef);

    // Actualización física
    void actualizar(float deltaTime) override;

private:
    float masa;
    QPointF velocidad;
    QPointF aceleracion;
    float coefElasticidad;
};

#endif // OBJETOFISICO_H
