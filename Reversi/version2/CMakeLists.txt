project ( REVERSI )
cmake_minimum_required (VERSION 3.0)

if ( CMAKE_COMPILER_IS_GNUCXX )
   message ( "Especificamos flags concretos para la gnu..." )
   set( REVERSI_EXTRA_CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++14" 
        CACHE STRING "Flags extra que se añaden a CMAKE_CXX_FLAGS" )
   set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${REVERSI_EXTRA_CMAKE_CXX_FLAGS}" )
else() # Si estamos con otro, al menos fijamos que es C++14
   set ( CMAKE_CXX_STANDARD 14 )
endif( CMAKE_COMPILER_IS_GNUCXX )

# El desarrollo se hace como Debug. Por comodidad, lo fijamos.
set (CMAKE_BUILD_TYPE "Debug" CACHE STRING "Fijamos Debug" FORCE)

set ( REVERSI_SRCS
      matriz.h matriz.cpp
      tablero.h tablero.cpp
      jugador.h jugador.cpp
      main.cpp
    )

add_executable ( reversi ${REVERSI_SRCS} )


