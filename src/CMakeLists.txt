project(saper)

set(SOURCES
	main.cpp
        minefield.cpp
        minefield.h
        minefielddrawer.cpp
        minefielddrawer.h
        smallfield.cpp
        smallfield.h
        inputhandler.cpp
        inputhandler.h
        game.cpp
        game.h
        menu.cpp
        menu.h
)

add_library(${PROJECT_NAME}-lib ${SOURCES})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
