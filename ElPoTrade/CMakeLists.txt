cmake_minimum_required(VERSION 3.10)

project(ElPoTrade VERSION 1.0)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/ProjectInst)

message("CIP=${CMAKE_INSTALL_PREFIX}")
message("BINARY=${CMAKE_BINARY_DIR} " "SOURCE=${CMAKE_SOURCE_DIR} " "Qt5_DIR=${Qt5_DIR}")
message("current=${CMAKE_CURRENT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH S:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_subdirectory(inc_files/Common)
add_subdirectory(inc_files/DataAccess)
add_subdirectory(inc_files/GUI)
add_subdirectory(inc_files/Libs/hiberlite)
add_subdirectory(inc_files/Services)
add_subdirectory(database)
add_subdirectory(icons)
add_subdirectory(docs)

list(APPEND EXTRA_LIBS Common
		       DataAccess
		       GUI
		       hiberlite
		       Services
		       Qt5::Core
		       Qt5::Gui
		       Qt5::Widgets
			)

get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)
get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

add_executable(ElPoTrade main.cpp)

target_link_libraries(ElPoTrade PUBLIC ${EXTRA_LIBS})
#for config-file(in future)
#target_include_directories(ElPoTrade PUBLIC
#			   "${PROJECT_BINARY_DIR}"
#			   )

install(TARGETS ElPoTrade DESTINATION ${CMAKE_INSTALL_PREFIX})

execute_process(
    COMMAND "${CMAKE_COMMAND}" -E
        env PATH="${_qt_bin_dir}" "${WINDEPLOYQT_EXECUTABLE}"
            --no-translations
	    --no-system-d3d-compiler
            ${CMAKE_INSTALL_PREFIX}
)