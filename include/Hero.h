#pragma once

class Hero {
public:
    Hero() = default;

    Hero(double a, double b, double c) {
        money = a;
        health = b;
        mood = c;
    }

    double get_money() {
        return money;
    }

    double get_health() {
        return health;
    }

    double get_mood() {
        return mood;
    }

private:
    double money;
    double health;
    double mood;
};