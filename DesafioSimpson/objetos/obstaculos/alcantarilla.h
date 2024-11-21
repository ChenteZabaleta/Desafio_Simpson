#ifndef ALCANTARILLA_H
#define ALCANTARILLA_H


#include "objetos/objeto.h"

class Alcantarilla : public Objeto {
public:
    Alcantarilla(
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = ":/resources/images/alcantarilla.png",
        bool visible = true,
        bool destruir = false,
        bool bloqueaMovimiento = true,
        float dt = 0.016
        );

    void actualizar(float deltaTime) override;
    bool esSolido() const override;
    void colisionConPersonaje(); // No destruye, pero podría activar algo

private:
    bool bloqueaMovimiento; // Indica si la alcantarilla bloquea el paso
};

#endif // ALCANTARILLA_H
