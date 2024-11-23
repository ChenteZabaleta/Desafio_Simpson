#ifndef PHACHA_H
#define PHACHA_H

#include "proyectil.h"

class pHacha : public Proyectil {
public:
    pHacha(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 5, 5),
        QString spritePath = ":/resources/images/hacha.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016,
        float masa = 0.5,
        QPointF velocidad = QPointF(0, 0),
        QPointF aceleracion = QPointF(0, 0),
        float coefElasticidad = 0.7
        );

    TipoObjeto colisionConPersonaje() override;
    TipoObjeto colisionConObstaculo() override;
};

#endif // PHACHA_H
