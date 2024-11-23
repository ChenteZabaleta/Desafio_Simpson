#ifndef DONA_H
#define DONA_H

#include "objetos/objeto.h"

class Dona : public Objeto {
public:
    Dona(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/consumibles/src/img/consumibles/donas.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016
        );

    TipoObjeto colisionConBart() override; // Sobrescribe el comportamiento
};

#endif // DONA_H
