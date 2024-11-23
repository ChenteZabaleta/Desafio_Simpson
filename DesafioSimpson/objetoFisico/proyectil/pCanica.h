#ifndef PCANICA_H
#define PCANICA_H

#include "proyectil.h"


class pCanica : public Proyectil {
public:
    pCanica(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 5, 5),
        QString spritePath = ":/resources/images/canica.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016,
        float masa = 0.1,
        QPointF velocidad = QPointF(0, 0),
        QPointF aceleracion = QPointF(0, 0),
        float coefElasticidad = 0.9
        );

    TipoObjeto colisionConPersonaje() override;
    TipoObjeto colisionConObstaculo() override;
};

#endif // PCANICA_H
