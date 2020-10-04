TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

#SMFL stuff
LIBS += -L"..\SFML-2.0\lib"
LIBS += -L"..\SFML-2.0\bin"


SOURCES += main.cpp \
    token.cpp \
    number.cpp \
    operator.cpp \
    points.cpp \
    ../TwoBalls/ball.cpp \
    ../TwoBalls/game.cpp \
    ../TwoBalls/system.cpp \
    sidebar.cpp

INCLUDEPATH += "..\SFML-2.0\include"
DEPENDPATH += "..\SFML-2.0\include"


CONFIG += c++11


LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "/usr/local/include"
DEPENDPATH += "/usr/local/include"
#-----------------------------------------

#include(deployment.pri)
#qtcAddDeployment()

HEADERS += \
    ../../LinkClass_include/nodes/node_template.h \
    ../../LinkClass_include/LinkList_functions/linklist_template_function.h \
    ../../LinkClass_include/lists/list_templated.h \
    ../../LinkClass_include/Queue/my_queue.h \
    ../../LinkClass_include/Stacks/my_stack.h \
    token.h \
    number.h \
    operator.h \
    points.h \
    ../TwoBalls/ball.h \
    ../TwoBalls/constants.h \
    ../TwoBalls/game.h \
    ../TwoBalls/system.h \
    sidebar.h

#DISTFILES += \
#    ../TwoBalls/deployment.pri

DISTFILES += \
    arial.ttf
