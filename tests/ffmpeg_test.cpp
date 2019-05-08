#include <gtest/gtest.h>
#include <stdio.h>
#include "../demuxer.h"

#include <string>
using namespace std;


class FFmpeg_test : public testing::Test{
protected:
	
	std::unique_ptr<Demuxer> demuxer_;
	void SetUp() override {}
	void TearDown() override {}



void test_check_video(string file_name){
	demuxer_ =std::make_unique<Demuxer>(file_name);
//	printf("demuxer = %d\n",demuxer_);
}

void test_check_not_valid_video(string file_name){

}

};

TEST_F(FFmpeg_test,test_check_valid_video){
	ASSERT_NO_THROW(test_check_video("input/gamar.mp4"));
}

TEST_F(FFmpeg_test,test_check_not_valid_video){
	ASSERT_ANY_THROW(test_check_video("input/ytdl"));
}





int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
