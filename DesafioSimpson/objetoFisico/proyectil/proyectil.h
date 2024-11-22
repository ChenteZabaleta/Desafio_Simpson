#ifndef PROYECTIL_H
#define PROYECTIL_H



#include "objetoFisico/objetofisico.h"

class Proyectil : public ObjetoFisico {
public:
    Proyectil(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 5, 5),
        QString spritePath = "",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016,
        float masa = 1.0,
        QPointF velocidad = QPointF(0, 0),
        QPointF aceleracion = QPointF(0, 0),
        float coefElasticidad = 0.5
        );

    // Métodos para manejar las colisiones
    virtual TipoObjeto colisionConPersonaje() = 0;
    virtual TipoObjeto colisionConObstaculo() = 0;

    void actualizar(float deltaTime) override;
};

#endif // PROYECTIL_H
