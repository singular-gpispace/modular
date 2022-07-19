#rm -r framework_build
cmake -D CMAKE_INSTALL_PREFIX="../framework-mod_install" \
      -D CMAKE_BUILD_TYPE=Release                       \
      -D SINGULAR_HOME=/opt/Singular430/Singular      \
      -B framework_build                                \
      -S .
cmake --build framework_build --target install -j $(nproc)

