#include "llave.h"


Llave::Llave(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    float dt
    ) : Objeto(TipoObjeto::Llave, posicion, geometria, spritePath, visible, destruir, dt) {}

TipoObjeto Llave::colisionConBart() {
    if (isVisible() && !isDestruir()) {
        Objeto::colisionConBart(); // Cambia visible y destruir
        return TipoObjeto::Llave; // Devuelve el tipo actualizado
    }
    return TipoObjeto::Generico; // Si ya fue consumido, devuelve tipo genérico
}
