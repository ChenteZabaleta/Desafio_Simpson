#include "plataforma.h"

Plataforma::Plataforma(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    bool solido,
    float dt
    ) : Obstaculo(TipoObjeto::Plataforma, posicion, geometria, spritePath, visible, destruir, solido, dt) {}

void Plataforma::actualizar(float deltaTime) {
    Obstaculo::actualizar(deltaTime);
}
