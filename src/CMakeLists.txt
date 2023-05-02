configure_file("installation.hpp.in" "installation.hpp" @ONLY)

extended_add_library (NAME installation
  TYPE SHARED
  NAMESPACE SINGULAR-modular
  SOURCES "installation.cpp"
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
  SOURCES "bin/SINGULAR-modular-module.cpp" "../modular/singular_functions.cpp"
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
