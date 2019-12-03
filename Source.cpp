#include "Head.h"
#include <thread>
#include "new_job.h"
#include "Header.h"

int main()
{


	extern sf::RenderWindow window;
	window.setKeyRepeatEnabled(true);
	//�������� ����
	Background main_men("images/main_menu_back.png");
	Button new_game("images/Button_new_game.png", 738, 216);
	main_men.push_button(new_game);
	Button continue_game("images/Button_continue.png", 738, 437);
	main_men.push_button(continue_game);
	Button quite("images/Button_leave.png", 738, 670);
	main_men.push_button(quite);
	main_men.set_status(true);


	//�������� �������� ����
	Background main_game("images/main.png");
	Button charector_b("images/character_b.png", 192, 910);
	main_game.push_button(charector_b);
	Button shop_b("images/shop_b.png", 510, 910);
	main_game.push_button(shop_b);
	Button u_b("images/success_b.png", 840, 910);
	main_game.push_button(u_b);
	Button job_b("images/job_b.png", 1170, 910);
	main_game.push_button(job_b);
	Button reletions("images/relations_b.png", 1493, 910);
	main_game.push_button(reletions);
	Button settings_b("images/settings_b.png", 1600, 606);
	main_game.push_button(settings_b);
	main_game.set_status(false);

	/*Background ivent("images/ivent.png");
	//�������� �������� ����
	/*Background main_game("images/ivent.png");
	Button charector_b("images/C_button.png", 192, 910);
	main_game.push_button(charector_b);
	Button shop_b("images/shop_b.png", 505, 910);
	main_game.push_button(shop_b);
	Button u_b("images/u_b.png", 810, 910);
	main_game.push_button(u_b);
	Button job_b("images/job_b.png", 1141, 910);
	main_game.push_button(job_b);
	Button reletions("images/reletions_b.png", 1493, 910);
	main_game.push_button(reletions);
	Button settings_b("images/settings_b.png", 1717, 606);
	main_game.push_button(settings_b);
	main_game.set_status(false);*/

	//std::string s("�� ����� ���������, ��� ��� ��������� ���������� ���� � � ���� ���������� ����������� ������� � ��� ��������� ������������� ���, ������� �������� ������������ �����. ����� ������� ����� ������������� ��������� �������: ��� �������� ��� ��������� ������� � �������, ��������� �� ������������, � ������� ��������� ������������ ��� (���. 23). ���� ����� ����������� ��� ������� (��������, �� ����� ���������� ��� ���� ������� ������ ������) � ���� ������� ����� ���� ��������� � ���������� ����, �� ��� ��������� ��� ���������� ����� � ���� ������ ������� �� ������ ������� �������� ������������");


	Background shop("images/main_back.png");
	shop.push_sprite("images/shop.png", 342, 184);


	Background Otnoshenia("images/main_back.png");
	Otnoshenia.push_sprite("images/relations.png", 342, 184);

	Background Charecter("images/main_back.png");
	Charecter.push_sprite("images/character.png", 342, 184);


	Background nastroyki("images/main_back.png");
	nastroyki.push_sprite("images/settings.png", 342, 184);

	int money = 500;
	bool* active_window;
	active_window = &main_men.is_active;

	//Music music;
	//music.openFromFile("music/1565802332_antoha-ms-tokye.ogg");
	//music.play();
	//music.setVolume(0);


	Background job("images/Job_back.png");
	Button job_start("images/start_job_button.png", 745, 550);
	job.push_button(job_start);

	Background game("images/ivent.png");

	int set_volume = 50;
	Texture ris;
	ris.loadFromFile("images/riska.png");
	Sprite riska;
	riska.setTexture(ris);

	int health = 80;

	int mood = 30;
	/*auto j2 = R"(
  {
	"rabotaet?": "xuy",
	"pi": 3.141
  }
)"_json;
	json json_event;
	std::cout << j2["rabotaet?"];
	std::ifstream json_event_file("json_events/test_json.json");
	json_event = json::parse(json_event_file);
	std::cout << json_event["rabotaet?"];
	//std::cout << json_event_file.rdbuf();
	//json json_event = "{\"text\": \"RABOTAET!\"}"_json;
	//std::cout << json_event["text"];
	//json_event_file >> json_event;*/

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
			if (job_start.is_click())
			{
				//game.draw(window);
				money = mont();
				std::cout << money;
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
		if (main_men)
		{

			main_men.draw(window);
			/*	if (new_game.is_click())
				{
					*active_window = false;
					active_window = &ivent.is_active;
					*active_window = true;
				}*/
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
			draw_money(window, money);
			draw_health(window, health);
			draw_mood(window, mood);
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
		if (shop)
		{
			shop.draw(window);
			draw_money(window, money);
			draw_health(window, health);
			draw_mood(window, mood);
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
			draw_money(window, money);
			draw_health(window, health);
			draw_mood(window, mood);
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
			draw_money(window, money);
			draw_health(window, health);
			draw_mood(window, mood);
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
			sound_volume(525, riska, set_volume);
			draw_money(window, money);
			draw_health(window, health);
			draw_mood(window, mood);
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
}