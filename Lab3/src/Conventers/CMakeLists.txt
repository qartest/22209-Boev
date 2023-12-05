set (LIBRARY_NAME ConventersLib)

add_library(${LIBRARY_NAME} STATIC)

target_link_libraries(${LIBRARY_NAME} PUBLIC WavHeader)
target_link_libraries(${LIBRARY_NAME} PUBLIC OneSecond)
target_include_directories(${LIBRARY_NAME} PUBLIC include)

target_sources(${LIBRARY_NAME}
    PUBLIC
        include/Conventers/IConventer.hpp
        include/Conventers/CreateConventer.hpp
        include/Conventers/Fwd.hpp
        
    PRIVATE
        src/CreateConventer.cpp
        src/MixConventer.hpp
        src/MixConventer.cpp
        src/MuteConventer.hpp
        src/MuteConventer.cpp
        src/BassConventer.hpp
        src/BassConventer.cpp)   