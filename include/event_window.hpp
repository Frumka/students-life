//
// Created by atrum on 05.12.19.
//

#ifndef STUDENT_LIFE_MAIN_EVENT_WINDOW_HPP
#define STUDENT_LIFE_MAIN_EVENT_WINDOW_HPP

#include <event_processor.hpp>
#include "Button.h"
#include "Head.hpp"

class event_button : public Button {
private:
    std::function<void()> onclick_event;
    std::wstring button_description;
    std::string result_text;
    std::string path_to_activated = "none";
    
public:
    json button_json;

    event_button(const json &_button_json, float x, float y, std::function<void()> onclick, const std::wstring &button_text,
                 const std::string &_result_text, const std::string &path_to_activated) :
            Button::Button("images/EventButton.png", x, y, Color::Cyan) {
        button_json = _button_json;
        onclick_event = onclick;
        button_description = button_text;
        result_text = _result_text;
    }

    event_button() = default;

    event_button &operator=(const event_button &rhs) = default;

    void draw_with_text(RenderWindow &window, int order) {
        draw(window);

        Font font;
        font.loadFromFile("CyrilicOld.TTF");
        Text button_text(button_description, font, 25);

        button_text.setPosition(380 * x, (550 + 88 * order) * y);
        window.draw(button_text);
    }

    void draw(RenderWindow &window) {
        texture.loadFromFile("images/EventButton.png");
        sprite.setTexture(texture);

        sprite.setPosition(x_pos, y_pos);
        if (sprite.getGlobalBounds().contains((float) Mouse::getPosition().x, (float) Mouse::getPosition().y)) {
            sprite.setColor(button_color);
        } else
            sprite.setColor(Color::White);
        window.draw(sprite);
    }

    void text_prettyprint(RenderWindow &window, int size = 32) {
        std::string s = result_text;
        auto x_pos = 360;
        auto y_pos = 250;
        s += " ";
        size_t pos1 = 0;
        size_t pos2 = 0;
        std::vector<std::string> words;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                pos2 = i;
                words.push_back(s.substr(pos1, pos2 - pos1));
                pos1 = pos2;
            }
        }
        Font font;
        font.loadFromFile("CyrilicOld.TTF");
        Text text;
        text.setPosition(x * x_pos + 5, y * y_pos);
        text.setFont(font);
        text.setFillColor(Color::Black);
        std::string str = "";
        text.setCharacterSize(static_cast<unsigned int>(size * y));
        for (size_t i = 0; i < words.size(); i++) {
            str += words[i];
            if (text.getLocalBounds().width <= 1050 * x) {
                text.setString(str_to_wstr(str));
            } else {
                y_pos += (text.getCharacterSize() + 25) * y;
                window.draw(text);
                text.setString("");
                text.setPosition(x * x_pos, y * y_pos);
                str = words[i];
            }
        }
        window.draw(text);
    }

    std::string execute() {
        onclick_event();
        
        return path_to_activated;
    }
};

class EventWindow {
private:
    std::string bg_path = "images/main_back.png";
    sf::Texture bg_texture;
    sf::Sprite bg_sprite;

    std::string cg_path = "images/event_cg.png";
    sf::Texture cg_texture;
    sf::Sprite cg_sprite;


    std::string description;
    std::string title;
    int button_count = 0;

public:
    std::vector<event_button> buttons;

    bool is_active = false;

    EventWindow() {
        bg_texture.loadFromFile(bg_path);
        bg_sprite.setTexture(bg_texture);
        bg_sprite.scale(x, y);

        cg_texture.loadFromFile(cg_path);
        cg_sprite.setTexture(cg_texture);
        cg_sprite.scale(x, y);
        cg_sprite.setPosition(342 * x, 184 * y);
    };

    EventWindow &operator=(const EventWindow &rhs) = default;

    explicit EventWindow(event_processor &processor) : EventWindow() {
        update(processor);
    }

    void update(event_processor &processor) {
        button_count = processor.saved_event["button_count"];
        description = processor.saved_event["text"];
        title = processor.saved_event["title"];

        buttons.clear();

        for (int i = 0; i < button_count; i++) {
            std::function<void()> onclick = [i, &processor]() {
                processor.execute_button(i);
            };

            std::wstring message = str_to_wstr(processor.saved_event["buttons"][i]["text"]);

            buttons.emplace_back(processor.saved_event["buttons"][i], 360, 184 + 350 + 88 * i,
                                 onclick, str_to_wstr(processor.saved_event["buttons"][i]["text"]),
                                 processor.saved_event["buttons"][i]["result_text"],
                                 processor.saved_event["buttons"][i]["set_available_event"]);
        }
    }

    void title_print(RenderWindow &window) {
        Font font;
        font.loadFromFile("CyrilicOld.TTF");
        Text button_text(str_to_wstr(title), font, 40);

        button_text.setPosition(360 * x, 180 * y);
        window.draw(button_text);
    }

    void text_prettyprint(RenderWindow &window, int size = 32) {
        std::string s = description;
        auto x_pos = 360;
        auto y_pos = 250;
        s += " ";
        size_t pos1 = 0;
        size_t pos2 = 0;
        std::vector<std::string> words;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                pos2 = i;
                words.push_back(s.substr(pos1, pos2 - pos1));
                pos1 = pos2;
            }
        }
        Font font;
        font.loadFromFile("CyrilicOld.TTF");
        Text text;
        text.setPosition(x * x_pos + 5, y * y_pos);
        text.setFont(font);
        text.setFillColor(Color::Black);
        std::string str = "";
        text.setCharacterSize(static_cast<unsigned int>(size * y));
        for (size_t i = 0; i < words.size(); i++) {
            str += words[i];
            if (text.getLocalBounds().width <= 1050 * x) {
                text.setString(str_to_wstr(str));
            } else {
                y_pos += (text.getCharacterSize() + 25) * y;
                window.draw(text);
                text.setString("");
                text.setPosition(x * x_pos, y * y_pos);
                str = words[i];
            }
        }
        window.draw(text);
    }

    void draw(RenderWindow &window) {
        window.draw(bg_sprite);
        window.draw(cg_sprite);
        title_print(window);
        text_prettyprint(window);
        for (int i = 0; i < buttons.size(); i++) {
            buttons[i].draw_with_text(window, i);
        }
    }

    operator bool() const {
        return is_active;
    }
};

#endif //STUDENT_LIFE_MAIN_EVENT_WINDOW_HPP
