cmake_minimum_required(VERSION 3.10)

project(global_lib C)  # Usa 'C' o 'CXX' para C++

# === Configura la biblioteca ===
# 1. Agrega los archivos fuente (.c)
file(GLOB LIB_SOURCES "src/*.c")  # O lista manualmente: set(LIB_SOURCES src/func1.c src/func2.c)

# 2. Crea la biblioteca (estática por defecto)
add_library(global STATIC ${LIB_SOURCES})

# 3. Incluye los headers públicos
target_include_directories(global PUBLIC include)

# (Opcional) Configura estándar de C
set(CMAKE_C_STANDARD 11)

# Crea el ejecutable principal
add_executable(main main.c)
target_link_libraries(main PRIVATE global)
target_include_directories(main PRIVATE include)