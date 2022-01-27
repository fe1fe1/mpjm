cmake_minimum_required(VERSION 3.16.3)

project(mpjm)

add_executable(${PROJECT_NAME} 
                Animacion.cpp  bola_lvl1.h     disparo_pj.h         escena_gameOver.cpp  escena_juego.h   global.h     pj.h
                Animacion.h    entidad.cpp     escena_gameOver.h    escena_menu.cpp      InputBox.h       nivel_1.cpp  player.h
                entidad.h      escena.h        escena_menu.h        juego.cpp            nivel_1.h        main.cpp     temps_mpjm.h 
                bola_lvl1.cpp  disparo_pj.cpp  escena.cpp           escena_juego.cpp     global.cpp       juego.h      pj.cpp
                escena_gameBeaten.h escena_gameBeaten.cpp   
              )

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
