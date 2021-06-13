cmake_minimum_required(VERSION 3.10)

project(ElPoTrade VERSION 1.0)
set(CMAKE_INSTALL_PREFIX S:/perfect_circle/RRProject/ElPoTrade/ProjectInst)

message("CIP=${CMAKE_INSTALL_PREFIX}")
message("BINARY=${CMAKE_BINARY_DIR} " "SOURCE=${CMAKE_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH S:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5)
find_package(Qt5 COMPONENTS Core REQUIRED)

add_subdirectory(inc_files/Common)
add_subdirectory(inc_files/DataAccess)
add_subdirectory(inc_files/GUI)
add_subdirectory(inc_files/Libs/hiberlite)
add_subdirectory(inc_files/Services)
add_subdirectory(database)
add_subdirectory(icons)

list(APPEND EXTRA_LIBS Common
		       DataAccess
		       GUI
		       hiberlite
		       Services
		       Qt5::Core
			)

add_executable(ElPoTrade main.cpp)

target_link_libraries(ElPoTrade PUBLIC ${EXTRA_LIBS})
#for config-file(in future)
#target_include_directories(ElPoTrade PUBLIC
#			   "${PROJECT_BINARY_DIR}"
#			   )

install(TARGETS ElPoTrade DESTINATION ${CMAKE_INSTALL_PREFIX})