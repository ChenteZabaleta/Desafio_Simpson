#include "obstaculo.h"

Obstaculo::Obstaculo(
    TipoObjeto tipo,
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    bool solido,
    float dt
    ) : Objeto(tipo, posicion, geometria, spritePath, visible, destruir, solido, dt) {}

TipoObjeto Obstaculo::colisionConPersonaje() {
    // Lógica adicional puede agregarse si es necesario
    return this->getTipo();
}

void Obstaculo::actualizar(float deltaTime) {
    // Lógica general de actualización para obstáculos (puede estar vacía)
    Objeto::actualizar(deltaTime);
}
