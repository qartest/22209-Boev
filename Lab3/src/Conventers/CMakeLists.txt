set (LIBRARY_NAME ConventersLib)

add_library(${LIBRARY_NAME} STATIC)


target_link_libraries(${LIBRARY_NAME} PUBLIC wav_hdr)
target_link_libraries(${LIBRARY_NAME} PUBLIC Stream)
target_link_libraries(${LIBRARY_NAME} PUBLIC OneSecond)
target_include_directories(${LIBRARY_NAME} PUBLIC include)

target_sources(${LIBRARY_NAME}
    PUBLIC
        include/Conventers/IConventer.hpp
        include/Conventers/ICreateConventer.hpp
        include/Conventers/Fwd.hpp
        include/Conventers/CreateConventerBass.hpp
        include/Conventers/CreateConventerMix.hpp
        include/Conventers/CreateConventerMute.hpp
        
    PRIVATE
        src/MixConventer.hpp
        src/MixConventer.cpp
        src/MuteConventer.hpp
        src/MuteConventer.cpp
        src/BassConventer.hpp
        src/BassConventer.cpp
        src/CreateConventerMute.cpp 
        src/CreateConventerMix.cpp 
        src/CreateConventerBass.cpp)   