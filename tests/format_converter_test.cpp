#include <gtest/gtest.h>
#include <stdio.h>
#include "../player.h"
#include "../display.h"

#include <string>
using namespace std;


class Queue_test : public testing::Test{
protected:
	
	

	//=======================================================================================================
	void SetUp() override {
		Player play{"rtsp://127.0.0.1:8554/baz.mkv"};
//		Player play{"/home/dawod/Videos/bazringosh.mp4"};
		play();

   }
	 void TearDown() override {}



void test_queue_push(){
}

void test_queue_pop(){
}





};



TEST_F(Queue_test,test_queue_performance){
  test_queue_push();
  test_queue_pop();
}






int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
