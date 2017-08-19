
SET(ANGLE_SETUP_TARGET_NAME libGLESv2)

# SET(HEADER_PATH ${PROJECT_SOURCE_DIR}/include/${ANGLE_SETUP_TARGET_NAME})

SET(ANGLE_SETUP_HEADERS
    # ${HEADER_PATH}/Export.h
)

SET(ANGLE_SETUP_SOURCES
    libGLESv2.def
    libGLESv2.cpp
    
    entry_points_egl.cpp
    entry_points_egl_ext.cpp
    entry_points_gles_2_0_autogen.cpp
    entry_points_gles_2_0_ext.cpp
    entry_points_gles_3_0.cpp
    entry_points_gles_3_1.cpp
    global_state.cpp
    
)

# IF(BUILD_STATIC_LIBRAY)

# ELSE(BUILD_STATIC_LIBRAY)
		add_definitions(-DLIBGLESV2_IMPLEMENTATION)
		add_definitions(-DGL_APICALL="")
# ENDIF(BUILD_STATIC_LIBRAY)

INCLUDE_DIRECTORIES(AFTER ${PROJECT_SOURCE_DIR}/src )
INCLUDE_DIRECTORIES(AFTER ${PROJECT_SOURCE_DIR}/src/common/third_party/base )

link_directories("C:/Program Files (x86)/Windows Kits/8.1/Lib/winv6.3/um/x86")

ANGLE_SETUP_DYNAMIC_LIBRARY(ON)
TARGET_LINK_LIBRARIES( ${ANGLE_SETUP_TARGET_NAME} libANGLE d3d11 dxguid)
ANGLE_SETUP_INSTALL()
ANGLE_SETUP_INSTALL_INCLUDE()

