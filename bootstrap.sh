if [ -d build ]; then
	rm -rf build
fi

mkdir -p build
cd build
cmake -Wno-dev ..

cd ../
cd classmaker
make

cd ../
cd build

make
./project
