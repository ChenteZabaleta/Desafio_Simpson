#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QPointF>
#include <QRectF>

// Enumeración para el estado de colisión
enum class EstadoColision {
    SinColision,       // No hay colisión
    ColisionDetectada, // Colisión detectada, pero no resuelta
    ColisionResuelta   // Colisión resuelta
};

// Clase base para ítems en la escena
class Item : public QGraphicsPixmapItem {
public:
    // Constructor
    Item(int id,
         const QPointF& pos,
         const QRectF& geom,
         float masa,
         const QString& spritePath,
         bool vis = true,
         QGraphicsItem* parent = nullptr);

    // Destructor virtual
    virtual ~Item();

    // Métodos para acceder y modificar atributos
    int getID() const;
    QPointF getPosicion() const;
    QRectF getGeometria() const;
    float getMasa() const;
    QString getSprite() const;
    bool isVisible() const;
    bool isDestruir() const;
    EstadoColision getEstadoColision() const;

    void setID(int id);
    void setPosicion(const QPointF& pos);
    void setGeometria(const QRectF& geom);
    void setMasa(float m);
    void setSprite(const QString& spritePath);
    void setVisible(bool vis);
    void setDestruir(bool destr);
    void setEstadoColision(EstadoColision estado);

    // Métodos funcionales
    // Método puro virtual para manejar colisiones específicas
    virtual void colisionCon(Item* otroItem) = 0;

    QRectF boundingRect() const override;

protected:
    int ID;                      // Identificador único del ítem
    QPointF posicion;            // Posición del ítem
    QRectF geometria;            // Geometría para colisiones
    float masa;                  // Masa del ítem
    QString sprite;              // Ruta del sprite
    bool visible;                // Estado de visibilidad
    bool destruir;               // Si el ítem debe ser destruido
    EstadoColision estadoColision; // Estado de colisión
};

#endif // ITEM_H
