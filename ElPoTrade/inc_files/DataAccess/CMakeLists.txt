add_library(DataAccess ProductDataManager.cpp)

target_link_libraries(DataAccess PUBLIC Common)

target_include_directories(DataAccess INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
						${CMAKE_SOURCE_DIR}/inc_files/Common)

install(TARGETS DataAccess DESTINATION lib)
install(FILES ProductDataManager.h DESTINATION include)