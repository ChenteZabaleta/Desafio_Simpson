#ifndef LLAVE_H
#define LLAVE_H


#include "objetos/objeto.h"

class Llave : public Objeto {
public:
    Llave(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/consumibles/src/img/consumibles/llave.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016
        );

    TipoObjeto colisionConBart() override; // Sobrescribe el comportamiento
};

#endif // LLAVE_H
