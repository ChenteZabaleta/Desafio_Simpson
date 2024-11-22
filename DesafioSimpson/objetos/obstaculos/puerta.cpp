#include "puerta.h"

Puerta::Puerta(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    bool solido,
    float dt
    ) : Obstaculo(TipoObjeto::Puerta, posicion, geometria, spritePath, visible, destruir, solido, dt) {}


void Puerta::abrirPuerta(QString spriteAbiertaPath) {
    // Cambia el estado a no sólido
    setSolido(false);

    // Actualiza la ruta del sprite y asigna el nuevo sprite
    setRutaSprite(spriteAbiertaPath);
    setSprite(QPixmap(spriteAbiertaPath));
}

void Puerta::actualizar(float deltaTime) {
    Obstaculo::actualizar(deltaTime);
}
