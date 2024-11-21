#ifndef TIRACHINAS_H
#define TIRACHINAS_H

#include "objetos/objeto.h"

class Tirachinas : public Objeto {
public:
    Tirachinas(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/herramientas/src/img/herramientas/tirachinas.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016
        );

    TipoObjeto colisionConBart() override; // Sobrescribe el comportamiento
};

#endif // TIRACHINAS_H
