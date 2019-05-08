#include <gtest/gtest.h>
#include "SDL2/SDL.h"
#include <stdio.h>
#include "../demuxer.h"
#include "../player.h"
#include "../display.h"
#include "../video_decoder.h"

#include <string>
using namespace std;




class Display_test : public testing::Test{
protected:
	
	
	std::unique_ptr<Demuxer> demuxer_;
	std::unique_ptr<VideoDecoder> video_decoder_;
	std::unique_ptr<Display> display_;

	SDL_Event event_;

	void SetUp() override {
//		Player play{"rtsp://127.0.0.1:8554/baz.mkv"};
//		Player play{"/home/dawod/Videos/bazringosh.mp4"};
//		play();

	demuxer_ = std::make_unique<Demuxer>("input/gamar.mp4");
	video_decoder_ = std::make_unique<VideoDecoder>(demuxer_->video_codec_parameters());
	display_ = std::make_unique<Display>(video_decoder_->width(), video_decoder_->height());

   }
	 void TearDown() override {}



void test_pause_resume_request(){

	bool flag1 = false;
	bool flag2 = false;

	ASSERT_TRUE(display_->get_play());
	while(!flag1 || !flag2){
		display_->input();

		if(!display_->get_play())
		{
			ASSERT_TRUE(true);
			flag1 = true;
		}

		if (flag1 && display_->get_play())
		{
			ASSERT_TRUE(true);
			flag2 = true;
		}
	}
}

void test_quit_request(){

	bool flag = false;
	ASSERT_FALSE(display_->get_quit());
	while(!flag){
		display_->input();

		if(display_->get_quit())
		{
			ASSERT_TRUE(true);
			flag = true;
		}
	}
}

};



TEST_F(Display_test,test_input_actions_pause){
  test_pause_resume_request();
}


TEST_F(Display_test,test_input_actions_quite){
  test_quit_request();
}




int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
