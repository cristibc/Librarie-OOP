cmake_minimum_required(VERSION 3.21)
project(OOPTesting)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOPTesting main.cpp Carte.cpp Carte.h ComicBook.cpp ComicBook.h Order.cpp Order.h Librarie.cpp Librarie.h Abonament.cpp Abonament.h PachetPromo.cpp PachetPromo.h Review.h)
