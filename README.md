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


Notes
-----

     
    some of the testing modules will not work correctly because you need to do the following first
	-create new folder and name it (input)
	-fill it with videos of the following names
		-(gamar.mp4)
		-(gamar.mpg)
		-(gamar.oog)
		-(gamar.mkv)
		-(gamar.264)
		-(12_angry.mp4)
		-(angle.mp4)
	-some of test cases will still fail because of the different window size of the new videos
	I couldn't upload the test videos because they are too large
		
     


Controls
--------

* Space: Toggle play/pause
* Escape: Quit

Build
-----

    sudo pacman -S ffmpeg sdl2
    make
