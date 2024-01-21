set(LIBRARY_NAME FactoryLib)

add_library(${LIBRARY_NAME} STATIC)

target_include_directories(${LIBRARY_NAME} PUBLIC include)


target_link_libraries(${LIBRARY_NAME} PUBLIC ConventersLib)

target_sources(${LIBRARY_NAME}
	PUBLIC
		include/Factory/FactoryCreator.hpp
		include/Factory/Fwd.hpp
		include/Factory/IFactory.hpp
	PRIVATE
		src/Factory.cpp
		src/Factory.hpp
		src/FactoryCreator.cpp)