#include "personaje.h"

Personaje::Personaje(
    int vida,
    int energia,
    float vCaminar,
    float vCorrer,
    float fSalto,
    float fFrenado,
    bool dispara,
    float tRecarga,
    float tApuntar,
    QPointF posicion,
    QRectF geometria,
    QString spritePath,
    bool visible,
    bool destruir,
    bool solido,
    float dt
    ) : ObjetoFisico(
          posicion,
          geometria,
          spritePath,
          visible,
          destruir,
          solido,
          dt),
    vida(vida),
    energia(energia),
    vCaminar(vCaminar),
    vCorrer(vCorrer),
    fSalto(fSalto),
    fFrenado(fFrenado),
    dispara(dispara),
    tRecarga(tRecarga),
    tApuntar(tApuntar) {}


// Getters
int Personaje::getVida() const { return vida; }
int Personaje::getEnergia() const { return energia; }
float Personaje::getVCaminar() const { return vCaminar; }
float Personaje::getVCorrer() const { return vCorrer; }
float Personaje::getFSalto() const { return fSalto; }
float Personaje::getFFrenado() const { return fFrenado; }
bool Personaje::getDispara() const { return dispara; }
float Personaje::getTRecarga() const { return tRecarga; }
float Personaje::getTApuntar() const { return tApuntar; }


// Setters
void Personaje::setVida(int v) { vida = v; }
void Personaje::setEnergia(int e) { energia = e; }
void Personaje::setVCaminar(float v) { vCaminar = v; }
void Personaje::setVCorrer(float v) { vCorrer = v; }
void Personaje::setFSalto(float f) { fSalto = f; }
void Personaje::setFFrenado(float f) { fFrenado = f; }
void Personaje::setDispara(bool d) { dispara = d; }
void Personaje::setTRecarga(float t) { tRecarga = t; }
void Personaje::setTApuntar(float t) { tApuntar = t; }

void Personaje::drenarVida(int cantidad) { vida = std::max(0, vida - cantidad); }
void Personaje::regenerarVida(int cantidad) { vida = std::min(100, vida + cantidad); }
void Personaje::drenarEnergia(int cantidad) { energia = std::max(0, energia - cantidad); }
void Personaje::regenerarEnergia(int cantidad) { energia = std::min(100, energia + cantidad); }

void Personaje::disparar() {
    if (dispara && energia >= 10) {
        energia -= 10;
        // Lógica para disparar, puede generar un proyectil, etc.
    }
}
