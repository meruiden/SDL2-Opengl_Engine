# SDL2-Opengl_Engine
an simple game engine using opengl and sdl2

How to build:

  Unix:
    make sure you have installed the following libraries:
      SDL2        https://www.libsdl.org/download-2.0.php
      SDL2_ttf    https://www.libsdl.org/projects/SDL_ttf/
      SDL2_image  https://www.libsdl.org/projects/SDL_image/
      SDL2_mixer  https://www.libsdl.org/projects/SDL_mixer/
      
    Just run ./bootstrap.sh
    
    or:
      mkdir -p build
      cd build
      cmake -Wno-dev ..
      make
      ./project
      
