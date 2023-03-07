#rm -r framework_build
cmake -D CMAKE_INSTALL_PREFIX="../framework_independent_sub_install5" \
      -D CMAKE_BUILD_TYPE=Release                       \
      -D SINGULAR_HOME=/home/hbn/Singular4/Singular      \
      -B framework_build                                \
      -S .
cmake --build framework_build --target install -j $(nproc)

