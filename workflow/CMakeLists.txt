# Note: Does _NOT_ track external dependencies!

function(add_petrinet in out module_name)
  add_custom_command (
    OUTPUT "${CMAKE_BINARY_DIR}/${module_name}.pnet"
           "${CMAKE_BINARY_DIR}/gen_${out}/pnetc/op/libsingular_${module_name}.so"
    COMMAND "${GSPC_HOME}/bin/pnetc"
            --Windependent-transition=0
            --gen-cxxflags=-O3
            --gen-cxxflags=-std=c++17
            --gen-cxxflags=-I"${CMAKE_BINARY_DIR}"
            --gen-cxxflags=-I"${CMAKE_SOURCE_DIR}"
            --gen-cxxflags=-I"${CMAKE_SOURCE_DIR}/src"
            --gen-cxxflags=-I"${GSPC_HOME}/include"
            --gen-cxxflags=-I"${GSPC_HOME}/external/boost/include"
            --gen-ldflags="-L${CMAKE_BINARY_DIR}"
            --gen-ldflags="-L${CMAKE_BINARY_DIR}/src/util-generic"
            --gen-ldflags="-Wl,-rpath='\\$\$\\$\$ORIGIN'"
            --gen-ldflags="-Wl,-rpath='${GSPC_HOME}/lib'"
            --gen-ldflags="-Wl,-rpath='${GSPC_HOME}/external/boost/lib'"
            --force-overwrite-file=true
            --input="${CMAKE_SOURCE_DIR}/workflow/${in}"
            --output="${CMAKE_BINARY_DIR}/${out}"
            --path-to-cpp="${CMAKE_BINARY_DIR}/gen_${out}"
            --Wbackup-file=OFF
            --Woverwrite-file=OFF
            &&
            make -C "${CMAKE_BINARY_DIR}/gen_${out}"
    DEPENDS "${in}"
  )
 add_custom_target ("${out}_and_wrapper-library"
   ALL
   DEPENDS "${CMAKE_BINARY_DIR}/gen_${out}/pnetc/op/libsingular_${module_name}.so"
           "${CMAKE_BINARY_DIR}/${out}"
 )
endfunction()

add_petrinet(modular.xpnet modular.pnet modular)


install (FILES
  "${CMAKE_BINARY_DIR}/modular.pnet"
  DESTINATION libexec/workflow
)

install (FILES
 "${CMAKE_BINARY_DIR}/gen_modular.pnet/pnetc/op/libsingular_modular.so"
  DESTINATION libexec/workflow
)
