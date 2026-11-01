cmake_minimum_required(VERSION 3.15)
project(PrismModern VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS 
    Core   
    Gui
    Widgets
    Quick
    Qml
    Network
)

add_executable(prismmodern
    src/main.cpp
    models/botmodel.cpp
    models/accountmodel.cpp
    widgets/botwidget.cpp
    widgets/navsidebar.cpp
    widgets/instanceslist.cpp
    widgets/statusbar.cpp
    styles/stylesheet.cpp
)

target_link_libraries(prismmodern PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Quick Qt6::Qml Qt6::Network)

set(QT_RESOURCE_REGISTER OFF)
set(QT_USE_QSTRINGBUILDER OFF)