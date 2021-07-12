set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH ${Qt5_DIR})

if(CMAKE_VERSION VERSION_LESS "3.7.0")
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(GUI ContactScreen.cpp
		DocumentScreen.cpp
		DownloadDocScreen.cpp
		GroupScreen.cpp
		LampScreen.cpp
	        MainScreen.cpp
		ProductScreen.cpp
		ScreenStack.cpp
		SuggestionScreen.cpp
		)

target_link_libraries(GUI PUBLIC Qt5::Widgets
				 Services)

target_include_directories(GUI INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
					 ${CMAKE_SOURCE_DIR}/inc_files/Services)

#install(TARGETS GUI DESTINATION lib)
#install(FILES LampScreen.h
#	      MainScreen.h
#	      ProductScreen.h
#	      ScreenStack.h DESTINATION include)