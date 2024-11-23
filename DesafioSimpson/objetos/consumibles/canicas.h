#ifndef CANICA_H
#define CANICA_H

#include "objetos/objeto.h"

class Canica : public Objeto {
public:
    Canica(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/consumibles/src/img/consumibles/canicas.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016
        );

    TipoObjeto colisionConBart() override; // Sobrescribe el comportamiento
};

#endif // CANICA_H
