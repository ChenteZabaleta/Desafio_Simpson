#include "objeto.h"

Objeto::Objeto(TipoObjeto tipo,
               QPointF posicion,
               QRectF geometria,
               QString spritePath,
               bool visible,
               bool destruir,
               bool solido,
               float dt
               ) : Entidad(tipo, posicion, geometria, spritePath, visible, destruir, solido, dt),
    consumido(false) {}

TipoObjeto Objeto::colisionConBart() {
    if (!consumido) {
        consumido = true;
        setVisible(false);  // Oculta el objeto
        setDestruir(true);  // Marca el objeto para ser destruido
        return getTipo();   // Devuelve el tipo del objeto colisionado
    }
    return TipoObjeto::Generico; // Devuelve un tipo genérico si ya fue consumido
}

void Objeto::actualizar(float deltaTime) {
    // Puedes añadir lógica específica para actualizar el objeto si es necesario
    Entidad::actualizar(deltaTime);
}
