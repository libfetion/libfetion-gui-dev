TEMPLATE = app

# ###############################################################################
# Global Configuration
# ###############################################################################
# product release configure
# CONFIG -= debug
# development configure
CONFIG += debug
QT += xml
QT += xmlpatterns
QT += webkit
win32 { 
    message ("WIN32 build start...")
    TARGET = LibFx
    CONFIG += static
    QTPLUGIN += qgif
    LIBS += ./lib/libcurl_imp.lib
}
unix { 
    message ("UNIX build start...")
    TARGET = linux-fetion
    LIBS += -lcurl \
        -lssl \
        ./lib/libfetion_32.a
}
mac { 
    message ("MAC build start...")
    CONFIG += static
    QTPLUGIN += qgif
    TARGET = Mac-Fetion
    ICON = ./misc/mac_fetion.icns
    QMAKE_INFO_PLIST = ./misc/mac_fetion.plist
    LIBS = -lcurl \
        -lssl \
        ./lib/libfetion_mac.a
}
TRANSLATIONS = fetion_utf8_CN.ts
QMAKE_CXXFLAGS += -I./ \
    -I./src \
    -I./.ui
OBJECTS_DIR = $$PWD/.tmp
MOC_DIR = $$PWD/.moc
UI_HEADERS_DIR = $$PWD/.ui

# DEFINES += FX_LIB_FUNC_DEBUG

# sub-directory sources
include (src/include/include.pri)
include (src/fetion-gui.pri)
include (ui/ui.pri)
include (src/model/model.pri)
include (src/view/view.pri)
include (src/widget/widget.pri)

# PR build, no log4qt linked in
# contains ($$CONFIG, debug)
debug { 
    message ("DEBUG profile entered...")
    
    # CONFIG contains 'debug'
    include (log4qt/log4qt.pri)
    DEFINES += HAVE_LOG4QT_DEBUG_ENABLED
}

# ###############################################################################
# Distribute files (data, config)
# ###############################################################################
DISTFILES += data/Location.xml
DISTFILES += 64_libfetion.sh \
    CREDITS.txt \
    install.sh \
    fetion_utf8_CN.qm \
    COPYING \
    README
DISTFILES += lib/*.a \
    lib/libcurl_imp.lib \
    sound/msg.wav
DISTFILES += libfetion/*.h

# ###############################################################################
# Installation
# ###############################################################################
# run a stricp to install our project
unix:target.extra = ./install.sh

# target
target.path += /usr/bin
INSTALLS += target
