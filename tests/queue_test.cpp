#include <gtest/gtest.h>
#include <stdio.h>
#include "../queue.h"
#include <functional>
#include <queue>
#include <memory>
#include <atomic>

#include <string>
using namespace std;

using TestQueue = Queue<std::unique_ptr<int, std::function<void(int*)>>>;


class Queue_test : public testing::Test{
protected:

	int queue_size_ = 5;	
	std::unique_ptr<TestQueue> test_queue_;

	void SetUp() override {
		test_queue_ = std::make_unique<TestQueue>(queue_size_);

   }
	 void TearDown() override {}




void test_queue_push_element(){
	std::unique_ptr<int, std::function<void(int*)>> x{ new int, [](int* p){}};
	*x = 22;
	ASSERT_TRUE(test_queue_->push(move(x)));
}

void test_queue_pop_element(){
		std::unique_ptr<int, std::function<void(int*)>> x{ new int, [](int* p){}};
		ASSERT_TRUE(test_queue_->pop(x));
		ASSERT_EQ(*x , 22);
}


void test_push_element_to_queue_notEmpty(){
	std::unique_ptr<int, std::function<void(int*)>> x{ new int, [](int* p){}};
	*x = 22;
	EXPECT_TRUE(test_queue_->push(move(x)));
	std::unique_ptr<int, std::function<void(int*)>> y{ new int, [](int* p){}};
	*y = 22;
	ASSERT_TRUE(test_queue_->push(move(y)));
}

void test_push_to_full_queue(){
	for(int i =0 ; i<queue_size_ ; i++){
		std::unique_ptr<int, std::function<void(int*)>> x{ new int, [](int* p){}};
		*x = i;
		EXPECT_TRUE(test_queue_->push(move(x)));
	}

	std::unique_ptr<int, std::function<void(int*)>> x{ new int, [](int* p){}};
	*x = 22;

	test_queue_->push(move(x));
	//it will never get here !

}

void test_pop_from_empty_queue(){
	test_queue_pop_element();
}

void test_push_after_quit(){
	test_queue_->quit();
	std::unique_ptr<int, std::function<void(int*)>> y{ new int, [](int* p){}};
	*y = 22;
	ASSERT_FALSE(test_queue_->push(move(y)));
}

void test_pop_after_quit(){

	std::unique_ptr<int, std::function<void(int*)>> x{ new int, [](int* p){}};
	*x = 22;
	EXPECT_TRUE(test_queue_->push(move(x)));
	test_queue_->quit();
	
	std::unique_ptr<int, std::function<void(int*)>> y{ new int, [](int* p){}};
	ASSERT_FALSE(test_queue_->pop(y));
}

void test_pop_after_finished(){	
	test_queue_->finished();
	std::unique_ptr<int, std::function<void(int*)>> y{ new int, [](int* p){}};
	ASSERT_FALSE(test_queue_->pop(y));
}

void test_push_after_finish(){
	test_queue_->finished();
	std::unique_ptr<int, std::function<void(int*)>> y{ new int, [](int* p){}};
	*y = 22;
	ASSERT_FALSE(test_queue_->push(move(y)));
}

void test_pop_from_full_queue(){

	for(int i =0 ; i<queue_size_ ; i++){
		std::unique_ptr<int, std::function<void(int*)>> x{ new int, [](int* p){}};
		*x = i;
		EXPECT_TRUE(test_queue_->push(move(x)));
	}

	std::unique_ptr<int, std::function<void(int*)>> y{ new int, [](int* p){}};
	ASSERT_TRUE(test_queue_->pop(y));
	ASSERT_EQ(*y , 0);
}



};









TEST_F(Queue_test,test_push_element_to_empty_queue){
	test_queue_push_element();
}

TEST_F(Queue_test,test_push_element_to_queue_notEmpty){
	test_push_element_to_queue_notEmpty();
}

TEST_F(Queue_test,test_pop_single_element_queue){
	test_queue_push_element();
	test_queue_pop_element();
}

TEST_F(Queue_test,test_pop_from_full_queue){
	test_pop_from_full_queue();
}

//predicate coverage
TEST_F(Queue_test,test_push_to_full_queue){
//	test_push_to_full_queue();
}
//predicate coverage
TEST_F(Queue_test,test_pop_from_empty_queue){
//	test_pop_from_empty_queue();
}
//predicate coverage
TEST_F(Queue_test,test_push_after_quit){
	test_push_after_quit();
}
//predicate coverage
TEST_F(Queue_test,test_push_after_finish){
	test_push_after_finish();
}
//predicate coverage
TEST_F(Queue_test,test_pop_after_quit){
	test_pop_after_quit();
}
//predicate coverage
TEST_F(Queue_test,test_pop_after_finished){
	test_pop_after_finished();
}





int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
