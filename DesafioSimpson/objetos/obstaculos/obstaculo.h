#ifndef OBSTACULO_H
#define OBSTACULO_H



#include "objetos/objeto.h"

class Obstaculo : public Objeto {
public:
    Obstaculo(
        TipoObjeto tipo = TipoObjeto::Generico,
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = "",
        bool visible = true,
        bool destruir = false,
        bool solido = true,
        float dt = 0.016
        );

    TipoObjeto colisionConPersonaje(); // Retorna el tipo de objeto al colisionar
    void actualizar(float deltaTime) override; // Actualiza el estado del obstáculo
};

#endif // OBSTACULO_H
