# Install script for directory: S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "S:/perfect_circle/RRProject/ElPoTrade/ProjectInst")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/perfect_circle/RRProject/ElPoTrade/cmake_bin/inc_files/Libs/hiberlite/Debug/hiberlite.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/perfect_circle/RRProject/ElPoTrade/cmake_bin/inc_files/Libs/hiberlite/Release/hiberlite.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/perfect_circle/RRProject/ElPoTrade/cmake_bin/inc_files/Libs/hiberlite/MinSizeRel/hiberlite.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/perfect_circle/RRProject/ElPoTrade/cmake_bin/inc_files/Libs/hiberlite/RelWithDebInfo/hiberlite.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/bean_ptr.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/bean_ptr_impl.hpp"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/BeanLoader.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/BeanUpdater_impl.hpp"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/ChildKiller.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/ChildKiller_impl.hpp"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/common.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/CppModel.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/Database.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/Database_tmpl_impl.hpp"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/db_error.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/hiberdefs.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/hiberlite.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/ModelExtractor.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/ModelExtractor_impl.hpp"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/nvp.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/Registry.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/Registry_impl.hpp"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/shared_res.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/some_types.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/sqlite3.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/SQLiteStmt.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/UpdateVisitor_tmpl.hpp"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/Visitor.h"
    "S:/perfect_circle/RRProject/ElPoTrade/inc_files/Libs/hiberlite/Visitor_tmpl_impl.hpp"
    )
endif()

