#ifndef ALCANTARILLA_H
#define ALCANTARILLA_H


#include "objetos/obstaculos/obstaculo.h"

class Alcantarilla : public Obstaculo {
public:
    Alcantarilla(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/resources/images/alcantarilla.png",
        bool visible = true,
        bool destruir = false,
        bool solido = true,
        float dt = 0.016
        );

    void actualizar(float deltaTime) override; // Actualiza el estado específico de Alcantarilla
};

#endif // ALCANTARILLA_H
