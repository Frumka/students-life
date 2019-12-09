//
// Created by atrum on 08.12.19.
//

#include <gtest/gtest.h>
#include "EventCaller.hpp"

#include <thread>

using namespace std::chrono_literals;


#define EvCaller EventCaller::getInstance()

TEST(EventCaller, init) {
    EXPECT_NO_THROW(EvCaller); //from standart EventList.json in ~/json_events

    EXPECT_NO_THROW(EvCaller.set_EventList("tests/json_event_examples/EventList.json"));
}

TEST(EventCaller, is_event_unique) {
    EXPECT_TRUE(EventCaller::is_event_unique("tests/json_event_examples/testing_event.json"));

    EXPECT_FALSE(EventCaller::is_event_unique("tests/json_event_examples/unexpected_zachet.json"));
}

TEST(EventCaller, choose_random_ivent) {
    std::string paths[] = {"tests/json_event_examples/testing_event.json",
                           "tests/json_event_examples/unavailable_event.json",
                           "tests/json_event_examples/unexpected_zachet.json"};

    int choosed[] = {0, 0, 0};

    EvCaller.set_EventList("tests/json_event_examples/EventList.json");

    for (int i = 0; i < 10; i++) {
        std::string path = EvCaller.choose_random_event();

        for (int j = 0; j < 3; j++) {
            if (path == paths[j])
                choosed[j] += 1;
        }
    }

    EXPECT_EQ(choosed[0], 1);
    EXPECT_EQ(choosed[1], 0);
    EXPECT_EQ(choosed[2], 9);
}

TEST(EventCaller, update_event) {
    std::string paths[] = {"tests/json_event_examples/testing_event.json",
                           "tests/json_event_examples/unavailable_event.json",
                           "tests/json_event_examples/unexpected_zachet.json"};

    int choosed[] = {0, 0, 0};

    EvCaller.set_EventList("tests/json_event_examples/EventList.json");

    EvCaller.update_EventList("tests/json_event_examples/testing_event.json", false);

    for (int j = 0; j < 5; j++) {
        std::string path = EvCaller.choose_random_event();

        for (int k = 0; k < 3; k++) {
            if (path == paths[k])
                choosed[k] += 1;
        }
    }

    EXPECT_EQ(choosed[0], 0);
    EXPECT_EQ(choosed[1], 0);
    EXPECT_EQ(choosed[2], 5);

    EvCaller.update_EventList("tests/json_event_examples/unavailable_event.json", true);
    EvCaller.update_EventList("tests/json_event_examples/unexpected_zachet.json", false);

    std::string path = EvCaller.choose_random_event();
    EXPECT_EQ(path, "tests/json_event_examples/unavailable_event.json");
}

TEST(EventCaller, set_next){
    EvCaller.set_EventList("tests/json_event_examples/EventList.json");

    EvCaller.set_next("tests/json_event_examples/unavailable_event.json");
    
    EXPECT_EQ(EvCaller.choose_random_event(), "tests/json_event_examples/unavailable_event.json");
}