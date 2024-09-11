#include "../header/Player/SnakeController.h"
#include "../header/Global/ServiceLocator.h"
#include "../header/Event/EventService.h"

namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace LinkedList;

	SnakeController::SnakeController() 
	{ 
		single_linked_list = nullptr;
		createLinkedList();
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::createLinkedList()
	{
		single_linked_list = new SingleLinkedList();
	}

	void SnakeController::initialize() 
	{ 
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		reset();

		single_linked_list->initialize(width, height, default_position, default_direction);
	}

	void SnakeController::update() 
	{ 
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			delayedUpdate();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render() 
	{ 
		single_linked_list->render();
	}

	void SnakeController::processPlayerInput() 
	{
		if (current_input_state == InputState::PROCESSING)
			return;

		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
			current_input_state = InputState::PROCESSING;
		}
	}

	void SnakeController::delayedUpdate()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.f;
			updateSnakeDirection();
			processSnakeCollision();
			if (current_snake_state != SnakeState::DEAD)
				moveSnake();
			
			current_input_state = InputState::WAITING;
		}
	}

	void SnakeController::updateSnakeDirection()
	{
		single_linked_list->updateNodeDirection(current_snake_direction);
	}

	void SnakeController::moveSnake() 
	{ 
		single_linked_list->updateNodePosition();
	}

	void SnakeController::processSnakeCollision()
	{
		if (single_linked_list->processNodeCollision())
		{
			current_snake_state = SnakeState::DEAD;
		}
	}

	void SnakeController::handleRestart() 
	{ 
		restart_counter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}

	void SnakeController::spawnSnake() 
	{ 
		// Insert nodes at tail to create the initial snake
		for (int i = 0; i < initial_snake_length; i++) 
		{
			single_linked_list->insertNodeAtTail();     
		}
	}

	void SnakeController::respawnSnake() 
	{
		single_linked_list->removeAllNodes();
		reset();
		spawnSnake();
	}

	SnakeState SnakeController::getSnakeState() const
	{
		return current_snake_state;
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	std::vector<sf::Vector2i> SnakeController::getCurrentSnakePositionList() const
	{
		return single_linked_list->getNodesPositionList();
	}

	void SnakeController::reset() 
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;
		elapsed_duration = 0.f;
		restart_counter = 0.f;
		current_input_state = InputState::WAITING;
	}

	void SnakeController::destroy() 
	{ 
		delete(single_linked_list);
	}

}