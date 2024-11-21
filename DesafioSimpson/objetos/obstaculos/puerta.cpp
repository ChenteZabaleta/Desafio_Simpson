#include "puerta.h"


Puerta::Puerta(
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    bool solido,
    float dt
    ) : Objeto(TipoObjeto::Puerta, posicion, geometria, spritePath, visible, destruir, solido, dt) {}

void Puerta::actualizar(float deltaTime) {
    // Implementar lógica de actualización si es necesario
    dt = deltaTime;
    if(!bloqueada){
        this->setRutaSprite(":/puerta_abierta");
        this->cambiarSprite(this->getRutaSprite());
        this->setSolido(false);
    }
}

void Puerta::colisionConPersonaje() {
    // Implementar interacción si es necesario
}

void Puerta::cambiarTipo(TipoObjeto nuevoTipo) {
    setTipo(nuevoTipo);
    // Cambiar el sprite o comportamiento si es necesario
}

bool Puerta::getBloqueada() const
{
    return bloqueada;
}

void Puerta::setBloqueada(bool nuevoBloqueada)
{
    bloqueada = nuevoBloqueada;
}
