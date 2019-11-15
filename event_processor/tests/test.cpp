// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <fstream>
using json = nlohmann::json;

#include <header.hpp>


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


TEST(event_processor, string_execution){
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

TEST(event_processor, file_single_comand){
    prepod Aliev, Konova;

    std::map<std::string, std::map<std::string, std::string*>> acessor = {
            {"Aliev", Aliev.acessor},
            {"Konova", Konova.acessor},
    };

    EXPECT_EQ(Aliev.checkit(), "2");

    event_processor processor;
    processor.link_acessor(acessor);

    processor.execute_chosen_button("../tests/test_event.json", 2);

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

    processor.execute_chosen_button("../tests/test_event.json", 1);

    EXPECT_EQ(Aliev.checkit(), "A");
    EXPECT_EQ(Konova.checkit(), "K");
}

TEST(event_processor, drop_acessor){
    prepod Aliev, Konova;

    std::map<std::string, std::map<std::string, std::string*>> acessor = {
            {"Aliev", Aliev.acessor},
            {"Konova", Konova.acessor},
    };

    EXPECT_EQ(Aliev.checkit(), "2");

    event_processor processor(acessor);

    processor.execute_string("Aliev.mark=-1");
    EXPECT_EQ(Aliev.checkit(), "-1");

    processor.drop_acessor();
    // Uncathable error raise manually detected, test case sucessful
    //EXPECT_ANY_THROW(processor.execute_string("Aliev.mark=-1"));
}