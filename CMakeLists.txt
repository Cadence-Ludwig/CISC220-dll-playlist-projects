cmake_minimum_required(VERSION 4.3)
project(DLLPlaylistProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(DLLPlaylistProject main.cpp
        Song.cpp
        Song.h
        Playlist.cpp
        Playlist.h
        DLL.cpp
        DLL.h
        DNode.cpp
        DNode.h)
