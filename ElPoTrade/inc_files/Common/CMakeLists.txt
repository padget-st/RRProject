add_library(Common Lamp.cpp)

target_link_libraries(Common PUBLIC hiberlite)

target_include_directories(Common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
					    ${CMAKE_SOURCE_DIR}/inc_files/Libs/hiberlite)

install(TARGETS Common DESTINATION lib)
install(FILES Lamp.h DESTINATION include)