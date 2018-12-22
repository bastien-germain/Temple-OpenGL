IF(NOT EXISTS "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/cmake-build-debug/assimp/install_manifest.txt")
  MESSAGE(FATAL_ERROR "Cannot find install manifest: \"/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/cmake-build-debug/assimp/install_manifest.txt\"")
ENDIF(NOT EXISTS "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/cmake-build-debug/assimp/install_manifest.txt")

FILE(READ "/media/julian/DATA/IMAC/OPENGL/Temple-OpenGL/cmake-build-debug/assimp/install_manifest.txt" files)
STRING(REGEX REPLACE "\n" ";" files "${files}")
FOREACH(file ${files})
  MESSAGE(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  EXEC_PROGRAM(
    "/opt/clion-2018.2.6/bin/cmake/linux/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
    OUTPUT_VARIABLE rm_out
    RETURN_VALUE rm_retval
    )
  IF(NOT "${rm_retval}" STREQUAL 0)
    MESSAGE(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
  ENDIF(NOT "${rm_retval}" STREQUAL 0)
ENDFOREACH(file)
