//
// Created by atrum on 08.12.19.
//

#include "Time_handler_singleton.hpp"
#include <gtest/gtest.h>
#include <thread>

using namespace std::chrono_literals;

#define Timer Time_handler_singleton::getInstance()

TEST(Time_handler, init) {
    Timer;

    std::this_thread::sleep_for(100ms);

    EXPECT_EQ(Timer.get_seconds(), 0);
}

TEST(Time_handler, start) {
    Timer.start();
    std::this_thread::sleep_for(50ms);

    EXPECT_NEAR(Timer.get_seconds(), 0.05, 0.005);
}

TEST(Time_handler, freeze) {
    Timer.start();
    std::this_thread::sleep_for(50ms);

    Timer.freeze();
    EXPECT_NEAR(Timer.get_seconds(), 0.05, 0.005);

    std::this_thread::sleep_for(50ms);
    EXPECT_NEAR(Timer.get_seconds(), 0.05, 0.005);
    Timer.freeze();

    std::this_thread::sleep_for(50ms);
    EXPECT_NEAR(Timer.get_seconds(), 0.05, 0.005);
}

TEST(Time_handler, unfreeze) {
    Timer.start();
    std::this_thread::sleep_for(50ms);

    Timer.unfreeze();
    EXPECT_NEAR(Timer.get_seconds(), 0.05, 0.005);

    std::this_thread::sleep_for(50ms);
    EXPECT_NEAR(Timer.get_seconds(), 0.1, 0.005);
}

TEST(Time_handler, freeze_unfreeze) {
    Timer.start();
    std::this_thread::sleep_for(50ms);

    Timer.freeze();
    EXPECT_NEAR(Timer.get_seconds(), 0.05, 0.005);

    std::this_thread::sleep_for(50ms);
    EXPECT_NEAR(Timer.get_seconds(), 0.05, 0.005);
    Timer.unfreeze();

    std::this_thread::sleep_for(50ms);
    EXPECT_NEAR(Timer.get_seconds(), 0.1, 0.005);
}

TEST(Time_handler, get_time) {
    Timer.start();
    std::this_thread::sleep_for(50ms);

    EXPECT_NEAR(Timer.get_time().asSeconds(), 0.05, 0.005);
}