#ifndef PUERTA_H
#define PUERTA_H

#include "obstaculo.h"

class Puerta : public Obstaculo {
public:
    Puerta(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/resources/images/puerta.png",
        bool visible = true,
        bool destruir = false,
        bool solido = true,
        float dt = 0.016
        );

    void abrirPuerta(QString spriteAbiertaPath = ":/resources/images/puerta_abierta.png"); // Cambia el estado a abierta
    void actualizar(float deltaTime) override; // Actualiza el estado específico de Puerta
};

#endif // PUERTA_H
