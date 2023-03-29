# Install script for directory: /home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/hbn/Documents/AIMS/projet/master/github/framework_independent_sub_install5")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/cmake/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/src/util-generic/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSINGULAR-modular-installation.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSINGULAR-modular-installation.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSINGULAR-modular-installation.so"
         RPATH "/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/libexec/iml:/home/hbn/spack/var/spack/environments/gp2209/.spack-env/view/lib:/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/lib:/usr/lib/gcc/x86_64-linux-gnu/9:/usr/lib/x86_64-linux-gnu:/usr/lib:/lib/x86_64-linux-gnu:/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/libSINGULAR-modular-installation.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSINGULAR-modular-installation.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSINGULAR-modular-installation.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSINGULAR-modular-installation.so"
         OLD_RPATH "/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/libexec/iml:/home/hbn/spack/var/spack/environments/gp2209/.spack-env/view/lib:/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/lib:/usr/lib/gcc/x86_64-linux-gnu/9:/usr/lib/x86_64-linux-gnu:/usr/lib:/lib/x86_64-linux-gnu:/lib:"
         NEW_RPATH "/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/libexec/iml:/home/hbn/spack/var/spack/environments/gp2209/.spack-env/view/lib:/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/lib:/usr/lib/gcc/x86_64-linux-gnu/9:/usr/lib/x86_64-linux-gnu:/usr/lib:/lib/x86_64-linux-gnu:/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSINGULAR-modular-installation.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/hbn/Documents/AIMS/projet/master/github/framework_independent_sub_install5/libSINGULAR-modular-module.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/hbn/Documents/AIMS/projet/master/github/framework_independent_sub_install5/libSINGULAR-modular-module.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/hbn/Documents/AIMS/projet/master/github/framework_independent_sub_install5/libSINGULAR-modular-module.so"
         RPATH "$ORIGIN/lib:/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/libexec/iml:/home/hbn/spack/var/spack/environments/gp2209/.spack-env/view/lib:/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/lib:/home/hbn/Singular4/Singular/lib:/usr/lib/gcc/x86_64-linux-gnu/9:/usr/lib/x86_64-linux-gnu:/usr/lib:/lib/x86_64-linux-gnu:/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/hbn/Documents/AIMS/projet/master/github/framework_independent_sub_install5/libSINGULAR-modular-module.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/hbn/Documents/AIMS/projet/master/github/framework_independent_sub_install5" TYPE SHARED_LIBRARY FILES "/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/libSINGULAR-modular-module.so")
  if(EXISTS "$ENV{DESTDIR}/home/hbn/Documents/AIMS/projet/master/github/framework_independent_sub_install5/libSINGULAR-modular-module.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/hbn/Documents/AIMS/projet/master/github/framework_independent_sub_install5/libSINGULAR-modular-module.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/hbn/Documents/AIMS/projet/master/github/framework_independent_sub_install5/libSINGULAR-modular-module.so"
         OLD_RPATH "/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/libexec/iml:/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build:/home/hbn/spack/var/spack/environments/gp2209/.spack-env/view/lib:/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/lib:/home/hbn/Singular4/Singular/lib:/usr/lib/gcc/x86_64-linux-gnu/9:/usr/lib/x86_64-linux-gnu:/usr/lib:/lib/x86_64-linux-gnu:/lib:"
         NEW_RPATH "$ORIGIN/lib:/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/libexec/iml:/home/hbn/spack/var/spack/environments/gp2209/.spack-env/view/lib:/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/gpi-space-22.09-c2fwsd6d7pug6g5qtsxnsrtj4krunlke/lib:/home/hbn/Singular4/Singular/lib:/usr/lib/gcc/x86_64-linux-gnu/9:/usr/lib/x86_64-linux-gnu:/usr/lib:/lib/x86_64-linux-gnu:/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/hbn/Documents/AIMS/projet/master/github/framework_independent_sub_install5/libSINGULAR-modular-module.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/modular/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/workflow/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/hbn/Documents/AIMS/projet/master/github/modular_independent_sub5/framework_build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
