#ifndef HEROE_H
#define HEROE_H

#include "personaje.h"
#include <QKeyEvent>
#include <QMap>

class Heroe : public Personaje {
public:
    // Constructor y destructor
    Heroe(int id,
          const QPointF& pos,
          const QRectF& geom,
          float masa,
          const QString& spritePath,
          bool vis = true,
          QGraphicsItem* parent = nullptr);
    virtual ~Heroe();

    // Métodos para gestionar la entrada del teclado
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

    // Métodos para interactuar con las herramientas y el inventario
    void cambiarHerramienta();
    void usarHerramienta();
    void abrirCerrarInventario();

    // Métodos de estado del héroe
    void actualizarEstadoHeroe();

    void colisionCon(Item* otroItem) override;
    void colisionConSuelo();

    // Métodos getters y setters para vida y energía
    int getVida() const;
    int getEnergia() const;

    void setVida(int nuevaVida);
    void setEnergia(int nuevaEnergia);

private:
    // Atributos del héroe
    int vida;
    int energia;

    // Atributos de control de entrada (teclas presionadas)
    QMap<int, bool> teclas; // Mapa para controlar las teclas presionadas

    // Atributos de herramientas y estado del inventario
    int herramientaActual;
    bool inventarioAbierto;
};

#endif // HEROE_H
