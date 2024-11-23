#ifndef ENTIDAD_H
#define ENTIDAD_H


#include <QGraphicsPixmapItem>
#include <QPointF>
#include <QRectF>
#include <QString>
#include <QPixmap>

// Lista de objeto en la escena
enum class TipoObjeto {
    // Consumibles
    KrustyBurger,
    Dona,
    Canica,
    Bateria,
    Llave,
    // Herramientas
    Patineta,
    Tirachinas,
    Linterna,
    // Obtaculos
    Alcantarilla,
    Muro,
    Piso,
    Plataforma,
    Puerta,
    Rampa,
    // Proyectiles
    pCanica,
    pHacha,
    pVenda,
    //Victimas
    Lisa,
    Marge,
    // Enemigos básicos
    Fantasma,
    Arana,
    Momia,
    // Jefe Final
    Tutancamon,
    Homero,
    // Campeón
    Bart,
    // Entorno
    Scene,
    // clase base
    Generico
};

class Entidad: public QGraphicsPixmapItem
{
public:

    Entidad(
        TipoObjeto tipo = TipoObjeto::Generico,
        QPointF posicion = QPointF(0,0),
        QRectF geometria = QRectF(0, 0, 10, 10),
        QString spritePath ="",
        bool visible = true,
        bool destruir = false,
        bool solido = false,
        float dt = 0.016 // Frecuencia de refresco de la pantalla para 60fps.
        );

    // Métodos getters
    TipoObjeto getTipo() const;
    QPointF getPosicion() const;
    QRectF getGeometria() const;
    QString getRutaSprite() const;
    QPixmap getSprite() const;
    bool isVisible() const;
    bool isDestruir() const;
    bool getSolido() const;
    float getDeltaTime() const;

    //Métodos setters
    void setTipo(TipoObjeto tipo);
    void setPosicion(const QPointF &pos);
    void setGeometria(const QRectF &geo);
    void setRutaSprite(const QString &ruta);
    void setSprite(const QPixmap &spr);
    void setVisible(bool vis);
    void setDestruir(bool des);
    void setSolido(bool nuevoSolido);
    void setDeltaTime(float delta);


    // Métodos adicionales
    // Métodos adicionales
    QRectF boundingRect() const override;
    virtual void actualizar(float deltaTime);
    void cambiarSprite(QString nuevoSpritePath);



protected:
    TipoObjeto tipo;
    QPointF posicion;
    QRectF geometria;
    QString rutaSprite;
    QPixmap sprite;
    bool visible;
    bool destruir;
    bool solido;
    float dt;

};

#endif // ENTIDAD_H
