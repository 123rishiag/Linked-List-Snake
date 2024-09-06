#pragma once
#include <SFML/Graphics.hpp>

namespace Level
{
	class LevelView
	{
	private:
		const sf::Color background_color = sf::Color(180, 200, 160);

	public:
		LevelView();
		~LevelView();

		void initialize();
		void update();
		void render();
	};
}