#include "tirachinas.h"


Tirachinas::Tirachinas(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    float dt
    ) : Objeto(TipoObjeto::Tirachinas, posicion, geometria, spritePath, visible, destruir, dt) {}

TipoObjeto Tirachinas::colisionConBart() {
    if (isVisible() && !isDestruir()) {
        Objeto::colisionConBart(); // Cambia visible y destruir
        return TipoObjeto::Tirachinas; // Devuelve el tipo actualizado
    }
    return TipoObjeto::Generico; // Si ya fue consumido, devuelve tipo genérico
}
