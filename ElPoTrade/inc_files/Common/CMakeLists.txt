add_library(Common Contact.cpp
		ItemDocument.cpp
		Lamp.cpp
		ProductGroup.cpp
		Suggestion.cpp)

target_link_libraries(Common PUBLIC hiberlite)

target_include_directories(Common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
					    ${CMAKE_SOURCE_DIR}/inc_files/Libs/hiberlite)

#install(TARGETS Common DESTINATION lib)
#install(FILES Lamp.h DESTINATION include)