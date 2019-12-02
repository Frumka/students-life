// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <fstream>
using json = nlohmann::json;

#include <event_processor.hpp>


class prepod{
private:
    std::string mark = "2";
    std::string name;

public:
    std::map<std::string, std::string*> acessor = {
            {"mark", &mark},
            {"name", &name}
    };

    std::string checkit(){
        return mark;
    }
};

TEST(event_processor_tools, split){
    std::string test0 = "hate.this.task";
    std::vector<std::string> res0 = {"hate", "this", "task"};
    EXPECT_EQ(event_parser_tools::split(test0), res0);

    std::string test1 = "split me pls";
    std::vector<std::string> res1 = {"split", "me", "pls"};
    EXPECT_EQ(event_parser_tools::split(test1, " "), res1);

    std::string test2 = "kill_me_pls";
    std::vector<std::string> res2 = {"kill", "pls"};
    EXPECT_EQ(event_parser_tools::split(test2, "_me_"), res2);
}

TEST(event_processor_tools, is_inside){
    EXPECT_TRUE(event_parser_tools::is_inside("hereis.dot", "."));

    EXPECT_FALSE(event_parser_tools::is_inside("noExclamHere... Sad -_-" , "!"));

    EXPECT_TRUE(event_parser_tools::is_inside("Close += example", "+="));

    EXPECT_FALSE(event_parser_tools::is_inside("Even = closer", "+="));
}

TEST(event_processor, constructor){
    prepod Aliev, Konova;

    std::map<std::string, std::map<std::string, std::string*>> acessor = {
            {"Aliev", Aliev.acessor},
            {"Konova", Konova.acessor},
    };

    event_processor processor(acessor);
    EXPECT_EQ(Aliev.checkit(), "2");

    *acessor["Aliev"]["mark"]="5";
    EXPECT_EQ(Aliev.checkit(), "5");

    *processor.acessor["Aliev"]["mark"] = "4";
    EXPECT_EQ(Aliev.checkit(), "4");

    *processor["Aliev"]["mark"] = "NA EKZ";
    EXPECT_EQ(Aliev.checkit(), "NA EKZ");
}


TEST(event_processor, string_execution_set){
    prepod Aliev, Konova;

    std::map<std::string, std::map<std::string, std::string*>> acessor = {
            {"Aliev", Aliev.acessor},
            {"Konova", Konova.acessor},
    };

    EXPECT_EQ(Aliev.checkit(), "2");

    event_processor processor;
    processor.link_acessor(acessor);

    processor.execute_string("Aliev.mark=5");

    EXPECT_EQ(Aliev.checkit(), "5");

    *acessor["Aliev"]["mark"]="2";

    EXPECT_EQ(Aliev.checkit(), "2");

}

TEST(event_processor, string_execution_add_substract){
    prepod Aliev, Konova;

    std::map<std::string, std::map<std::string, std::string*>> acessor = {
            {"Aliev", Aliev.acessor},
            {"Konova", Konova.acessor},
    };

    EXPECT_EQ(Aliev.checkit(), "2");

    event_processor processor;
    processor.link_acessor(acessor);

    processor.execute_string("Aliev.mark+=5");

    EXPECT_EQ(std::stod(Aliev.checkit()), 7);

    processor.execute_string("Aliev.mark-=2");

    EXPECT_EQ(std::stod(Aliev.checkit()), 5);

}

TEST(event_processor, file_single_comand){
    prepod Aliev, Konova;

    std::map<std::string, std::map<std::string, std::string*>> acessor = {
            {"Aliev", Aliev.acessor},
            {"Konova", Konova.acessor},
    };

    EXPECT_EQ(Aliev.checkit(), "2");

    event_processor processor;
    processor.link_acessor(acessor);
    processor.load_event("./tests/test_event.json");

    processor.execute_button(2);

    EXPECT_EQ(Aliev.checkit(), "AA");
}

TEST(event_processor, file_multiple_comands){
    prepod Aliev, Konova;

    std::map<std::string, std::map<std::string, std::string*>> acessor = {
            {"Aliev", Aliev.acessor},
            {"Konova", Konova.acessor},
    };

    EXPECT_EQ(Aliev.checkit(), "2");
    EXPECT_EQ(Konova.checkit(), "2");

    event_processor processor;
    processor.link_acessor(acessor);
    processor.load_event("./tests/test_event.json");

    processor.execute_button(1);

    EXPECT_EQ(Aliev.checkit(), "A");
    EXPECT_EQ(Konova.checkit(), "K");
}

TEST(event_processor, load_event){
    event_processor processor;
    processor.load_event("./tests/test_event.json");

    EXPECT_EQ(processor.saved_event["text"], "Текст - описание события");
    EXPECT_EQ(processor.saved_event["button_count"], 4);
}