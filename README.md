player
======

Video player written in C++14 using FFmpeg libraries and SDL2

Usage
-----

     
    ./player video.mp4


Testing
-----

     
    ./player video.mp4
     lcov --capture --directory . --output-file coverage.info
     genhtml coverage.info --output-directory out
     cd out
     xdg-open index.html

also you can run any one of google test files (.e.g) ./test_demuxer


Controls
--------

* Space: Toggle play/pause
* Escape: Quit

Build
-----

    sudo pacman -S ffmpeg sdl2
    make
