#ifndef PISO_H
#define PISO_H


#include "objetos/obstaculos/obstaculo.h"

class Piso : public Obstaculo {
public:
    Piso(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/resources/images/piso.png",
        bool visible = true,
        bool destruir = false,
        bool solido = true,
        float dt = 0.016
        );

    void actualizar(float deltaTime) override; // Actualiza el estado específico de Piso
};

#endif // PISO_H
