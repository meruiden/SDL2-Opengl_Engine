if [ -d build ]; then
	rm -rf build
fi

mkdir -p build
cd build
cmake -Wno-dev ..


make
./project


cd ..
