//
// Created by atrum on 07.12.19.
// Who sincerely apologize for this dumb class

#ifndef STUDENT_LIFE_MAIN_PLAYER_HPP
#define STUDENT_LIFE_MAIN_PLAYER_HPP

class Player {
private:
    std::string money = "50000";
    std::string health = "30";
    std::string mood = "80";

    std::string friends = "50";
    std::string family = "50";
    std::string girlfriend = "0";
    
    std::string phiz = "10";
    std::string math = "10";
    std::string info = "10";
    
    std::string exp = "0";
    std::string luck = "0";
    std::string communication = "0";
    std::string look = "0";
    std::string brain = "0";
    std::string fit = "0";
public:
    std::map<std::string, std::string *> acessor = {
            {"money",  &money},
            {"health", &health},
            {"mood",   &mood},
            {"friends", &friends},
            {"family", &family},
            {"girlfriend", &girlfriend},
            {"phiz", &phiz},
            {"math", &math},
            {"info", &info},
            {"exp", &exp},
            {"luck", &luck},
            {"communication", &communication},
            {"look", &look},
            {"brain", &brain},
            {"fit", &fit}
    };

    Player() = default;

    Player(const std::string &_money, const std::string &_health, const std::string &_mood) {
        money = _money;
        health = _health;
        mood = _mood;
    }

    int get_money() const {
        return std::stoi(money);
    }

    int get_health() const {
        return std::stoi(health);
    }

    int get_mood() const {
        return std::stoi(mood);
    }

    void set_money(int _money) {
        money = std::to_string(_money);
    }

    void set_health(int _health) {
        if (_health < 100) {
            health = std::to_string(_health);
        } else health = "100";
    }

    void set_mood(int _mood) {
        if (_mood < 100) {
            mood = std::to_string(_mood);
        } else mood = "100";
    }

    int get_friends() const {
        return std::stoi(friends);
    }
    void set_friends(int _new_val) {
        friends = std::to_string(_new_val);
    }

    int get_family() const {
        return std::stoi(family);
    }
    void set_family(int _new_val) {
        family = std::to_string(_new_val);
    }

    int get_girlfriend() const {
        return std::stoi(girlfriend);
    }
    void set_girlfriend(int _new_val) {
        girlfriend = std::to_string(_new_val);
    }

    int get_phiz() const {
        return std::stoi(phiz);
    }
    void set_phiz(int _new_val) {
        phiz = std::to_string(_new_val);
    }

    int get_math() const {
        return std::stoi(math);
    }
    void set_math(int _new_val) {
        math = std::to_string(_new_val);
    }

    int get_info() const {
        return std::stoi(info);
    }
    void set_info(int _new_val) {
        info = std::to_string(_new_val);
    }

    int get_exp() const {
        return std::stoi(exp);
    }
    void set_exp(int _new_val) {
        exp = std::to_string(_new_val);
    }

    int get_luck() const {
        return std::stoi(luck);
    }
    void set_luck(int _new_val) {
        luck = std::to_string(_new_val);
    }

    int get_communication() const {
        return std::stoi(communication);
    }
    void set_communication(int _new_val) {
        communication = std::to_string(_new_val);
    }

    int get_look() const {
        return std::stoi(look);
    }
    void set_look(int _new_val) {
        look = std::to_string(_new_val);
    }

    int get_brain() const {
        return std::stoi(brain);
    }
    void set_brain(int _new_val) {
        brain = std::to_string(_new_val);
    }

    int get_fit() const {
        return std::stoi(fit);
    }
    void set_fit(int _new_val) {
        fit = std::to_string(_new_val);
    }
};

#endif //STUDENT_LIFE_MAIN_PLAYER_HPP
