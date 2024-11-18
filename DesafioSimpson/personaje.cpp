#include "personaje.h"
#include "constantes.h"
// Constructor
Personaje::Personaje(int id,
                     const QPointF& pos,
                     const QRectF& geom,
                     float masa,
                     const QString& spritePath,
                     bool vis, QGraphicsItem* parent)
    : Item(id, pos, geom, masa, spritePath, vis, parent),
    velocidadX(0),
    velocidadY(0),
    aceleracionX(0),
    aceleracionY(9.8f),
    masa(masa),
    fuerzaSalto(FUERZA_SALTO),//Fuerza del salto en nuevaton, modificar al tanteo
    friccion(FRICCION),   //Modificar valor entre 0 y 1.0
    velocidadMin(VELOCIDAD_MINIMA),
    velocidadMax(VELOCIDAD_MAXIMA),
    enSuelo(false),
    enMovimiento(false),
    saltando(false),
    direccion(0) {}

// Destructor
Personaje::~Personaje() = default;

// Movimiento
void Personaje::moverIzquierda() {
    direccion = -1;
    velocidadX = -velocidadMax / 2;
    enMovimiento = true;
}

void Personaje::moverDerecha() {
    direccion = 1;
    velocidadX = velocidadMax / 2;
    enMovimiento = true;
}

void Personaje::detenerMovimiento() {
    velocidadX = 0;
    direccion = 0;
    enMovimiento = false;
}

// Salto
void Personaje::saltar() {
    if (puedeSaltar()) {
        velocidadY = -fuerzaSalto;
        enSuelo = false;
        saltando = true;
    }
}

bool Personaje::puedeSaltar() const {
    return enSuelo && !saltando;
}

float Personaje::getVelocidadX() const
{
    return velocidadX;
}

void Personaje::setVelocidadX(float nuevaVelocidadX)
{
    velocidadX = nuevaVelocidadX;
}

float Personaje::getVelocidadY() const
{
    return velocidadY;
}

void Personaje::setVelocidadY(float nuevaVelocidadY)
{
    velocidadY = nuevaVelocidadY;
}

float Personaje::getAceleracionX() const
{
    return aceleracionX;
}

void Personaje::setAceleracionX(float nuevaAceleracionX)
{
    aceleracionX = nuevaAceleracionX;
}

float Personaje::getAceleracionY() const
{
    return aceleracionY;
}

void Personaje::setAceleracionY(float nuevaAceleracionY)
{
    aceleracionY = nuevaAceleracionY;
}

float Personaje::getFuerzaSalto() const
{
    return fuerzaSalto;
}

void Personaje::setFuerzaSalto(float nuevaFuerzaSalto)
{
    fuerzaSalto = nuevaFuerzaSalto;
}

float Personaje::getFriccion() const
{
    return friccion;
}

void Personaje::setFriccion(float nuevaFriccion)
{
    friccion = nuevaFriccion;
}

float Personaje::getVelocidadMax() const
{
    return velocidadMax;
}

void Personaje::setVelocidadMax(float nuevaVelocidadMax)
{
    velocidadMax = nuevaVelocidadMax;
}

float Personaje::getVelocidadMin() const
{
    return velocidadMin;
}

void Personaje::setVelocidadMin(float nuevaVelocidadMin)
{
    velocidadMin = nuevaVelocidadMin;
}

bool Personaje::getEnSuelo() const
{
    return enSuelo;
}

void Personaje::setEnSuelo(bool nuevoEnSuelo)
{
    enSuelo = nuevoEnSuelo;
}

int Personaje::getDireccion() const
{
    return direccion;
}

void Personaje::setDireccion(int nuevaDireccion)
{
    direccion =nuevaDireccion;
}

// Físicas
void Personaje::aplicarGravedad(float dt) {
    if (!enSuelo) {
        velocidadY += aceleracionY * dt;
    }
    else {
        velocidadY = 0;
    }
}

void Personaje::actualizarFriccion(float dt) {//dt aún sin usar!!
    if (enSuelo && velocidadX != 0) {
        velocidadX *= friccion;
        if (abs(velocidadX) < 0.1) {
            detenerMovimiento();
        }
    }
}

void Personaje::actualizarPosicion(float dt) {
    posicion.setX(posicion.x() + velocidadX * dt);
    posicion.setY(posicion.y() + velocidadY * dt);
    setPos(posicion);
}

// Estado
void Personaje::actualizarEstado() {
    enMovimiento = (velocidadX != 0);
    saltando = !enSuelo;
}

bool Personaje::estaEnMovimiento() const
{
    return enMovimiento;
}

bool Personaje::estaSaltando() const
{
    return saltando;
}
