cmake_minimum_required(VERSION 3.16)
project(CPP__CoupGAME_a)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPP__CoupGAME_a Demo.cpp Game.cpp Player.cpp Characters/Assassin.cpp Characters/Duke.cpp Characters/Captain.cpp Characters/Ambassador.cpp Characters/Contessa.cpp)
