add_library(Services ContactManager.cpp
		     DocumentManager.cpp
		     GroupManager.cpp
		     ProductManager.cpp
		     ResourceManager.cpp
		     )

target_link_libraries(Services PUBLIC DataAccess)

target_include_directories(Services INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
					      ${CMAKE_SOURCE_DIR}/inc_files/DataAccess)

#install(TARGETS Services DESTINATION lib)
#install(FILES   ProductManager.h
#		ResourceManager.h DESTINATION include)