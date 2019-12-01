// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_EVENT_PROCESSOR_HPP_
#define INCLUDE_EVENT_PROCESSOR_HPP_

#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

std::vector<std::string> split(const std::string& s, char delimiter='.')
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

class event_processor{
public:
    json saved_event = {};

    std::map<std::string, std::map<std::string, std::string*>> acessor;

    event_processor()= default;

    explicit event_processor(std::map<std::string, std::map<std::string, std::string*>> map){
        acessor = std::move(map);
    }

    void link_acessor(std::map<std::string, std::map<std::string, std::string*>> map){
        acessor = std::move(map);
    }

    void load_event(std::string path){
        std::ifstream text_stream(path);
        text_stream >> saved_event;
    }

    std::map<std::string, std::string*> operator[](const std::string &str){
        return acessor[str];
    }

    void execute_string(const std::string& command){
        auto command_parts = split(command, '=');

        auto steps = split(command_parts[0]);
        auto result = command_parts[1];

        *acessor[steps[0]][steps[1]] = result;
    }

    void drop_acessor(){
        acessor = {};
    }

    void execute_button(int button_number){
        for(const auto &e :saved_event["buttons"][button_number - 1]["event"])
            execute_string(e);
    }

};

#endif