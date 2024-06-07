cmake_minimum_required(VERSION 3.26)
project(Lightsed)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lightsed main.cpp
        Cell.h
        Player.h
        Locked.h
        Locked.cpp
        Cell.cpp
        constants.h
        Map.h
        Map.cpp
        Player.cpp
        Light.h
        BaseObject.h
        BaseObject.cpp
        Button.h
        Point.h
        Point.cpp
        Button.cpp
        UpgradeButton.h
        Light.cpp
        UpgradeButton.cpp
        Upgrades.h
        Tab.cpp
        Tab.h
)

target_link_libraries(Lightsed sfml-system)
target_link_libraries(Lightsed sfml-graphics)
target_link_libraries(Lightsed sfml-window)