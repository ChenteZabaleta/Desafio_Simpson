#ifndef MURO_H
#define MURO_H


#include "objetos/obstaculos/obstaculo.h"

class Muro : public Obstaculo {
public:
    Muro(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/resources/images/muro.png",
        bool visible = true,
        bool destruir = false,
        bool solido = true,
        float dt = 0.016
        );

    void actualizar(float deltaTime) override; // Actualiza el estado específico de Muro
};

#endif // MURO_H
