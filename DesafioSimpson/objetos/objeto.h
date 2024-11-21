#ifndef OBJETO_H
#define OBJETO_H

#include "entidad.h"

class Objeto : public Entidad {
public:
    Objeto(
        TipoObjeto tipo = TipoObjeto::Generico,
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = "",
        bool visible = true,
        bool destruir = false,
        float dt = 0.016
        );

    // Método para manejar colisión con un Objeto de la clase Bart
    virtual TipoObjeto colisionConBart();

    void actualizar(float deltaTime) override; // Puede personalizar su comportamiento

private:
    bool consumido; // Para evitar múltiples colisiones
};

#endif // OBJETO_H
