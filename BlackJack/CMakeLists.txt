cmake_minimum_required(VERSION 3.12)
project(BlackJack)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BlackJack
        Card.cpp
        Card.h
        CMakeLists.txt
        Deck.cpp
        Deck.h
        Game.cpp
        Game.h
        main.cpp
        Player.cpp
        Player.h
        Max5Cards.h
        Max17Score.h
        Max19Score.h
        WhileNot21.h
        Factory.h)
