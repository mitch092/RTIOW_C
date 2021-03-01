cmake_minimum_required (VERSION 3.11)
project (RTIOW_C LANGUAGES C)

#set(H_FILES includes/framebuffer.h)
#set(C_FILES src/main.c src/framebuffer.c)
#add_executable(${PROJECT_NAME} ${H_FILES} ${C_FILES})
#target_include_directories(${PROJECT_NAME} includes)
add_executable(${PROJECT_NAME} src/main.c)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_EXTENSIONS OFF)
target_compile_options(${PROJECT_NAME} PRIVATE /Wall /WX)
