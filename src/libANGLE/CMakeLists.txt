
SET(ANGLE_SETUP_TARGET_NAME libANGLE)

# SET(HEADER_PATH ${PROJECT_SOURCE_DIR}/include/${ANGLE_SETUP_TARGET_NAME})

SET(ANGLE_SETUP_HEADERS
    # ${HEADER_PATH}/Export.h
)


FILE(GLOB anglebase_SOURCES "../common/third_party/base/anglebase/*.cc")
FILE(GLOB murmurhash_SOURCES "../common/third_party/murmurhash/*.cpp")

FILE(GLOB image_util_SOURCES "../image_util/*.cpp")

FILE(GLOB translator_SOURCES "../compiler/translator/*.cpp")
FILE(GLOB preprocessor_SOURCES "../compiler/preprocessor/*.cpp")

FILE(GLOB compiler_SOURCES "../third_party/compiler/*.cpp")

FILE(GLOB common_SOURCES "../common/*.cpp")
FILE(GLOB common_SOURCES_unittest "../common/*_unittest.cpp")
FILE(GLOB common_SOURCES_linux "../common/*_linux.cpp")
FILE(GLOB common_SOURCES_mac "../common/*_mac.cpp")

FILE(GLOB this_SOURCES "*.cpp")
FILE(GLOB this_SOURCES_unittest "*_unittest.cpp")
FILE(GLOB renderer_SOURCES "renderer/*.cpp")


FILE(GLOB d3d_SOURCES "renderer/d3d/*.cpp")
FILE(GLOB d3d11_SOURCES "renderer/d3d/d3d11/*.cpp")
FILE(GLOB d3d11_win32_SOURCES "renderer/d3d/d3d11/win32/*.cpp")
# FILE(GLOB d3d9_SOURCES "renderer/d3d/d3d9/*.cpp")

FILE(GLOB gl_SOURCES "renderer/gl/*.cpp")
# FILE(GLOB wgl_SOURCES "renderer/gl/wgl/*.cpp")
SET( wgl_SOURCES 
    renderer/gl/wgl/FunctionsWGL.cpp
    )

# FILE(GLOB vulkan_SOURCES "renderer/vulkan/*.cpp")


#filter
foreach(loop_var ${common_SOURCES_unittest})
    # message(${loop_var})
    list(REMOVE_ITEM common_SOURCES ${loop_var})
endforeach(loop_var)
foreach(loop_var ${common_SOURCES_linux})
    # message(${loop_var})
    list(REMOVE_ITEM common_SOURCES ${loop_var})
endforeach(loop_var)
foreach(loop_var ${common_SOURCES_mac})
    # message(${loop_var})
    list(REMOVE_ITEM common_SOURCES ${loop_var})
endforeach(loop_var)

foreach(loop_var ${this_SOURCES_unittest})
    # message(${loop_var})
    list(REMOVE_ITEM this_SOURCES ${loop_var})
endforeach(loop_var)


SET(ANGLE_SETUP_SOURCES
    ${anglebase_SOURCES}
    ${murmurhash_SOURCES}
    ${compiler_SOURCES}
    ${image_util_SOURCES}
    ${common_SOURCES}
    ${translator_SOURCES}
    ${preprocessor_SOURCES}
    
    ${this_SOURCES}
    ${renderer_SOURCES}
    
    ${d3d_SOURCES}
    ${d3d9_SOURCES}
    ${d3d11_SOURCES}
    ${d3d11_win32_SOURCES}
    
    # ${gl_SOURCES}
    # ${wgl_SOURCES}
)

#for static
add_definitions(-DANGLE_EXPORT)

# IF(BUILD_STATIC_LIBRAY)
# ELSE(BUILD_STATIC_LIBRAY)
	# add_definitions(-DLIBANGLE_IMPLEMENTATION)
# ENDIF(BUILD_STATIC_LIBRAY)

INCLUDE_DIRECTORIES(AFTER ${OPENGL_INCLUDE_DIR} )
INCLUDE_DIRECTORIES(AFTER ${PROJECT_SOURCE_DIR}/src )
INCLUDE_DIRECTORIES(AFTER ${PROJECT_SOURCE_DIR}/src/common/third_party/base )
INCLUDE_DIRECTORIES(AFTER ${PROJECT_SOURCE_DIR}/src/third_party/khronos )


ANGLE_SETUP_STATIC_LIBRARY(ON)
# TARGET_LINK_LIBRARIES( ${ANGLE_SETUP_TARGET_NAME} ANGLE )
ANGLE_SETUP_INSTALL()
ANGLE_SETUP_INSTALL_INCLUDE()

