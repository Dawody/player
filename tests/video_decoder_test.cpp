#include <gtest/gtest.h>
#include <stdio.h>
#include "../demuxer.h"
#include "../video_decoder.h"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>

using namespace std;



extern "C" {
#include <libavutil/time.h>
#include <libavutil/imgutils.h>
#include <libavcodec/avcodec.h>
}

class Video_decoder_test : public testing::Test{
protected:
	
	


	std::unique_ptr<Demuxer> demuxer_;
	std::unique_ptr<VideoDecoder> video_decoder_;

		     


	void SetUp() override {


	demuxer_ = std::make_unique<Demuxer>("/home/dawod/GP/live555/live/mediaServer/gamar.mp4");
	
	video_decoder_ = std::make_unique<VideoDecoder>(demuxer_->video_codec_parameters());
	
	std::unique_ptr<AVPacket, std::function<void(AVPacket*)>>packet{nullptr, [](AVPacket* p){ av_packet_unref(p); delete p; }};

   }
	 void TearDown() override {}



void test_packet_decoding(string file_name ){
	demuxer_ = std::make_unique<Demuxer>(file_name);
	video_decoder_ = std::make_unique<VideoDecoder>(demuxer_->video_codec_parameters());
	std::unique_ptr<AVPacket, std::function<void(AVPacket*)>>packet{nullptr, [](AVPacket* p){ av_packet_unref(p); delete p; }};
	std::unique_ptr<AVFrame, std::function<void(AVFrame*)>>frame_decoded{av_frame_alloc(), [](AVFrame* f){ av_frame_free(&f); }};
	bool sent = video_decoder_->send(packet.get());
	ASSERT_TRUE(sent);
//	int counter = 100000;
//	while(!(video_decoder_->receive(frame_decoded.get())))
//	{
//		if(counter-- < 0 )
//			ASSERT_TRUE(false);
//	}
//	ASSERT_TRUE(true);


}

void test_video_width(string file_name, int w){
	
	demuxer_ = std::make_unique<Demuxer>(file_name);
	video_decoder_ = std::make_unique<VideoDecoder>(demuxer_->video_codec_parameters());
	ASSERT_EQ(video_decoder_->width(),w);
}

void test_video_height(string file_name, int h){
	
	demuxer_ = std::make_unique<Demuxer>(file_name);
	video_decoder_ = std::make_unique<VideoDecoder>(demuxer_->video_codec_parameters());
	ASSERT_EQ(video_decoder_->height(),h);

}

};



TEST_F(Video_decoder_test,test_packet_decoding_mp4){
	test_packet_decoding("input/gamar.mp4");
}

TEST_F(Video_decoder_test,test_packet_decoding_mpg){
	test_packet_decoding("input/gamar.mpg");
}
TEST_F(Video_decoder_test,test_packet_decoding_mkv){
	test_packet_decoding("input/gamar.mkv");
}
TEST_F(Video_decoder_test,test_packet_decoding_264){
	test_packet_decoding("input/gamar.264");
}
TEST_F(Video_decoder_test,test_packet_decoding_ogg){
	test_packet_decoding("input/gamar.ogg");
}
TEST_F(Video_decoder_test,test_packet_decoding_mp4_long_video){
	test_packet_decoding("input/angle.mp4");
}

//testing width for different decoders
TEST_F(Video_decoder_test,test_video_width_mp4){
	test_video_width("input/gamar.mp4",640);
}
TEST_F(Video_decoder_test,test_video_width_mpg){
	test_video_width("input/gamar.mpg",640);
}
TEST_F(Video_decoder_test,test_video_width_mkv){
	test_video_width("input/gamar.mkv",640);
}
TEST_F(Video_decoder_test,test_video_width_264){
	test_video_width("input/gamar.264",640);
}
TEST_F(Video_decoder_test,test_video_width_ogg){
	test_video_width("input/gamar.ogg",640);
}

//testing height for different decoders
TEST_F(Video_decoder_test,test_video_height_mp4){
	test_video_height("input/gamar.mp4",360);
}
TEST_F(Video_decoder_test,test_video_height_mpg){
	test_video_height("input/gamar.mpg",360);
}
TEST_F(Video_decoder_test,test_video_height_mkv){
	test_video_height("input/gamar.mkv",360);
}
TEST_F(Video_decoder_test,test_video_height_264){
	test_video_height("input/gamar.264",360);
}
TEST_F(Video_decoder_test,test_video_height_ogg){
	test_video_height("input/gamar.ogg",360);
}

//testing width and height for different videos
TEST_F(Video_decoder_test,test1_video_width_mp4){
	test_video_width("input/12_angry.mp4",1792);
}
TEST_F(Video_decoder_test,test1_video_height_mp4){
	test_video_height("input/12_angry.mp4",1072);
}
TEST_F(Video_decoder_test,Test2_video_width_mp4){
	test_video_width("input/angle.mp4",1920);
}
TEST_F(Video_decoder_test,test2_video_height_mp4){
	test_video_height("input/angle.mp4",1024);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
