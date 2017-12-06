
PROJECT(ANGLE)
SET(PROJECT_NAME ANGLE )

IF(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
ENDIF(COMMAND cmake_policy)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMakeModules/")
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.7)
include(angleMacroUtils)

SET(ANGLE_MAJOR_VERSION 0)
SET(ANGLE_MINOR_VERSION 1)
SET(ANGLE_PATCH_VERSION 0)
SET(ANGLE_VERSION ${ANGLE_MAJOR_VERSION}.${ANGLE_MINOR_VERSION}.${ANGLE_PATCH_VERSION})


#render interface
FIND_PACKAGE(OpenGL)
# FIND_PACKAGE(DX9)
# FIND_PACKAGE(Mali)
#FIND_PACKAGE(NVGLES)

#other
# FIND_PACKAGE(Doxygen)



SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

# SET(ANGLE_DEBUG_POSTFIX "d" CACHE STRING "use postfix to link with osg with debug")

IF(WIN32)
    IF(MSVC)
        OPTION(WIN32_USE_MP "Set to ON to build OpenSceneGraph with the /MP option (Visual Studio 2005 and above)." OFF)
        MARK_AS_ADVANCED(WIN32_USE_MP)
        IF(WIN32_USE_MP)
            SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
        ENDIF(WIN32_USE_MP)

        # More MSVC specific compilation flags
        ADD_DEFINITIONS(-D_SCL_SECURE_NO_WARNINGS)
        ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE)
    ENDIF(MSVC)
ENDIF(WIN32)

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} CACHE STRING "You may add additional search paths here. Use ; to separate multiple paths.")


IF (NOT WIN32)
    SET(CMAKE_CXX_FLAGS "-W -Wall -Wno-unused")
ENDIF(NOT WIN32)


# Here we apparantly do some funky stuff with making the bin/ and lib/
# folders which is probably needed to work around a very old CMake bug?

#SET(OUTPUT_BINDIR ${PROJECT_BINARY_DIR}/bin/${CMAKE_SYSTEM_NAME})
SET(OUTPUT_BINDIR ${PROJECT_BINARY_DIR}/bin)
MAKE_DIRECTORY(${OUTPUT_BINDIR})
IF(MSVC AND NOT MSVC_IDE)
    MAKE_DIRECTORY(${OUTPUT_BINDIR}/${OSG_PLUGINS})
ENDIF(MSVC AND NOT MSVC_IDE)

#SET(OUTPUT_LIBDIR ${PROJECT_BINARY_DIR}/lib/${CMAKE_SYSTEM_NAME})
SET(OUTPUT_LIBDIR ${PROJECT_BINARY_DIR}/lib)
MAKE_DIRECTORY(${OUTPUT_LIBDIR})
IF(NOT MSVC OR MSVC_IDE)
    MAKE_DIRECTORY(${OUTPUT_LIBDIR}/${OSG_PLUGINS})
ENDIF(NOT MSVC OR MSVC_IDE)

# On CMake 2.4.x use EXECUTABLE_OUTPUT_PATH and LIBRARY_OUTPUT_PATH and later
# we work around the DLL placement by use of the PREFIX target property hack
#
# On CMake 2.6.x use the newly minted CMAKE_LIBRARY_OUTPUT_DIRECTORY,
# CMAKE_ARCHIVE_OUTPUT_DIRECTORY & CMAKE_RUNTIME_OUTPUT_DIRECTORY

IF(CMAKE_MAJOR_VERSION EQUAL 2 AND CMAKE_MINOR_VERSION LESS 5)
    SET(EXECUTABLE_OUTPUT_PATH ${OUTPUT_BINDIR})
    SET(LIBRARY_OUTPUT_PATH    ${OUTPUT_LIBDIR})
ELSE()
    # If CMake >= 2.6.0
    SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_LIBDIR})
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BINDIR})
    IF(WIN32)
        SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_BINDIR})
    ELSE(WIN32)
        SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_LIBDIR})
    ENDIF(WIN32)
ENDIF()


# set postfix
# SET(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "add a postfix, usually d on windows")
# SET(CMAKE_RELEASE_POSTFIX "" CACHE STRING "add a postfix, usually empty on windows")
# SET(CMAKE_RELWITHDEBINFO_POSTFIX "rd" CACHE STRING "add a postfix, usually empty on windows")
# SET(CMAKE_MINSIZEREL_POSTFIX "s" CACHE STRING "add a postfix, usually empty on windows")

