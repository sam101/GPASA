#-------------------------------------------------
#
# Project created by QtCreator 2011-05-22T16:01:24
#
#-------------------------------------------------

QT       += core gui

TARGET = mobileUI
TEMPLATE = app


SOURCES += main.cpp \
    ../Chargeur.cpp \
    ../Config.cpp \
    ../Dossier.cpp \
    ../Heros.cpp \
    ../Inventaire.cpp \
    ../Item.cpp \
    ../Jeu.cpp \
    ../Monde.cpp \
    ../Proposition.cpp \
    ../Question.cpp \
    ../Random.cpp \
    ../Sauvegarde.cpp \
    ../Selectionneur.cpp \
    ../Univers.cpp \
    ../Zone.cpp \
    ../UI/DebugDock.cpp \
    ../UI/MainWindow.cpp \
    ../UI/Selecteur.cpp

HEADERS  += m.h \
    ../Chargeur.h \
    ../Config.h \
    ../Dossier.h \
    ../Heros.h \
    ../Inventaire.h \
    ../Item.h \
    ../Jeu.h \
    ../Monde.h \
    ../Proposition.h \
    ../Question.h \
    ../Random.h \
    ../Sauvegarde.h \
    ../Selectionneur.h \
    ../Univers.h \
    ../Zone.h \
    ../UI/Config.h \
    ../UI/DebugDock.h \
    ../UI/MainWindow.h \
    ../UI/Selecteur.h

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xe12be796
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

OTHER_FILES += \
    android/res/drawable-hdpi/icon.png \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/AndroidManifest.xml \
    android/src/eu/licentia/necessitas/ministro/IMinistroCallback.aidl \
    android/src/eu/licentia/necessitas/ministro/IMinistro.aidl \
    android/src/eu/licentia/necessitas/industrius/QtSurface.java \
    android/src/eu/licentia/necessitas/industrius/QtApplication.java \
    android/src/eu/licentia/necessitas/industrius/QtActivity.java \
    android/res/drawable-hdpi/icon.png \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/drawable-mdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/AndroidManifest.xml \
    android/src/eu/licentia/necessitas/ministro/IMinistroCallback.aidl \
    android/src/eu/licentia/necessitas/ministro/IMinistro.aidl \
    android/src/eu/licentia/necessitas/industrius/QtSurface.java \
    android/src/eu/licentia/necessitas/industrius/QtApplication.java \
    android/src/eu/licentia/necessitas/industrius/QtActivity.java
