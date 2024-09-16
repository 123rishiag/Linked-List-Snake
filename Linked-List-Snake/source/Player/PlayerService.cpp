#include "../header/Player/PlayerService.h"
#include "../header/Player/SnakeController.h"

namespace Player
{
	using namespace Level;

	PlayerService::PlayerService()
	{
		snake_controller = nullptr;
		createController();
	}

	PlayerService::~PlayerService()
	{
		destroy();
	}
	
	void PlayerService::createController()
	{
		snake_controller = new SnakeController();
	}

	void PlayerService::initialize() 
	{
		snake_controller->initialize();
	}

	void PlayerService::update() 
	{ 
		snake_controller->update();
	}

	void PlayerService::render() 
	{
		snake_controller->render();
	}

	void PlayerService::spawnPlayer(LinkedListType linked_list_type)
	{
		snake_controller->createLinkedList(linked_list_type);
		snake_controller->spawnSnake();
	}

	std::vector<sf::Vector2i> PlayerService::getCurrentSnakePositionList() const
	{
		return snake_controller->getCurrentSnakePositionList();
	}
		
	int PlayerService::getPlayerScore() const
	{
		return snake_controller->getPlayerScore();
	}

	TimeComplexity PlayerService::getTimeComplexity() const
	{
		return snake_controller->getTimeComplexity();
	}

	LinkedListOperations PlayerService::getLastOperation() const
	{
		return snake_controller->getLastOperation();
	}

	bool PlayerService::isPlayerDead() const
	{
		return snake_controller->isSnakeDead();
	}

	bool PlayerService::isSnakeSizeMinimum() const
	{
		return snake_controller->isSnakeSizeMinimum();
	}

	void PlayerService::destroy()
	{
		delete(snake_controller);
	}
}