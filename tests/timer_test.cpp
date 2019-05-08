#include <gtest/gtest.h>
#include <stdio.h>
#include <cstdint>
#include <chrono>
#include "../timer.h"
#include <string>
using namespace std;


class Timer_test : public testing::Test{
protected:
	
	

	//=======================================================================================================
	void SetUp() override {
		 timer_ = std::make_unique<Timer>(),
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
