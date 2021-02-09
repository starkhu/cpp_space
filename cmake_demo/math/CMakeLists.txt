aux_source_directory(. DIR_LIB_SRCS)

add_library(MathFunction ${DIR_LIB_SRCS})

install(FILES math.h DESTINATION include)
