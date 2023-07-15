cmake -D CMAKE_INSTALL_PREFIX="../framework_install" \
      -D CMAKE_BUILD_TYPE=Release                       \
      -D SINGULAR_HOME=/home/hbn/spack/opt/spack/linux-ubuntu20.04-icelake/gcc-9.4.0/singular-snapshot_22_03-qqvuclfdgojic7xdjgcgw422b6ao4p7y      \
      -D Boost_NO_BOOST_CMAKE=on   \
      -B framework_build                                \
      -S .
cmake --build framework_build --target install -j $(nproc)

