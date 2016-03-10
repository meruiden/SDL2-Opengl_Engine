if [ -d build ]; then
	rm -rf build
fi


cd external
cd SDL2-2.0.4

./configure 
make
sudo make install
cd ../
cd SDL2_mixer-2.0.1

./configure
make
sudo make install

cd ../
cd SDL2_ttf-2.0.14

./configure
make
sudo make install

cd ../
cd ../

mkdir -p build
cd build
cmake -Wno-dev ..


make
./project


cd ..
