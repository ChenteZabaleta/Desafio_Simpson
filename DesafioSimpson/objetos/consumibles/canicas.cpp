#include "canicas.h"


Canica::Canica(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    float dt
    ) : Objeto(TipoObjeto::Canica, posicion, geometria, spritePath, visible, destruir, dt) {}

TipoObjeto Canica::colisionConBart() {
    if (isVisible() && !isDestruir()) {
        Objeto::colisionConBart(); // Cambia visible y destruir
        return TipoObjeto::Canica; // Devuelve el tipo actualizado
    }
    return TipoObjeto::Generico; // Si ya fue consumido, devuelve tipo genérico
}
