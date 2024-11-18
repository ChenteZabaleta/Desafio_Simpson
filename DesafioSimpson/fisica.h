#ifndef FISICA_H
#define FISICA_H

#include "constantes.h"  // Incluye el archivo de constantes

// Estructura para representar un vector 2D (para velocidad, posición, etc.)
struct Vector2D {
    float x, y;

    Vector2D();
    Vector2D(float x_val, float y_val);

    // Sumar dos vectores
    Vector2D operator+(const Vector2D& v) const;

    // Multiplicar un vector por un escalar
    Vector2D operator*(float scalar) const;

    // Restar dos vectores
    Vector2D operator-(const Vector2D& v) const;
};

// Estructura para representar un ObjetoFisico físico (con masa y velocidad)
struct ObjetoFisico {
    float masa;          // Masa del ObjetoFisico (kg)
    Vector2D velocidad; // Velocidad del ObjetoFisico (m/s)
    Vector2D posicion;  // Posición del ObjetoFisico (m)
};

// Función para calcular la aceleración de un ObjetoFisico con fricción
Vector2D calcularAceleracionConFriccion(const ObjetoFisico& obj, const Vector2D& fuerzaAplicada, float coefFriccion);

// Ecuación para el movimiento uniformemente acelerado (MUA)
// Posición en función del tiempo, velocidad inicial, aceleración
Vector2D calcularPosicionMUA(const Vector2D& posicionInicial, const Vector2D& velocidadInicial,
                             const Vector2D& aceleracion, float tiempo);

// Ecuación para el lanzamiento parabólico
Vector2D calcularPosicionLanzamientoParabolico(const Vector2D& posicionInicial, const Vector2D& velocidadInicial,
                                               float tiempo);

// Función para calcular la velocidad de un ObjetoFisico en lanzamiento parabólico
Vector2D calcularVelocidadLanzamientoParabolico(const Vector2D& velocidadInicial, float tiempo);

// Colisiones elásticas: calcular las velocidades después de la colisión en 1D
void calcularVelocidadesColisionElastica(float m1, float v1, float m2, float v2,
                                         float& v1_final, float& v2_final);

// Función para calcular el momentum de un ObjetoFisico
float calcularMomentum(const ObjetoFisico& obj);

// Función para calcular el cambio de momentum debido a la fricción
float calcularCambioMomentum(float fuerzaFriccion, float tiempo);

#endif // FISICA_H
