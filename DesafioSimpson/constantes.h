#ifndef CONSTANTES_H
#define CONSTANTES_H

// Constantes de física
const float GRAVEDAD = -9.8f;          // Gravedad en el eje Y (hacia abajo)
const float RESISTENCIA_AIRE = 0.1f;    // Resistencia del aire
const float FRICCION = 0.7f;            // Fricción asfalto seco
const float FRICCION_SKATE = 0.5f;       // Fricción asfalto vs skate
const float VELOCIDAD_MAXIMA = 200.0f; // Velocidad máxima en el eje X
const float VELOCIDAD_MINIMA = 100.0f;  // Velocidad mínima en el eje X
const float MASA_PERSONAJE = 70.0f;    // Masa del personaje en kg (solo ejemplo)
const float FUERZA_SALTO = 7.0f;      // Fuerza de salto

// Constantes de juego (puedes ajustar según necesites)
const int VIDA_MAXIMA = 100;   // Vida máxima del héroe
const int ENERGIA_MAXIMA = 100; // Energía máxima del héroe

// Dimensiones del mapa o área de juego
const float ANCHO_MAPA = 1000.0f;   // Ancho del mapa en unidades del juego
const float ALTO_MAPA = 600.0f;     // Alto del mapa en unidades del juego

// Constantes de interacción
// const float TIEMPO_RESPAWN = 5.0f;   // Tiempo de respawn de objetos en segundos

#endif // CONSTANTES_H
