#ifndef PVENDA_H
#define PVENDA_H

#include "proyectil.h"

class pVenda : public Proyectil {
public:
    pVenda(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 5, 5),
        QString spritePath = ":/resources/images/venda.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016,
        float masa = 0.2,
        QPointF velocidad = QPointF(0, 0),
        QPointF aceleracion = QPointF(0, 0),
        float coefElasticidad = 0.8
        );

    TipoObjeto colisionConPersonaje() override;
    TipoObjeto colisionConObstaculo() override;
};

#endif // PVENDA_H
