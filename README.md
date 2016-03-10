# SDL2-Opengl_Engine
an simple game engine using opengl and sdl2

make sure you have installed the following libraries: <br> 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SDL2        https://www.libsdl.org/download-2.0.php <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SDL2_ttf    https://www.libsdl.org/projects/SDL_ttf/ <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SDL2_image  https://www.libsdl.org/projects/SDL_image/ <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SDL2_mixer  https://www.libsdl.org/projects/SDL_mixer/ <br>

How to build:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Unix: <br>

      
    Just run ./bootstrap.sh
    
    or:
      mkdir -p build
      cd build
      cmake -Wno-dev ..
      make
      ./project
      
