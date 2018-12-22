# Install script for directory: /media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so.4.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so.4"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/cmake-build-debug/assimp/code/libassimpd.so.4.1.0"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/cmake-build-debug/assimp/code/libassimpd.so.4"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so.4.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so.4"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/cmake-build-debug/assimp/code/libassimpd.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/anim.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/ai_assert.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/camera.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/color4.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/color4.inl"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/cmake-build-debug/assimp/code/../include/assimp/config.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/defs.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/Defines.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/cfileio.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/light.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/material.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/material.inl"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/matrix3x3.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/matrix3x3.inl"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/matrix4x4.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/matrix4x4.inl"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/mesh.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/postprocess.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/quaternion.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/quaternion.inl"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/scene.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/metadata.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/texture.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/types.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/vector2.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/vector2.inl"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/vector3.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/vector3.inl"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/version.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/cimport.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/importerdesc.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/Importer.hpp"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/DefaultLogger.hpp"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/ProgressHandler.hpp"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/IOStream.hpp"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/IOSystem.hpp"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/Logger.hpp"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/LogStream.hpp"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/NullLogger.hpp"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/cexport.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/Exporter.hpp"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/DefaultIOStream.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/DefaultIOSystem.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/SceneCombiner.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/Compiler/poppack1.h"
    "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

