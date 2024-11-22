#include "piso.h"

Piso::Piso(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    bool solido,
    float dt
    ) : Obstaculo(TipoObjeto::Piso, posicion, geometria, spritePath, visible, destruir, solido, dt) {}

void Piso::actualizar(float deltaTime) {
    Obstaculo::actualizar(deltaTime);
}
