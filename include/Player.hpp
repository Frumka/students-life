//
// Created by atrum on 07.12.19.
//

#ifndef STUDENT_LIFE_MAIN_PLAYER_HPP
#define STUDENT_LIFE_MAIN_PLAYER_HPP

class Player{
private:
    std::string money = "50000";
    std::string health = "30";
    std::string mood = "80";

public:
    std::map<std::string, std::string*> acessor = {
            {"money", &money},
            {"health", &health},
            {"mood", &mood}
    };

    Player() = default;

    Player(const std::string &_money, const std::string &_health, const std::string &_mood){
        money = _money;
        health = _health;
        mood = _mood;
    }

    int get_money()const{
        return std::stoi(money);
    }

    int get_health()const{
        return std::stoi(health);
    }

    int get_mood()const{
        return std::stoi(mood);
    }

    void set_money(int _money){
        money = std::to_string(_money);
    }

    void set_health(int _health){
        if(_health < 100){
            health = std::to_string(_health);
        }
        else health = "100";
    }

    void set_mood(int _mood){
        if(_mood < 100){
            mood = std::to_string(_mood);
        }
        else mood = "100";
    }
};
#endif //STUDENT_LIFE_MAIN_PLAYER_HPP
