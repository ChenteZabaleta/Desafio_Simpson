#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "objetoFisico/objetofisico.h"

class Personaje : public ObjetoFisico {
public:
    Personaje(
        int vida = 100,
        int energia = 100,
        float vCaminar = 2.0f,
        float vCorrer = 5.0f,
        float fSalto = 10.0f,
        float fFrenado = 0.5f,
        bool dispara = false,
        float tRecarga = 2.0f,
        float tApuntar = 1.0f,
        QPointF posicion = QPointF(0, 0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath = "",
        bool visible = true,
        bool destruir = false,
        bool solido = true,
        float dt = 0.016
        );

    // Getters
    int getVida() const;
    int getEnergia() const;
    float getVCaminar() const;
    float getVCorrer() const;
    float getFSalto() const;
    float getFFrenado() const;
    bool getDispara() const;
    float getTRecarga() const;
    float getTApuntar() const;

    // Setters
    void setVida(int v);
    void setEnergia(int e);
    void setVCaminar(float v);
    void setVCorrer(float v);
    void setFSalto(float f);
    void setFFrenado(float f);
    void setDispara(bool d);
    void setTRecarga(float t);
    void setTApuntar(float t);

    // Métodos adicionales
    void drenarVida(int cantidad);
    void regenerarVida(int cantidad);
    void drenarEnergia(int cantidad);
    void regenerarEnergia(int cantidad);
    void disparar();

private:
    int vida;
    int energia;
    float vCaminar;
    float vCorrer;
    float fSalto;
    float fFrenado;
    bool dispara;
    float tRecarga;
    float tApuntar;
};

#endif // PERSONAJE_H
