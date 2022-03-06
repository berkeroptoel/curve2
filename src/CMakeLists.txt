# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)

set(COMPONENT_SRCS "main.cpp" "Calibrator.cpp" "FindCurve.cpp" "curveFitting.cpp")
set(COMPONENT_ADD_INCLUDEDIRS "")


idf_component_register(SRCS ${app_sources})




