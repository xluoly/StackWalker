TARGET  =   StackWalker
HEADERS =   stackwalk.h \
            mainwindow.h \
            mapfile.h \
            mangle.h

SOURCES =   main.cpp \
            stackwalk.cpp \
            mainwindow.cpp \
            mapfile.cpp \
            mangle.cpp

FORMS   =   stackwalk.ui \
    tablebox.ui \
    mangle.ui

LIBS += -ldbghelp

DEFINES += _UNICODE

