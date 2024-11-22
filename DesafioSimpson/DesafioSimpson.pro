QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    entidad.cpp \
    main.cpp \
    mainwindow.cpp \
    objetoFisico/objetofisico.cpp \
    objetoFisico/proyectil/pCanica.cpp \
    objetoFisico/proyectil/pHacha.cpp \
    objetoFisico/proyectil/pVenda.cpp \
    objetoFisico/proyectil/proyectil.cpp \
    objetos/consumibles/baterias.cpp \
    objetos/consumibles/canicas.cpp \
    objetos/consumibles/dona.cpp \
    objetos/consumibles/krustyBurger.cpp \
    objetos/consumibles/llave.cpp \
    objetos/herramientas/linterna.cpp \
    objetos/herramientas/patineta.cpp \
    objetos/herramientas/tirachinas.cpp \
    objetos/objeto.cpp \
    objetos/obstaculos/alcantarilla.cpp \
    objetos/obstaculos/muro.cpp \
    objetos/obstaculos/obstaculo.cpp \
    objetos/obstaculos/piso.cpp \
    objetos/obstaculos/plataforma.cpp \
    objetos/obstaculos/puerta.cpp \
    objetos/obstaculos/rampa.cpp

HEADERS += \
    entidad.h \
    mainwindow.h \
    objetoFisico/objetofisico.h \
    objetoFisico/proyectil/pCanica.h \
    objetoFisico/proyectil/pHacha.h \
    objetoFisico/proyectil/pVenda.h \
    objetoFisico/proyectil/proyectil.h \
    objetos/consumibles/baterias.h \
    objetos/consumibles/canicas.h \
    objetos/consumibles/dona.h \
    objetos/consumibles/krustyBurger.h \
    objetos/consumibles/llave.h \
    objetos/herramientas/linterna.h \
    objetos/herramientas/patineta.h \
    objetos/herramientas/tirachinas.h \
    objetos/objeto.h \
    objetos/obstaculos/alcantarilla.h \
    objetos/obstaculos/muro.h \
    objetos/obstaculos/obstaculo.h \
    objetos/obstaculos/piso.h \
    objetos/obstaculos/plataforma.h \
    objetos/obstaculos/puerta.h \
    objetos/obstaculos/rampa.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    DesafioSimpson_es_CO.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
