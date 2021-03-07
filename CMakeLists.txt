cmake_minimum_required (VERSION 3.11)
project (RTIOW_C LANGUAGES C)

set(H_FILES includes/image_tga.h
            includes/params.h
            includes/progress.h
            includes/vec3.h)
set(C_FILES src/main.c 
            src/image_tga.c
            src/params.c
            src/progress.c
            src/vec3.c)
            
add_executable(${PROJECT_NAME} ${C_FILES} ${H_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE includes)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY C_EXTENSIONS OFF)
target_compile_options(${PROJECT_NAME} PRIVATE /Wall /WX)
