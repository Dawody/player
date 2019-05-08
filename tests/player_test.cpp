#include <gtest/gtest.h>
#include <stdio.h>
#include "../player.h"
#include <algorithm>
#include <chrono>
#include <iostream>
extern "C" {
	#include <libavutil/time.h>
	#include <libavutil/imgutils.h>
}

#include <string>
using namespace std;


class Player_test : public testing::Test{
protected:
	

	

	//=======================================================================================================
	void SetUp() override {
//		Player play{"rtsp://127.0.0.1:8554/baz.mkv"};
//		Player play{"/home/dawod/Videos/bazringosh.mp4"};
//		play();

   }
	 void TearDown() override {}



void test_rethrowing_exceptions(){


}

void test_videoPlaying(){

}


};



TEST_F(Player_test,Clause_coverage){
  test_rethrowing_exceptions();
//  test_queue_pop();
}

TEST_F(Player_test,Predicate_coverage){
	test_videoPlaying();
}





int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
