#include "patineta.h"

Patineta::Patineta(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    float dt
    ) : Objeto(TipoObjeto::Patineta, posicion, geometria, spritePath, visible, destruir, dt) {}

TipoObjeto Patineta::colisionConBart() {
    if (isVisible() && !isDestruir()) {
        Objeto::colisionConBart(); // Cambia visible y destruir
        return TipoObjeto::Patineta; // Devuelve el tipo actualizado
    }
    return TipoObjeto::Generico; // Si ya fue consumido, devuelve tipo genérico
}
