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
         float masa,
         const QString& spritePath,
         bool vis = true,
         QGraphicsItem* parent = nullptr);

    // Destructor virtual
    virtual ~Item();

    // Métodos getter y setter
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

    // Rectángulo delimitador del sprite
    QRectF boundingRect() const override;

protected:
    int ID;                         // Identificador único del ítem
    QPointF posicion;               // Posición del ítem
    QRectF geometria;               // Geometría para colisiones
    float masa;                     // Masa del ítem
    QString rutaSprite;             // Ruta del sprite
    QPixmap sprite;                 // imagen del sprite
    bool visible;                   // Estado de visibilidad
    bool destruir;                  // Si el ítem debe ser destruido
    EstadoColision estadoColision;  // Estado de colisión
};

#endif // ITEM_H
