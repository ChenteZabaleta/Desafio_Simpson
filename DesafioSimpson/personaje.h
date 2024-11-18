#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "item.h"

class Personaje : public Item {
public:
    // Constructor y destructor
    Personaje(int id, const QPointF& pos, const QRectF& geom, float masa, const QString& spritePath, bool vis = true, QGraphicsItem* parent = nullptr);
    virtual ~Personaje();

    // Métodos de movimiento
    void moverIzquierda();
    void moverDerecha();
    void detenerMovimiento();
    void saltar();

    // Métodos de físicas
    void aplicarGravedad(float dt);
    void actualizarFriccion(float dt);
    void actualizarPosicion(float dt);
    // void colisionarConSuelo(); //Sin definir aún.

    // Métodos de estado
    void actualizarEstado();
    bool estaEnMovimiento() const;
    bool estaSaltando() const;
    bool puedeSaltar() const;

    //Métodos getters
    float getVelocidadX() const;
    float getVelocidadY() const;
    float getAceleracionX() const;
    float getAceleracionY() const;
    float getFuerzaSalto() const;
    float getFriccion() const;
    float getVelocidadMax() const;
    float getVelocidadMin() const;
    int getDireccion() const;

    //Métodos setters
    void setVelocidadX(float nuevaVelocidadX);
    void setVelocidadY(float nuevaVelocidadY);
    void setAceleracionX(float nuevaAceleracionX);
    void setAceleracionY(float nuevaAceleracionY);
    void setFuerzaSalto(float nuevaFuerzaSalto);
    void setFriccion(float nuevaFriccion);
    void setVelocidadMax(float nuevaVelocidadMax);
    void setDireccion(int nuevaDireccion);
    void setVelocidadMin(float nuevaVelocidadMin);


    bool getEnSuelo() const;
    void setEnSuelo(bool nuevoEnSuelo);

private:
    // Atributos de físicas
    float velocidadX;
    float velocidadY;
    float aceleracionX;
    float aceleracionY;
    float masa;
    float fuerzaSalto;
    float friccion;
    float velocidadMin;
    float velocidadMax;

    // Estados
    bool enSuelo;
    bool enMovimiento;
    bool saltando;

    // Dirección
    int direccion;
};

#endif // PERSONAJE_H
