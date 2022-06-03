cd build
rm -r *
cp ../src/input.ssi .
cp ../src/prime.ssi .
cp ../src/modulargp.lib .
cmake ..
cmake --build .
./main
cd ..
