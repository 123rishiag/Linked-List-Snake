#pragma once
#include<SFML/Graphics.hpp>
#include "../header/LinkedList/SingleLinkedList.h"

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;

		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;

		const float movement_frame_duration = 0.1f;
		float elapsed_duration;

		SnakeState current_snake_state;
		Direction current_snake_direction;

		LinkedList::SingleLinkedList* single_linked_list;

		void createLinkedList();
		void processPlayerInput();
		void updateSnakeDirection();
		void delayedUpdate();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();
		void respawnSnake();

		SnakeState getSnakeState() const;
		void setSnakeState(SnakeState state);
	};
}