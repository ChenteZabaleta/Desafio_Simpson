#ifndef PATINETA_H
#define PATINETA_H

#include "objetos/objeto.h"

class Patineta : public Objeto {
public:
    Patineta(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/herramientas/src/img/herramientas/patineta.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016
        );

    TipoObjeto colisionConBart() override; // Sobrescribe el comportamiento
};

#endif // PATINETA_H
