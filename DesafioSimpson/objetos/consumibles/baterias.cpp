#include "baterias.h"

Bateria::Bateria(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    float dt
    ) : Objeto(TipoObjeto::Bateria, posicion, geometria, spritePath, visible, destruir, dt) {}

TipoObjeto Bateria::colisionConBart() {
    if (isVisible() && !isDestruir()) {
        Objeto::colisionConBart(); // Cambia visible y destruir
        return TipoObjeto::Bateria; // Devuelve el tipo actualizado
    }
    return TipoObjeto::Generico; // Si ya fue consumido, devuelve tipo genérico
}
