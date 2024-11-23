#ifndef PLATAFORMA_H
#define PLATAFORMA_H


#include "objetos/obstaculos/obstaculo.h"

class Plataforma : public Obstaculo {
public:
    Plataforma(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/resources/images/plataforma.png",
        bool visible = true,
        bool destruir = false,
        bool solido = true,
        float dt = 0.016
        );

    void actualizar(float deltaTime) override; // Actualiza el estado específico de Plataforma
};

#endif // PLATAFORMA_H
