cmake_minimum_required (VERSION 3.15)
project (singular-modular LANGUAGES C CXX)
#enable_testing()

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")

set (INSTALL_DO_NOT_BUNDLE ON CACHE BOOL "")

add_subdirectory (cmake)
include (add_macros)
include (beautify_find_boost)
include (beautify_find_GPISpace)

find_package (GPISpace 22.09 EXACT REQUIRED)
find_boost (1.61 REQUIRED QUIET FROM_GPISPACE_INSTALLATION COMPONENTS
  date_time
  filesystem
  program_options
  regex
  serialization
  system
  test_exec_monitor
  thread
  unit_test_framework
  timer
  iostreams
  chrono
)
find_package (Singular REQUIRED)

#set (BUNDLE_ROOT "libexec/bundle")
#bundle_GPISpace (DESTINATION "${BUNDLE_ROOT}/gpispace" COMPONENTS "runtime" "monitoring")

set(SP_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}")
configure_file("src/installation.hpp.in" "src/installation.hpp")

include_directories ("src")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories ("${CMAKE_CURRENT_BINARY_DIR}/src")

add_subdirectory (src/util-generic)

extended_add_library (NAME installation
	TYPE SHARED 
	NAMESPACE SINGULAR-modular
  SOURCES "src/installation.cpp"
  LIBRARIES Util::Generic GPISpace::execution
  POSITION_INDEPENDENT
  INSTALL
)
set_target_properties (SINGULAR-modular-installation
  PROPERTIES
  INSTALL_RPATH_USE_LINK_PATH TRUE
)

extended_add_library (NAME module
  TYPE SHARED
  NAMESPACE SINGULAR-modular
  SOURCES "src/bin/SINGULAR-modular-module.cpp" "modular/singular_functions.cpp"
  COMPILE_DEFINITIONS SING_NDEBUG OM_NDEBUG
  LIBRARIES SINGULAR-modular::installation Util::Generic GPISpace::execution Singular
  POSITION_INDEPENDENT
  INSTALL
  INSTALL_DESTINATION "${CMAKE_INSTALL_PREFIX}"
)
set_target_properties (SINGULAR-modular-module
  PROPERTIES
  INSTALL_RPATH "$ORIGIN/lib"
  INSTALL_RPATH_USE_LINK_PATH TRUE
)
	
add_subdirectory (modular)
add_subdirectory (workflow)

#install (DIRECTORY "${SINGULAR_HOME}/"
#  DESTINATION "${BUNDLE_ROOT}/singular"
#  USE_SOURCE_PERMISSIONS
#  PATTERN "share/singular/html/*" EXCLUDE
#)
