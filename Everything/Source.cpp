#include "Head.h"
#include "Draw_windows.h"
#include "Window.h"
#include "Button.h"
using namespace sf;



int main()
{
	extern sf::RenderWindow window;
	//создание меню
	Background main_men("images/main_menu_back.png");
	Button new_game("images/Button_new_game.png", 738, 216);
	main_men.push_button(new_game);
	Button continue_game("images/Button_continue.png", 738, 437);
	main_men.push_button(continue_game);
	Button quite("images/Button_leave.png", 738, 670);
	main_men.push_button(quite);
	main_men.set_status(true);


	//создание главного окна
	Background main_game("images/main.png");
	Button charector_b("images/C_button.png", 192, 861);
	main_game.push_button(charector_b);
	Button shop_b("images/shop_b.png", 505 , 861);
	main_game.push_button(shop_b);
	Button u_b("images/u_b.png", 810, 861);
	main_game.push_button(u_b);
	Button job_b("images/job_b.png", 1141, 861);
	main_game.push_button(job_b);
	Button reletions("images/reletions_b.png", 1493, 861);
	main_game.push_button(reletions);
	Button settings_b("images/settings_b.png", 1717, 606);
	main_game.push_button(settings_b);
	main_game.set_status(false);
	std::map<Background, bool> Active_window;
	Active_window[main_game]=main_game.get_status();
	Active_window[main_men] = main_men.get_status();


	while (window.isOpen())
	{
		Background active_window;
		if (Active_window[main_men])
		{ 
			std::cout << Active_window[main_men];
			std::cout << Active_window[main_game];
			active_window = main_men;
			main_men.draw(window);
			if (new_game.is_click())
			{
				Active_window[main_game] = true;
				Active_window[main_men] = false;
			}
			if (continue_game.is_click())
			{

			}
			if (quite.is_click())
			{
				button_extit();
			}
		}
		if (Active_window[main_game])
		{
			Active_window[active_window] = false;
			active_window = main_game;
			main_game.draw(window);
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			// "запрос закрытия" событие: мы закрываем окно
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (event.key.code == sf::Keyboard::Escape)
		{
			//std::cout << "ESQ";
			Active_window[active_window] = false;
			Active_window[main_men] = true;
		}
		window.display();
	}
	return 0;
}