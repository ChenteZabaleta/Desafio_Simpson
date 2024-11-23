#ifndef KRUSTYBURGER_H
#define KRUSTYBURGER_H


#include "objetos/objeto.h"

class KrustyBurger : public Objeto {
public:
    KrustyBurger(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/consumibles/src/img/consumibles/KrustyBurger.png",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016
        );

    TipoObjeto colisionConBart() override; // Sobrescribe el comportamiento
};

#endif // KRUSTYBURGER_H
