//
// Created by atrum on 08.12.19.
//
#ifndef STUDENT_LIFE_MAIN_TIME_HANDLER_HPP
#define STUDENT_LIFE_MAIN_TIME_HANDLER_HPP

#include <SFML/System/Clock.hpp>

class Time_handler_singleton {
private:
    Time_handler_singleton() = default;

    ~Time_handler_singleton() = default;

    sf::Clock Clock;
    sf::Time elapsed_time;
    bool is_running = false;

public:
    Time_handler_singleton(const Time_handler_singleton &) = delete;

    Time_handler_singleton &operator=(Time_handler_singleton &) = delete;

    static Time_handler_singleton &getInstance() {
        static Time_handler_singleton instance;
        return instance;
    }


    void start() {
        elapsed_time = sf::seconds(0);
        Clock.restart();
        is_running = true;
    }

    void freeze() {
        if (is_running)
            elapsed_time += Clock.restart();
        is_running = false;
    }

    void unfreeze() {
        if (!is_running)
            Clock.restart();
        is_running = true;
    }

    sf::Time get_time() {
        if (is_running)
            elapsed_time += Clock.restart();
        return elapsed_time;
    }

    float get_seconds() {
        if (is_running)
            elapsed_time += Clock.restart();
        return elapsed_time.asSeconds();
    }
};

#endif //STUDENT_LIFE_MAIN_TIME_HANDLER_HPP
