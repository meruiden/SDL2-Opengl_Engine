# Install script for directory: /Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/build/external/SDL2-2.0.4/libSDL2.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2.a")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/build/external/SDL2-2.0.4/libSDL2-2.0.0.4.0.dylib"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/build/external/SDL2-2.0.4/libSDL2-2.0.0.dylib"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/build/external/SDL2-2.0.4/libSDL2-2.0.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.0.4.0.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.0.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2-2.0.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      execute_process(COMMAND "/usr/bin/install_name_tool"
        -id "libSDL2-2.0.0.dylib"
        "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/build/external/SDL2-2.0.4/libSDL2main.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2main.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2main.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSDL2main.a")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/begin_code.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/close_code.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_assert.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_atomic.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_audio.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_bits.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_blendmode.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_clipboard.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_config_android.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_config_iphoneos.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_config_macosx.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_config_minimal.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_config_pandora.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_config_psp.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_config_windows.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_config_winrt.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_config_wiz.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_copying.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_cpuinfo.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_egl.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_endian.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_error.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_events.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_filesystem.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_gamecontroller.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_gesture.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_haptic.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_hints.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_joystick.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_keyboard.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_keycode.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_loadso.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_log.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_main.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_messagebox.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_mouse.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_mutex.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_name.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_opengl.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_opengl_glext.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_opengles.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_opengles2.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_opengles2_gl2.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_opengles2_gl2ext.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_opengles2_gl2platform.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_opengles2_khrplatform.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_pixels.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_platform.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_power.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_quit.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_rect.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_render.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_revision.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_rwops.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_scancode.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_shape.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_stdinc.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_surface.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_system.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_syswm.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_assert.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_common.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_compare.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_crc32.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_font.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_fuzzer.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_harness.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_images.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_log.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_md5.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_test_random.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_thread.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_timer.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_touch.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_types.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_version.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/include/SDL_video.h"
    "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/build/external/SDL2-2.0.4/include/SDL_config.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
      execute_process(COMMAND /usr/local/bin/cmake -E create_symlink
      "libSDL2-2.0.so" "libSDL2.so")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/build/external/SDL2-2.0.4/libSDL2.so")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/build/external/SDL2-2.0.4/sdl2.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/build/external/SDL2-2.0.4/sdl2-config")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/aclocal" TYPE FILE FILES "/Users/cornesteenhuis/Dropbox (Edutales)/csFramework/2d/opengl_SDL2/external/SDL2-2.0.4/sdl2.m4")
endif()