INCLUDE_DIRECTORIES(include ${CMAKE_INCLUDE_PATH} ${OPENSCENEGRAPH_INCLUDE_DIR})
LINK_DIRECTORIES(${CMAKE_LIBRARY_PATH} ${OPENSCENEGRAPH_LIB_DIR})


#option
OPTION(BUILD_DOCUMENTATION "Build  documentation" OFF)
OPTION(BUILD_SAMPLES "build samples" ON)
# OPTION(BUILD_STATIC_LIBRAY "build static library" ON)

OPTION(RENDERER_NULL "" OFF)
OPTION(RENDERER_OPENGL "" OFF)
OPTION(RENDERER_DX_9 "" OFF)
OPTION(RENDERER_DX_11 "" OFF)
OPTION(RENDERER_VULKAN_1 "" OFF)


#system info 
#shell info 
#compiler info

#cygwin
IF( CYGWIN )
	MESSAGE( "system: windows")
	MESSAGE( "environment: cygwin")
	MESSAGE( "compiler: gcc")
ENDIF( CYGWIN )

# msys mingw
IF( MSYS AND MINGW )
	MESSAGE( "system: windows")
	MESSAGE( "environment: msys")
	MESSAGE( "compiler: mingw-gcc")
ENDIF( MSYS AND MINGW )

# msvc IDE NMAKE
IF( WIN32 AND NOT CYGWIN AND NOT MINGW )
	MESSAGE( "system: windows")
	IF(MSVC_IDE)
		MESSAGE( "environment: MSVC_IDE")
		MESSAGE( "compiler: MSVC")
	ELSE(MSVC)
		MESSAGE( "environment: NMAKE")
		MESSAGE( "compiler: MSVC")
	ENDIF(MSVC_IDE)
ENDIF( WIN32 AND NOT CYGWIN AND NOT MINGW)

#mac xcode or makefile
IF( APPLE )
	MESSAGE( "system: Mac OS")
	IF(XCODE_VERSION)
		MESSAGE( "environment: XCODE")
	ELSE(XCODE_VERSION)
		MESSAGE( "environment: Unix make")
	ENDIF(XCODE_VERSION)
    MESSAGE( "compiler: GCC")
ENDIF( APPLE )

# emc
IF( UNIX AND NOT EMSCRIPTEN)
    MESSAGE( "system: UNIX")
    MESSAGE( "environment: Unix make")
    MESSAGE( "compiler: GCC")
    
    # SET(SELECT_PLATFORM 2)
ENDIF(UNIX AND NOT EMSCRIPTEN)

#emc ?
IF( EMSCRIPTEN )
    MESSAGE( "system: EMC")
    MESSAGE( "environment: EMC")
    MESSAGE( "compiler: EMC")
    
    # SET(SELECT_GRAPHICS_INTERFACE 3)
    # SET(SELECT_PLATFORM 4)
ENDIF( EMSCRIPTEN )



IF (MINGW)
    # gcc >= 4.8
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
ENDIF(MINGW)



add_definitions(-DNOMINMAX)

add_definitions(-DANGLE_ENABLE_D3D11)
# add_definitions(-DANGLE_ENABLE_D3D9)
# add_definitions(-DANGLE_ENABLE_OPENGL)
# add_definitions(-DANGLE_ENABLE_NULL)
# add_definitions(-DANGLE_ENABLE_VULKAN)

add_definitions(-DANGLE_ENABLE_GLSL)
add_definitions(-DANGLE_ENABLE_HLSL)
add_definitions(-DANGLE_ENABLE_ESSL)


set(RENDER_LIBRARY d3d11 dxguid)
IF( WIN32 AND NOT CYGWIN AND NOT MINGW )
    set(RENDER_LIBRARY d3d11 dxguid)
    if( CMAKE_SIZEOF_VOID_P EQUAL 8 )
        link_directories("C:/Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x64")
    ELSE(CMAKE_SIZEOF_VOID_P EQUAL 8 )
        link_directories("C:/Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x86")
    ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 8 )
ENDIF( WIN32 AND NOT CYGWIN AND NOT MINGW )



ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(util)

IF ( BUILD_SAMPLES )
    ADD_SUBDIRECTORY(samples)
ENDIF( BUILD_SAMPLES )


install(DIRECTORY 
        include/EGL 
        include/GLES2 
        include/GLES3 
        include/GLSLANG 
        include/KHR 
        include/platform 
        DESTINATION include)


# install(FILES 
        # include/*
        # DESTINATION include)




