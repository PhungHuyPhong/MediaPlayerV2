cmake_minimum_required(VERSION 3.16)

project(MediaPlayerV2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Bluetooth Multimedia Sensors)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appMediaPlayerV2
    main.cpp
)

qt_add_qml_module(appMediaPlayerV2
    URI MediaPlayerV2
    VERSION 1.0
    QML_FILES

        SOURCES
        SOURCES playlistmodel.h playlistmodel.cpp
        SOURCES mediaplayer.h mediaplayer.cpp
        SOURCES bluetoothmanager.h bluetoothmanager.cpp
        SOURCES sensorsmanager.h sensorsmanager.cpp
        QML_FILES Main.qml
        RESOURCES README.md
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appMediaPlayerV2 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appMediaPlayerV2
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMediaPlayerV2
    PRIVATE QMLModulesplugin Qt6::Quick Qt6::Bluetooth Qt6::Multimedia Qt6::Core Qt6::Gui Qt6::Qml Qt6::Sensors
)

include(GNUInstallDirs)
install(TARGETS appMediaPlayerV2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
add_subdirectory(QMLModules)
