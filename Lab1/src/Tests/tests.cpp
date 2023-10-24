#include "CircularBuffer/CircularBuffer.h"
#include <gtest/gtest.h>

TEST(TestCircularBuffer, simple_test1){
    CircularBuffer first;
 //   EXPECT_EQ(first.capacity(), 1);
    // EXPECT_NO_THROW({
    //     value_type answer = first.front();
    //     answer = first.back();
    // });

    first.set_capacity(5);

    for(int i = 0; i < 199; ++i){
        first.push_back('h');
    }
    for(int i = 0; i < 2; ++i){
        first.push_front('j');
    }
    EXPECT_EQ(first[0], 'j');
    EXPECT_EQ(first[1], 'j');
    EXPECT_EQ(first[2], 'h');

    first.set_capacity(2);

    CircularBuffer second(2, 'h');
    EXPECT_TRUE((first== second));
}

TEST(TestCircularBuffer, simple_test2){
    CircularBuffer first (5);
    for (int i = 0; i < first.capacity(); ++i){
        first.push_back('h');
    }
    EXPECT_TRUE(first.size() == 5);
    EXPECT_NO_THROW({
        value_type check = first.at(4);
    }
    );
    EXPECT_FALSE(first.empty());
    EXPECT_TRUE(first.full());
    
    CircularBuffer first_1(5, 'h');
    EXPECT_FALSE(first_1 != first);

    first.pop_back();
    first.pop_front();

    EXPECT_TRUE(first.reserve() == 2);
    CircularBuffer second(0);

    second.push_back('t');
    first = second;
    EXPECT_ANY_THROW({
        value_type check = first.at(5);
    }
    );
    EXPECT_TRUE(first.capacity() == 1);
    EXPECT_TRUE(first == second);

}

TEST(TestCircularBuffer, simple_test3){
    CircularBuffer first(5, 'j');
    CircularBuffer second(first);

    EXPECT_TRUE(first == second);

    first.insert(0, 'h');

    EXPECT_TRUE(first.front() == 'h');

    first.erase(0, first.capacity());

    second.clear();

    EXPECT_TRUE(first == second);

}
TEST(TestCircularBuffer, rotate){
    CircularBuffer first(8, 'j');
    CircularBuffer second(first);
    first.push_front('k');
    first.pop_front();
    first.pop_front();
    first.push_front('b');
    first.pop_front();
    first.insert(2, 'a');

    first.rotate(2);

    second.push_front('a');
    second.pop_back();
    second.pop_back();

    EXPECT_TRUE(first == second);

    second.push_front('a');
    second.push_front('a');
    second.push_front('a');

    first.push_front('a');
    first.push_front('a');
    first.push_front('a');

    second.linearize();
    EXPECT_TRUE(second == first);
}

TEST(TestCircularBuffer, simple_test4){

    CircularBuffer first (10, 'g'); 
    CircularBuffer third(0);

    third.resize(10, 'g');

    EXPECT_TRUE(third.capacity() == 10);
    EXPECT_TRUE(first == third);

    first.rotate(6);
    first.set_capacity(15);

    EXPECT_FALSE(first.full());
    EXPECT_TRUE(first.is_linearized());
    EXPECT_TRUE(first.capacity() == 15);
    EXPECT_TRUE(first.size() == 10);

    third = first;
    third.rotate(0);
    first.linearize();
    EXPECT_TRUE(first == third);
}

TEST(TestCircularBuffer, simple_test5){

    CircularBuffer first(10);
    for (int i =0; i < first.capacity(); ++i){
        first.push_front('g');
    }

    first.rotate(5);
    first.push_front('h');
    first.rotate(2);
    first.push_back('k');

    for(int i = 0; i < 7; ++i){
        first.pop_front();
    }

    first.linearize();
    const CircularBuffer const_check(first);
    const value_type check_begin = const_check.front();
    const value_type check_back = const_check.back();
    const value_type not_fall = const_check.at(1);

    EXPECT_ANY_THROW({
        const value_type fall = const_check.at(6);
        const value_type not_fall = const_check.at(1);
    });

    const value_type check_operator = const_check[0];
    EXPECT_TRUE(check_begin == 'h');
    EXPECT_TRUE(check_back == 'k');

    first.set_capacity(0);
    first.set_capacity(0);
    CircularBuffer second(first);
}

TEST(TestCircularBuffer, simple_test6){
    CircularBuffer first(6, 'j');
    first.erase(0, 5);
    EXPECT_TRUE(first.is_linearized());
    EXPECT_TRUE(first.size() == 1);

    CircularBuffer second(9, 's');
    CircularBuffer third(second);
    first.swap(second);
    EXPECT_TRUE(first == third);

    EXPECT_FALSE(first == second);
    EXPECT_TRUE( first != second);
    second.set_capacity(9);
    
    EXPECT_FALSE(first == second);
    EXPECT_TRUE( first != second);

    for(int i = 0; i < 8; ++i){
        second.push_front('s');
    }

    EXPECT_FALSE(first == second);
    EXPECT_TRUE( first != second);

    first.set_capacity(0);
    second.set_capacity(0);
    EXPECT_TRUE(first.empty());

    EXPECT_FALSE(first != second);

    first.resize(7, 'j');
    second = first;
    second.push_back('o');

    EXPECT_TRUE( first != second);
    first.pop_front();
    first.erase(1, 5);

    EXPECT_FALSE(first.is_linearized());
    first.set_capacity(7);

    EXPECT_TRUE(first.is_linearized());

    while(first.capacity() != first.size()){
        first.push_back('u');
    }

    EXPECT_TRUE(first != second);
    EXPECT_FALSE(first == second);

}

TEST(TestCircularBuffer, simple_test7){
    CircularBuffer first(10, 'j');
    CircularBuffer second(8, 'j');
    first.pop_back();
    first.pop_front();
    EXPECT_TRUE(first == second);
    EXPECT_FALSE(first != second);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}