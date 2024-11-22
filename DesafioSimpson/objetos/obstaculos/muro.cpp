#include "muro.h"

Muro::Muro(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    bool solido,
    float dt
    ) : Obstaculo(TipoObjeto::Muro, posicion, geometria, spritePath, visible, destruir, solido, dt) {}

void Muro::actualizar(float deltaTime) {
    Obstaculo::actualizar(deltaTime);
}
