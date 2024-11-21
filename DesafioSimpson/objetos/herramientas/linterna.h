#ifndef LINTERNA_H
#define LINTERNA_H

#include "objetos/objeto.h"

class Linterna : public Objeto {
public:
    Linterna(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/herramientas/src/img/herramientas/linterna.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016
        );

    TipoObjeto colisionConBart() override; // Sobrescribe el comportamiento
};

#endif // LINTERNA_H
