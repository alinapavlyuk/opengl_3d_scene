# Install script for directory: /Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code

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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.3.0" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/apvlk/Desktop/kpi/графіка/lab2/cmake-build-debug/assimp/bin/libassimpd.5.3.0.dylib"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/cmake-build-debug/assimp/bin/libassimpd.5.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.5.3.0.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimpd.5.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "libassimp5.3.0" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/apvlk/Desktop/kpi/графіка/lab2/cmake-build-debug/assimp/bin/libassimpd.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/anim.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/aabb.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/ai_assert.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/camera.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/color4.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/color4.inl"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/cmake-build-debug/assimp/code/../include/assimp/config.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/ColladaMetaData.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/commonMetaData.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/defs.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/cfileio.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/light.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/material.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/material.inl"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/matrix3x3.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/matrix3x3.inl"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/matrix4x4.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/matrix4x4.inl"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/mesh.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/ObjMaterial.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/pbrmaterial.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/GltfMaterial.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/postprocess.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/quaternion.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/quaternion.inl"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/scene.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/metadata.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/texture.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/types.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/vector2.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/vector2.inl"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/vector3.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/vector3.inl"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/version.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/cimport.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/AssertHandler.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/importerdesc.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Importer.hpp"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/DefaultLogger.hpp"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/ProgressHandler.hpp"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/IOStream.hpp"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/IOSystem.hpp"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Logger.hpp"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/LogStream.hpp"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/NullLogger.hpp"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/cexport.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Exporter.hpp"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/DefaultIOStream.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/DefaultIOSystem.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/ZipArchiveIOSystem.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/SceneCombiner.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/fast_atof.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/qnan.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/BaseImporter.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Hash.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/MemoryIOWrapper.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/ParsingUtils.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/StreamReader.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/StreamWriter.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/StringComparison.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/StringUtils.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/SGSpatialSort.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/GenericProperty.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/SpatialSort.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/SmallVector.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/SmoothingGroups.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/SmoothingGroups.inl"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/StandardShapes.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/RemoveComments.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Subdivision.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Vertex.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/LineSplitter.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/TinyFormatter.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Profiler.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/LogAux.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Bitmap.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/XMLTools.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/IOStreamBuffer.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/CreateAnimMesh.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/XmlParser.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/BlobIOSystem.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/MathFunctions.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Exceptional.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/ByteSwapper.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Base64.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "assimp-dev" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Compiler/pushpack1.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Compiler/poppack1.h"
    "/Users/apvlk/Desktop/kpi/графіка/lab2/assimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

