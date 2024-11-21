// Puerta.h
#ifndef PUERTA_H
#define PUERTA_H

#include "objetos/objeto.h"

class Puerta : public Objeto {
public:
    Puerta(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/resources/images/puerta.png",
        bool visible = true,
        bool destruir = false,
        bool solido = true, // Definimos si la puerta es sólida
        float dt = 0.016
        );

    void actualizar(float deltaTime) override;
    void colisionConPersonaje(); // No destruye, pero podría cambiar algún estado
    void cambiarTipo(TipoObjeto nuevoTipo); // Cambia la puerta, p. ej., abrirla

    bool getBloqueada() const;
    void setBloqueada(bool nuevoBloqueada);

protected:
    bool bloqueada;
};

#endif // PUERTA_H
