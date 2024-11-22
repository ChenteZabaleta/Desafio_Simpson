#include "alcantarilla.h"

Alcantarilla::Alcantarilla(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    bool solido,
    float dt
    ) : Obstaculo(TipoObjeto::Alcantarilla, posicion, geometria, spritePath, visible, destruir, solido, dt) {}

void Alcantarilla::actualizar(float deltaTime) {
    // Lógica específica para Alcantarilla si es necesaria
    Obstaculo::actualizar(deltaTime);
}
