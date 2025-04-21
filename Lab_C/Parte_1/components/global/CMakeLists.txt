add_library(global global.c)

# Especificar el directorio de los headers para esta librería
target_include_directories(global PUBLIC include)
