#include "fisica.h"

// Implementación de las funciones

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(float x_val, float y_val) : x(x_val), y(y_val) {}

Vector2D Vector2D::operator+(const Vector2D& v) const {
    return Vector2D(x + v.x, y + v.y);
}

Vector2D Vector2D::operator*(float scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator-(const Vector2D& v) const {
    return Vector2D(x - v.x, y - v.y);
}

Vector2D calcularAceleracionConFriccion(const ObjetoFisico& obj, const Vector2D& fuerzaAplicada, float coefFriccion) {
    float fuerzaFriccion = coefFriccion * obj.masa * GRAVEDAD;
    Vector2D aceleracion = (fuerzaAplicada - Vector2D(0, fuerzaFriccion)) * (1.0f / obj.masa);
    return aceleracion;
}

Vector2D calcularPosicionMUA(const Vector2D& posicionInicial, const Vector2D& velocidadInicial,
                             const Vector2D& aceleracion, float tiempo) {
    Vector2D posicionFinal;
    posicionFinal.x = posicionInicial.x + velocidadInicial.x * tiempo + 0.5f * aceleracion.x * tiempo * tiempo;
    posicionFinal.y = posicionInicial.y + velocidadInicial.y * tiempo + 0.5f * aceleracion.y * tiempo * tiempo;
    return posicionFinal;
}

Vector2D calcularPosicionLanzamientoParabolico(const Vector2D& posicionInicial, const Vector2D& velocidadInicial,
                                               float tiempo) {
    Vector2D posicionFinal;
    posicionFinal.x = posicionInicial.x + velocidadInicial.x * tiempo;
    posicionFinal.y = posicionInicial.y + velocidadInicial.y * tiempo - 0.5f * GRAVEDAD * tiempo * tiempo;
    return posicionFinal;
}

Vector2D calcularVelocidadLanzamientoParabolico(const Vector2D& velocidadInicial, float tiempo) {
    Vector2D velocidadFinal;
    velocidadFinal.x = velocidadInicial.x;
    velocidadFinal.y = velocidadInicial.y - GRAVEDAD * tiempo;
    return velocidadFinal;
}

void calcularVelocidadesColisionElastica(float m1, float v1, float m2, float v2,
                                         float& v1_final, float& v2_final) {
    v1_final = ((m1 - m2) * v1 + 2 * m2 * v2) / (m1 + m2);
    v2_final = ((m2 - m1) * v2 + 2 * m1 * v1) / (m1 + m2);
}

float calcularMomentum(const ObjetoFisico& obj) {
    return obj.masa * obj.velocidad.x; // Supone movimiento en la dirección x
}

float calcularCambioMomentum(float fuerzaFriccion, float tiempo) {
    return fuerzaFriccion * tiempo;
}
