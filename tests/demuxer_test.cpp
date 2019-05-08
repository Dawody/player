#include <gtest/gtest.h>
#include <stdio.h>
#include "../demuxer.h"


#include <string>
using namespace std;


class Demuxer_test : public testing::Test{
protected:
	
	
	std::unique_ptr<Demuxer> demuxer_;
	void SetUp() override {}
	void TearDown() override {}
	
	
	void test_stream_index(string file_name){
		demuxer_ =std::make_unique<Demuxer>(file_name);
		ASSERT_EQ(demuxer_->video_stream_index(),0);	
	}
};



TEST_F(Demuxer_test,test_demuxing_mp4){
	test_stream_index("input/gamar.mp4");
}
TEST_F(Demuxer_test,test_demuxing_mpg){
	test_stream_index("input/gamar.mpg");
}
TEST_F(Demuxer_test,test_demuxing_264){
	test_stream_index("input/gamar.264");
}
TEST_F(Demuxer_test,test_demuxing_mkv){
	test_stream_index("input/gamar.mkv");
}
TEST_F(Demuxer_test,test_demuxing_ogg){
	test_stream_index("input/gamar.ogg");
}




int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
