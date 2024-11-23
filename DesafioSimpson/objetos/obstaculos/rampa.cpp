#include "rampa.h"

Rampa::Rampa(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    bool solido,
    float dt
    ) : Obstaculo(TipoObjeto::Rampa, posicion, geometria, spritePath, visible, destruir, solido, dt) {}

void Rampa::actualizar(float deltaTime) {
    Obstaculo::actualizar(deltaTime);
}
