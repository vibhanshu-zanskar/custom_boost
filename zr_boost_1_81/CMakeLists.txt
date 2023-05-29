cmake_minimum_required(VERSION 3.10)

project(zr_miniboost)

add_library(zr_miniboost_headers INTERFACE)
target_include_directories(zr_miniboost_headers INTERFACE ./)

file(GLOB_RECURSE boost_sources CONFIGURE_DEPENDS libs/system/src/*.cpp libs/test/src/*.cpp libs/program_options/*.cpp)
list(FILTER boost_sources EXCLUDE REGEX "libs/test/src/.*_main.cpp")

function(zr_add_miniboost_compile_options target)
    target_compile_options(${target} PRIVATE -Wno-parentheses -Wno-conversion -Wno-format-overflow -Wno-unused-parameter)
endfunction()

function(zr_add_miniboost_library target type)
    add_library(${target} ${type} ${boost_sources})
    target_link_libraries(${target} PUBLIC zr_miniboost_headers)
    zr_add_miniboost_compile_options(${target})
endfunction()

zr_add_miniboost_library(zr_miniboost STATIC)

zr_add_miniboost_library(zr_miniboost_pic STATIC)
set_property(TARGET zr_miniboost_pic PROPERTY POSITION_INDEPENDENT_CODE ON)

add_library(zr_miniboost_test SHARED libs/test/src/unit_test_main.cpp)
target_link_libraries(zr_miniboost_test PUBLIC zr_miniboost_pic)
zr_add_miniboost_compile_options(zr_miniboost_test)

