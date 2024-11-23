#include "krustyBurger.h"


KrustyBurger::KrustyBurger(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    float dt
    ) : Objeto(TipoObjeto::KrustyBurger, posicion, geometria, spritePath, visible, destruir, dt) {}

TipoObjeto KrustyBurger::colisionConBart() {
    if (isVisible() && !isDestruir()) {
        Objeto::colisionConBart(); // Cambia visible y destruir
        return TipoObjeto::KrustyBurger; // Devuelve el tipo específico
    }
    return TipoObjeto::Generico;
}
