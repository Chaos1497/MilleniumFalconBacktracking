cmake_minimum_required(VERSION 3.8)
project(MilleniumFalconBacktracking)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Entidad.cpp Entidad.h Falcon.cpp Falcon.h Sprite.cpp Sprite.h Asteroide.cpp Asteroide.h DeathStar.cpp DeathStar.h Lista.h ListNode.h Mapa.cpp Mapa.h Matrix.h Node.cpp Node.h Backtracking.cpp Backtracking.h PList.h Tiled.cpp Tiled.h)
add_executable(MilleniumFalconBacktracking ${SOURCE_FILES})

INCLUDE_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.1.1_1/include )
LINK_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.1.1_1/lib )

file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.1.1_1/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(MilleniumFalconBacktracking  ${LIBRARIES})

TARGET_LINK_LIBRARIES(MilleniumFalconBacktracking  allegro_acodec
        allegro_audio
        allegro_color
        allegro_dialog
        allegro_image
        allegro_main
        allegro_memfile
        allegro_physfs
        allegro_primitives
        allegro_ttf
        allegro_font
        allegro)