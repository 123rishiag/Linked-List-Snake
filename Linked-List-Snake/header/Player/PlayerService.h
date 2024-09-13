#pragma once
#include<SFML/Graphics.hpp>
#include<vector>

namespace Player
{
	enum class TimeComplexity;
	enum class LinkedListOperations;

	class SnakeController;

	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void createController();
		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer();

		std::vector<sf::Vector2i> getCurrentSnakePositionList() const;
		int getPlayerScore() const;
		TimeComplexity getTimeComplexity() const;
		LinkedListOperations getLastOperation() const;
	};
}