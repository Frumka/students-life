// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_EVENT_PROCESSOR_HPP_
#define INCLUDE_EVENT_PROCESSOR_HPP_

#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace event_parser_tools {
    bool is_inside(const std::string &main, const std::string &sub) {
        return (main.find(sub) != std::string::npos);
    }

    std::vector<std::string> split(const std::string& s, const std::string& delimiter = ".") {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
            token = s.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (s.substr (pos_start));
        return res;
    }
}

using namespace event_parser_tools;

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

    void load_event(const std::string& path){
        std::ifstream text_stream(path);
        text_stream >> saved_event;
    }

    std::map<std::string, std::string*> operator[](const std::string &str){
        return acessor[str];
    }

    const void execute_string(const std::string& command){
        std::string operation;

        if(is_inside(command, "+="))
            operation = "+=";
        else if(is_inside(command, "-="))
            operation = "-=";
        else if(is_inside(command, "="))
            operation = "just =";
        else
            throw std::invalid_argument("bad string event given: '" + command + "' , no '=' sign detected");

        if(operation == "just =") {
            auto command_parts = split(command, "=");

            auto steps = split(command_parts[0]);
            auto result = command_parts[1];

            *acessor[steps[0]][steps[1]] = result;
            return;
        }
        else{
            auto command_parts = split(command, operation);

            auto steps = split(command_parts[0]);

            double result = std::stod(*acessor[steps[0]][steps[1]]); // previous value

            if(operation == "+=")
                result += std::stod(command_parts[1]);
            else
                result -= std::stod(command_parts[1]);

            *acessor[steps[0]][steps[1]] = std::to_string(result);
            return;
        }
    }

    void execute_button(int button_number){
        std::cout << saved_event << std::endl;
        std::cout <<"text: " <<saved_event["buttons"][button_number]["text"];
        std::cout << 2 << std::endl;
        std::cout <<"text: " <<saved_event["buttons"][button_number]["event"];
        for(const auto &e :saved_event["buttons"][button_number]["event"]) {
            std::cout <<"text: " <<saved_event["buttons"][button_number]["text"];
            std::cout <<"text: " <<saved_event["buttons"][button_number]["event"];
            execute_string(e);
        }
    }

};

#endif