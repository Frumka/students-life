//
// Created by atrum on 08.12.19.
//

#ifndef STUDENT_LIFE_MAIN_EVENTCALLER_HPP
#define STUDENT_LIFE_MAIN_EVENTCALLER_HPP

#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include <random>

using json = nlohmann::json;

class EventCaller {
private:
    std::string next_event = "0";
    
    std::vector<std::pair<std::string, bool>> event_paths;
    json event_list;

    uint64_t event_number;

    std::string choose_from_available(int max_tries = 10) {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> rand(0, event_number - 1);

        ///tries to randomly choose available event
        for (int tries = 0; tries < max_tries; tries++) {
            int randed = rand(rng);
            auto element = event_paths[randed];
            if (element.second) {
                return element.first;
            }
        }

        ///tries to take first available event
        for (const auto &e:event_paths) {
            if (e.second)
                return e.first;
        }

        ///tries to  randomly choose not unique event
        for (int tries = 0; tries < max_tries; tries++) {
            auto element = event_paths[rand(rng)];
            if (!is_event_unique(element.first))
                return element.first;
        }

        ///tries to take first not unique event
        for (const auto &e:event_paths) {
            if (!is_event_unique(e.first))
                return e.first;
        }

        ///finally takes random event
        return event_paths[rand(rng)].first;
    }

    void update_paths() {
        int i = 0;
        for (auto it = event_list.begin(); it != event_list.end(); it++) {
            event_paths[i++] = std::pair<std::string, bool>(it.key(), it.value());
        }
    }

    EventCaller() = default;

    ~EventCaller() = default;

public:
    EventCaller(const EventCaller &) = delete;

    EventCaller &operator=(EventCaller &) = delete;

    static EventCaller &getInstance() {
        static EventCaller instance;
        return instance;
    }
    
    void set_next(const std::string &path){
        next_event = path;
    }

    void update_EventList(const std::string &key, bool is_available){
        if(key != "none"){
            event_list[key] = is_available;
            for(auto& e: event_paths){
                if(e.first == key)
                    e.second = is_available;
            }
        }
    }

    void set_EventList(const std::string &path_to_EventList = "json_events/EventList.json") {
        std::ifstream ifs(path_to_EventList);
        event_list = json::parse(ifs);
        event_number = event_list.size();

        //std::cerr<<"On set: "<<std::setw(4)<<event_list<<std::endl;

        event_paths.resize(event_number);

        update_paths();
    }

    std::string choose_random_event(int max_tries = 10) {
        if(next_event != "0"){
            std::string res = next_event;
            next_event = "0";
            return res;
        }
        
        std::string path_to_event = choose_from_available(max_tries);

        std::ifstream ds(path_to_event);
        json event = json::parse(ds);

        if(event["is_unique"]){
            for(auto& e: event_paths){
                if(e.first == path_to_event)
                    e.second = false;
            }
        }

        return path_to_event;
    }

    static bool is_event_unique(const std::string &path) {
        std::ifstream ifs(path);
        json event = json::parse(ifs);
        return event["is_unique"];
    }
};

#endif //STUDENT_LIFE_MAIN_EVENTCALLER_HPP
