CXX = g++
CXXFLAGS = -g3 -std=c++14 -D__STDC_CONSTANT_MACROS \
		   -Wall -Wextra -Wextra -pedantic \
		   -Wdisabled-optimization -Wctor-dtor-privacy -Wmissing-declarations \
		   -Woverloaded-virtual -Wshadow -Wno-unused -Winline -fprofile-arcs -ftest-coverage
LDLIBS = -lavformat -lavcodec -lavutil -lswscale -lSDL2 -pthread -lgtest -lgtest_main -lgcov





src = $(wildcard demuxer.cpp  display.cpp  ffmpeg.cpp  format_converter.cpp  player.cpp  timer.cpp  video_decoder.cpp main.cpp)
src1 = $(wildcard demuxer.cpp  display.cpp  ffmpeg.cpp  format_converter.cpp  player.cpp  timer.cpp  video_decoder.cpp tests/queue_test.cpp )
src2 = $(wildcard demuxer.cpp  display.cpp  ffmpeg.cpp  format_converter.cpp  player.cpp  timer.cpp  video_decoder.cpp tests/display_test.cpp )
src3 = $(wildcard demuxer.cpp  display.cpp  ffmpeg.cpp  format_converter.cpp  player.cpp  timer.cpp  video_decoder.cpp tests/player_test.cpp )
src4 = $(wildcard demuxer.cpp  display.cpp  ffmpeg.cpp  format_converter.cpp  player.cpp  timer.cpp  video_decoder.cpp tests/demuxer_test.cpp )
src5 = $(wildcard demuxer.cpp  display.cpp  ffmpeg.cpp  format_converter.cpp  player.cpp  timer.cpp  video_decoder.cpp tests/video_decoder_test.cpp )
src6 = $(wildcard demuxer.cpp  display.cpp  ffmpeg.cpp  format_converter.cpp  player.cpp  timer.cpp  video_decoder.cpp tests/ffmpeg_test.cpp )


obj = $(src:.cpp=.o)
obj1 = $(src1:.cpp=.o)
obj2 = $(src2:.cpp=.o)
obj3 = $(src3:.cpp=.o)
obj4 = $(src4:.cpp=.o)
obj5 = $(src5:.cpp=.o)
obj6 = $(src6:.cpp=.o)

dep = $(obj:.o=.d)
dep1 = $(obj1:.o=.d)
dep2 = $(obj2:.o=.d)
dep3 = $(obj3:.o=.d)
dep4 = $(obj4:.o=.d)
dep5 = $(obj5:.o=.d)
dep6 = $(obj6:.o=.d)

target = player
target1 = test_queue
target2 = test_display
target3 = test_player
target4 = test_demuxer
target5 = test_video_decoder
target6 = test_ffmpeg

all: $(target) $(target1) $(target2) $(target3) $(target4) $(target5) $(target6)



$(target): $(obj)
	$(CXX) -o $@ $^ $(LDLIBS)

$(target1): $(obj1)
	$(CXX) -o $@ $^ $(LDLIBS)

$(target2): $(obj2)
	$(CXX) -o $@ $^ $(LDLIBS)

$(target3): $(obj3)
	$(CXX) -o $@ $^ $(LDLIBS)

$(target4): $(obj4)
	$(CXX) -o $@ $^ $(LDLIBS)

$(target5): $(obj5)
	$(CXX) -o $@ $^ $(LDLIBS)

$(target6): $(obj6)
	$(CXX) -o $@ $^ $(LDLIBS)


-include $(dep)

%.d: %.cpp
	@$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

test: $(target)
	./$(target) test.mkv

.PHONY: clean
clean:
	$(RM) $(obj) $(obj1) $(obj2) $(obj3) $(obj4) $(obj5) $(obj6) $(target)  $(target1) $(target2) $(target3) $(target4) $(target5) $(target6) $(dep)
