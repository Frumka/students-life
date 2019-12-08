#include "Head.h"
#include <thread>
#include <iomanip>
#include "new_job.h"
#include "Settings.h"
#include "Shop.h"
#include "prepods.hpp"
#include "event_window.hpp"
#include "Relations.h"


Background shop("images/main_back.png");
Background nastroyki("images/main_back.png");

Sprite price;
Sprite riska2;
//Sprite riska2;

<<<<<<< HEAD
int main()
{

	Texture risq;
	risq.loadFromFile("images/riska2.png");
	riska2.setTexture(risq);
	


	Player player;

	///testovie prepodi
	prepod A("Aname", "Amark"), K("Kname", "Kmark");

	std::map<std::string, std::map<std::string, std::string*>> acessor = {
			{"A",      A.acessor},
			{"K",      K.acessor},
			{"player", player.acessor}
	};
	event_processor processor;
	processor.link_acessor(acessor);
	processor.load_event("json_events/testing_event.json");
	//std::cout<<std::setw(4)<<processor.saved_event;
	EventWindow ivent(processor);
	///end of test block
	Texture p;
	
	p.loadFromFile("images/price.png");
	p.setSmooth(true);
	price.setTexture(p);
	extern sf::RenderWindow window;
	window.setKeyRepeatEnabled(true);
	Background main_men("images/main_menu_back.png");
	Button new_game("images/Button_new_game.png", 738, 216, Color::Cyan);
	main_men.push_button(new_game);
	Button continue_game("images/Button_continue.png", 738, 437, Color::Cyan);
	main_men.push_button(continue_game);
	Button quite("images/Button_leave.png", 738, 670, Color::Cyan);
	main_men.push_button(quite);
	main_men.set_status(true);

	Background main_game("images/main.png");
	Button charector_b("images/character_b.png", 192, 910, Color::Cyan);
	main_game.push_button(charector_b);
	Button shop_b("images/shop_b.png", 510, 910, Color::Cyan);
	main_game.push_button(shop_b);
	Button u_b("images/success_b.png", 840, 910, Color::Cyan);
	main_game.push_button(u_b);
	Button job_b("images/job_b.png", 1170, 910, Color::Cyan);
	main_game.push_button(job_b);
	Button reletions("images/relations_b.png", 1493, 910, Color::Cyan);
	main_game.push_button(reletions);
	Button settings_b("images/settings_b.png", 1600, 606, Color::Cyan);
	main_game.push_button(settings_b);
	main_game.set_status(false);

	extern std::vector<product*> products;
	product burger_(500, 30, 20);
	products.push_back(&burger_);
	product pizza_(500, 30, 20);
	products.push_back(&pizza_);
	product coke_(500, 30, 20);
	products.push_back(&coke_);
	product shirt_(500, 30, 20);
	products.push_back(&shirt_);
	product shorts_(2000, 30, 20);
	products.push_back(&shorts_);
	product boots_(500, 30, 20);
	products.push_back(&boots_);
	product headphones_(500, 30, 20);
	products.push_back(&headphones_);
	product phone_(500, 30, 20);
	products.push_back(&phone_);
	product flash_(500, 30, 20);
	products.push_back(&flash_);

	shop.push_sprite("images/Shop_back.png", 342, 184);

	Button burger("images/burger.png", 788, 271, Color(255,255,0,255));
	shop.push_button(burger);
	Button pizza("images/pizza.png", 1053, 271, Color(255, 255, 0, 255));
	shop.push_button(pizza);
	Button coke("images/coke.png", 1310, 271, Color::Red);
	shop.push_button(coke);
	Button shirt("images/shirt.png", 788, 470, Color::Red);
	shop.push_button(shirt);
	Button shorts("images/shorts.png", 1053, 470, Color::Magenta);
	shop.push_button(shorts);
	Button boots("images/boots.png", 1310, 470, Color::Cyan);
	shop.push_button(boots);

	Button headphones("images/headphones.png", 788, 668, Color::Cyan);
	shop.push_button(headphones);
	Button phone("images/phone.png", 1053, 668, Color::Cyan);
	shop.push_button(phone);
	Button flash("images/flash.png", 1310, 668, Color::Cyan);
	shop.push_button(flash);


	Background Otnoshenia("images/main_back.png");
	Otnoshenia.push_sprite("images/relations.png", 342, 184);

	Background Charecter("images/main_back.png");
	Charecter.push_sprite("images/character.png", 342, 184);


	nastroyki.push_sprite("images/settings.png", 342, 184);
	Button left("images/nastoiky_left.png", 822, 573 + 184, Color::Cyan);
	Button right("images/nastroiky_right.png", 996 + 342, 573 + 184, Color::Cyan);
	nastroyki.push_button(left);
	nastroyki.push_button(right);

	bool* active_window;
	active_window = &main_men.is_active;

	//Music music;
	//music.openFromFile("music/1565802332_antoha-ms-tokye.ogg");
	//music.play();
	//music.setVolume(0);


	Background job("images/main_back.png");
	job.push_sprite("images/game_page_1.png", 342, 184);
	Button job_start("images/start_job_button.png", 745, 550, Color::Cyan);
	job.push_button(job_start);

	Background game("images/ivent.png");

	int set_volume = 50;
	Texture ris;
	ris.loadFromFile("images/riska.png");
	Sprite riska;
	riska.setTexture(ris);

	int complexity = 0;


	while (window.isOpen())
	{
		/*if (ivent)
		{
			ivent.draw(window);
			draw_ivent(window, s, 800, 450, 280, 30, Color::Black);
		}*/
		sf::Event event;
		window.pollEvent(event);
		if (job)
		{
			job.draw(window);
			if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					continue;
				}
				std::cout << "rofl";
				*active_window = false;
				active_window = &main_game.is_active;
				*active_window = true;
			}
			if (job_start.is_click())
			{
				//game.draw(window);
				player.set_money(mont(player));
				/**active_window = false;
				active_window = &main_game.is_active;
				*active_window = true;
				continue;*/
			}
			if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					continue;
				}
				std::cout << "rofl";
				*active_window = false;
				active_window = &main_game.is_active;
				*active_window = true;
			}
			/*if (!(IntRect(334, 132, 800, 500).contains(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					continue;
				}
				std::cout << "rofl";
				*active_window = false;
				active_window = &main_game.is_active;
				*active_window = true;
			}*/
			//	jump();
				/**active_window = false;
				active_window = &main_game.is_active;
				*active_window = true;*/
		}
		if (main_men)
		{

			main_men.draw(window);
				if (new_game.is_click())
				{
					*active_window = false;
					active_window = &ivent.is_active;
					*active_window = true;
				}
			if (continue_game.is_click())
			{
				*active_window = false;
				active_window = &main_game.is_active;
				*active_window = true;
			}
			if (quite.is_click())
			{
				button_extit();
			}
		}
		if (main_game)
		{
			main_game.draw(window);
			draw_money(window, player);
			draw_health(window, player);
			draw_mood(window, player);
			if (shop_b.is_click())
			{
				*active_window = false;
				active_window = &shop.is_active;
				*active_window = true;
			}
			if (settings_b.is_click())
			{
				*active_window = false;
				active_window = &nastroyki.is_active;
				*active_window = true;
			}
			if (charector_b.is_click())
			{
				*active_window = false;
				active_window = &Charecter.is_active;
				*active_window = true;
			}
			if (reletions.is_click())
			{
				*active_window = false;
				active_window = &Otnoshenia.is_active;
				*active_window = true;
			}
			if (job_b.is_click())
			{
				*active_window = false;
				active_window = &job.is_active;
				*active_window = true;
			}

		}
		if (ivent){
			ivent.draw(window);
			draw_money(window, player);
			draw_health(window, player);
			draw_mood(window, player);
			std::cout<<"A.mark = "<<A.mark<< std::endl;
			std::cout<<"A.name = "<<A.name<< std::endl;
			for(auto e: ivent.buttons){
				if(e.is_click()){
					e.execute();
					*active_window = false;
					active_window = &main_game.is_active;
					*active_window = true;
				}
			}
		}

		if (shop)
		{
			draw_shop(player);
			draw_money(window, player);
			draw_health(window, player);
			draw_mood(window, player);
			if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					continue;
				}
				std::cout << "rofl";
				*active_window = false;
				active_window = &main_game.is_active;
				*active_window = true;
			}
		}
		if (Otnoshenia)
		{
			Otnoshenia.draw(window);
			draw_money(window, player);
			draw_health(window, player);
			draw_mood(window, player);
			draw_relations(window,100, 100, 100);
			if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					continue;
				}
				std::cout << "rofl";
				*active_window = false;
				active_window = &main_game.is_active;
				*active_window = true;
			}
		}

		if (Charecter)
		{
			Charecter.draw(window);
			draw_money(window, player);
			draw_health(window, player);
			draw_mood(window, player);
			if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					continue;
				}
				std::cout << "rofl";
				*active_window = false;
				active_window = &main_game.is_active;
				*active_window = true;
			}
		}
		if (nastroyki)
		{
			nastroyki.draw(window);
			sound_volume(350, riska, set_volume);
			//sound_volume(525, riska, set_volume);
			draw_money(window, player);
			draw_health(window, player);
			draw_mood(window, player);
			Complexity(window, complexity);
			if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					continue;
				}
				std::cout << "rofl";
				*active_window = false;
				active_window = &main_game.is_active;
				*active_window = true;
			}
		}

		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == event.KeyPressed && event.key.code == Keyboard::Escape)
		{
			std::cout << "Danya privet";
			*active_window = false;
			active_window = &main_men.is_active;
			*active_window = true;
		}


		window.display();
	}
	return 0;
