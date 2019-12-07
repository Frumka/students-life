//
// Created by atrum on 05.12.19.
//

#ifndef STUDENT_LIFE_MAIN_EVENT_WINDOW_HPP
#define STUDENT_LIFE_MAIN_EVENT_WINDOW_HPP

#include <event_processor.hpp>
#include "Button.h"
#include "Head.h"

class event_button : public Button{
private:
    std::function<void()> onclick_event;
    std::wstring button_description;
public:
    event_button(const std::string& image_path, float x, float y, std::function<void()> onclick,const std::wstring &button_text):
        Button::Button(image_path, x, y, Color::Cyan)
    {
        onclick_event = onclick;
        button_description = button_text;
    }

    void draw_with_text(RenderWindow& window, int order){
        draw(window);

        Font font;
        font.loadFromFile("CyrilicOld.TTF");
        Text button_text(button_description, font, 20);

        button_text.setPosition(480*x, (565 + 60 * order)*y);
        //button_text.setPosition(480, 565 + 60 * order);
        window.draw(button_text);
    }

    void execute(){
        onclick_event();
    }
};

class EventWindow{
private:
    std::string image_path = "images/ivent.png";
    sf::Texture texture;
    sf::Sprite sprite;


    std::string description;
    int button_count = 0;

public:
    std::vector<event_button> buttons;

    bool is_active = false;

    explicit EventWindow(event_processor &processor){
        texture.loadFromFile(image_path);
        sprite.setTexture(texture);
        sprite.scale(x, y);

        update(processor);
    }

    void update(event_processor& processor){
        button_count = processor.saved_event["button_count"];
        description = processor.saved_event["text"];
        for(int i = 0; i < button_count; i++){
            std::function<void()> onclick = [i, &processor](){
                processor.execute_button(i);
            };

            std::wstring message = str_to_wstr(processor.saved_event["buttons"][i]["text"]);

            buttons.emplace_back("images/EventButton.png", 470, 560 + 60*i,
                                 onclick, str_to_wstr(processor.saved_event["buttons"][i]["text"]));
        }
    }

    void draw(RenderWindow& window){
        window.draw(sprite);
        for(int i = 0; i<buttons.size(); i++){
            buttons[i].draw_with_text(window, i);
        }
    }

    operator bool() const
    {
        return is_active;
    }
};

#endif //STUDENT_LIFE_MAIN_EVENT_WINDOW_HPP
