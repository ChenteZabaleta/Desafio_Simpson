#ifndef BATERIA_H
#define BATERIA_H

#include "objetos/objeto.h"

class Bateria : public Objeto {
public:
    Bateria(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/consumibles/src/img/consumibles/baterias.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016
        );

    TipoObjeto colisionConBart() override; // Sobrescribe el comportamiento
};

#endif // BATERIA_H