=======
int main() {
    Player player;

    ///testovie prepodi
    prepod A("Aname", "Amark"), K("Kname", "Kmark");

    std::map<std::string, std::map<std::string, std::string *>> acessor = {
            {"A",      A.acessor},
            {"K",      K.acessor},
            {"player", player.acessor}
    };
    event_processor processor;
    processor.link_acessor(acessor);
    processor.load_event("json_events/testing_event.json");

    EventWindow ivent(processor);
    ///end of test block

    com.emplace_back("   Легко");
    com.emplace_back("   Норма");
    com.emplace_back("Студент");

    Texture p;
    p.loadFromFile("images/price.png");
    p.setSmooth(true);
    price.setTexture(p);

    extern sf::RenderWindow window;
    window.setKeyRepeatEnabled(true);

    Background main_men("images/main_menu_back.png");
    Button new_game("images/Button_new_game.png", 738, 216, Color::Cyan);
    main_men.push_button(new_game);
    Button continue_game("images/Button_continue.png", 738, 437, Color::Cyan);
    main_men.push_button(continue_game);
    Button quite("images/Button_leave.png", 738, 670, Color::Cyan);
    main_men.push_button(quite);
    main_men.set_status(true);

    Background event_answer_bg("images/main_back.png");
    event_answer_bg.push_sprite("images/event_cg.png", 342, 184);

    Background main_game("images/main.png");
    Button charector_b("images/character_b.png", 192, 910, Color::Cyan);
    main_game.push_button(charector_b);
    Button shop_b("images/shop_b.png", 510, 910, Color::Cyan);
    main_game.push_button(shop_b);
    Button u_b("images/success_b.png", 840, 910, Color::Cyan);
    main_game.push_button(u_b);
    Button job_b("images/job_b.png", 1170, 910, Color::Cyan);
    main_game.push_button(job_b);
    Button reletions("images/relations_b.png", 1493, 910, Color::Cyan);
    main_game.push_button(reletions);
    Button settings_b("images/settings_b.png", 1600, 606, Color::Cyan);
    main_game.push_button(settings_b);
    main_game.set_status(false);

    extern std::vector<product *> products;
    product burger_(500, 30, 20);
    products.push_back(&burger_);
    product pizza_(500, 30, 20);
    products.push_back(&pizza_);
    product coke_(500, 30, 20);
    products.push_back(&coke_);
    product shirt_(500, 30, 20);
    products.push_back(&shirt_);
    product shorts_(2000, 30, 20);
    products.push_back(&shorts_);
    product boots_(500, 30, 20);
    products.push_back(&boots_);
    product headphones_(500, 30, 20);
    products.push_back(&headphones_);
    product phone_(500, 30, 20);
    products.push_back(&phone_);
    product flash_(500, 30, 20);
    products.push_back(&flash_);

    shop.push_sprite("images/Shop_back.png", 342, 184);

    Button burger("images/burger.png", 788, 271, Color(255, 255, 0, 255));
    shop.push_button(burger);
    Button pizza("images/pizza.png", 1053, 271, Color(255, 255, 0, 255));
    shop.push_button(pizza);
    Button coke("images/coke.png", 1310, 271, Color::Red);
    shop.push_button(coke);

    Button shirt("images/shirt.png", 788, 470, Color::Red);
    shop.push_button(shirt);
    Button shorts("images/shorts.png", 1053, 470, Color::Magenta);
    shop.push_button(shorts);
    Button boots("images/boots.png", 1310, 470, Color::Cyan);
    shop.push_button(boots);

    Button headphones("images/headphones.png", 788, 668, Color::Cyan);
    shop.push_button(headphones);
    Button phone("images/phone.png", 1053, 668, Color::Cyan);
    shop.push_button(phone);
    Button flash("images/flash.png", 1310, 668, Color::Cyan);
    shop.push_button(flash);


    Background Otnoshenia("images/main_back.png");
    Otnoshenia.push_sprite("images/relations.png", 342, 184);

    Background Charecter("images/main_back.png");
    Charecter.push_sprite("images/character.png", 342, 184);


    nastroyki.push_sprite("images/settings.png", 342, 184);
    Button left("images/nastoiky_left.png", 822, 573 + 184, Color::Cyan);
    Button right("images/nastroiky_right.png", 996 + 342, 573 + 184, Color::Cyan);
    nastroyki.push_button(left);
    nastroyki.push_button(right);

    bool *active_window;
    active_window = &main_men.is_active;

    //Music music;
    //music.openFromFile("music/1565802332_antoha-ms-tokye.ogg");
    //music.play();
    //music.setVolume(0);


    Background job("images/Job_back.png");
    Button job_start("images/start_job_button.png", 745, 550, Color::Cyan);
    job.push_button(job_start);

    Background game("images/ivent.png");

    int set_volume = 50;
    Texture ris;
    ris.loadFromFile("images/riska.png");
    Sprite riska;
    riska.setTexture(ris);

    int complexity = 0;


    event_button last_pressed_button;
    EventWindow last_active_event;

    while (window.isOpen()) {
        /*if (ivent)
        {
            ivent.draw(window);
            draw_ivent(window, s, 800, 450, 280, 30, Color::Black);
        }*/
        sf::Event event;
        window.pollEvent(event);
        if (job) {
            job.draw(window);
            if (job_start.is_click()) {
                //game.draw(window);
                player.set_money(mont(player));
                /**active_window = false;
                active_window = &main_game.is_active;
                *active_window = true;
                continue;*/
            }
            /*if (!(IntRect(334, 132, 800, 500).contains(Mouse::getPosition(window))) && Mouse::isButtonPressed(Mouse::Left))
            {
                while (Mouse::isButtonPressed(Mouse::Left))
                {
                    continue;
                }
                std::cout << "rofl";
                *active_window = false;
                active_window = &main_game.is_active;
                *active_window = true;
            }*/
            //	jump();
            /**active_window = false;
            active_window = &main_game.is_active;
            *active_window = true;*/
        }
        if (main_men) {

            main_men.draw(window);
            if (new_game.is_click()) {
                *active_window = false;
                active_window = &ivent.is_active;
                *active_window = true;
            }
            if (continue_game.is_click()) {
                *active_window = false;
                active_window = &main_game.is_active;
                *active_window = true;
            }
            if (quite.is_click()) {
                button_extit();
            }
        }
        if (main_game) {
            main_game.draw(window);
            draw_money(window, player);
            draw_health(window, player);
            draw_mood(window, player);
            if (shop_b.is_click()) {
                *active_window = false;
                active_window = &shop.is_active;
                *active_window = true;
            }
            if (settings_b.is_click()) {
                *active_window = false;
                active_window = &nastroyki.is_active;
                *active_window = true;
            }
            if (charector_b.is_click()) {
                *active_window = false;
                active_window = &Charecter.is_active;
                *active_window = true;
            }
            if (reletions.is_click()) {
                *active_window = false;
                active_window = &Otnoshenia.is_active;
                *active_window = true;
            }
            if (job_b.is_click()) {
                *active_window = false;
                active_window = &job.is_active;
                *active_window = true;
            }

        }
        if (ivent) {
            ivent.draw(window);
            draw_money(window, player);
            draw_health(window, player);
            draw_mood(window, player);

            for (auto e: ivent.buttons) {
                if (e.is_click()) {
                    e.execute();

                    last_pressed_button = e;
                    last_active_event = ivent;

                    *active_window = false;
                    active_window = &event_answer_bg.is_active;
                    *active_window = true;
                }
            }
        }

        if (event_answer_bg) {
            event_answer_bg.draw(window);

            draw_money(window, player);
            draw_health(window, player);
            draw_mood(window, player);

            last_active_event.title_print(window);
            last_pressed_button.text_prettyprint(window);

            if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) &&
                Mouse::isButtonPressed(Mouse::Left)) {
                while (Mouse::isButtonPressed(Mouse::Left)) {
                    continue;
                }

                *active_window = false;
                active_window = &main_game.is_active;
                *active_window = true;
            }

        }

        if (shop) {
            draw_shop(player);
            draw_money(window, player);
            draw_health(window, player);
            draw_mood(window, player);
            if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) &&
                Mouse::isButtonPressed(Mouse::Left)) {
                while (Mouse::isButtonPressed(Mouse::Left)) {
                    continue;
                }
                *active_window = false;
                active_window = &main_game.is_active;
                *active_window = true;
            }
        }
        if (Otnoshenia) {
            Otnoshenia.draw(window);
            draw_money(window, player);
            draw_health(window, player);
            draw_mood(window, player);
            if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) &&
                Mouse::isButtonPressed(Mouse::Left)) {
                while (Mouse::isButtonPressed(Mouse::Left)) {
                    continue;
                }
                *active_window = false;
                active_window = &main_game.is_active;
                *active_window = true;
            }
        }

        if (Charecter) {
            Charecter.draw(window);
            draw_money(window, player);
            draw_health(window, player);
            draw_mood(window, player);
            if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) &&
                Mouse::isButtonPressed(Mouse::Left)) {
                while (Mouse::isButtonPressed(Mouse::Left)) {
                    continue;
                }
                *active_window = false;
                active_window = &main_game.is_active;
                *active_window = true;
            }
        }
        if (nastroyki) {
            nastroyki.draw(window);
            sound_volume(350, riska, set_volume);
            //sound_volume(525, riska, set_volume);
            draw_money(window, player);
            draw_health(window, player);
            draw_mood(window, player);
            Complexity(window, complexity);
            if (!(IntRect(342 * x, 184 * y, 1231 * x, 707 * y).contains(Mouse::getPosition(window))) &&
                Mouse::isButtonPressed(Mouse::Left)) {
                while (Mouse::isButtonPressed(Mouse::Left)) {
                    continue;
                }
                *active_window = false;
                active_window = &main_game.is_active;
                *active_window = true;
            }
        }

        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == event.KeyPressed && event.key.code == Keyboard::Escape) {
            *active_window = false;
            active_window = &main_men.is_active;
            *active_window = true;
        }


        window.display();
    }
    return 0;
>>>>>>> ee4b0817cd57135e1ea08debefe6ffe5a9f725b9
}