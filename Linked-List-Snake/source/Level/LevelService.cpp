#include "../header/Level/LevelService.h"
#include "../header/Level/LevelController.h"
#include "../header/Global/ServiceLocator.h"

namespace Level
{
	using namespace Global;
	using namespace Element;

	LevelService::LevelService()
	{
		level_controller = nullptr;
		level_controller = new LevelController();
	}

	LevelService::~LevelService()
	{
		destroy();
	}

	void LevelService::initialize() 
	{ 
		level_controller->initialize();
	}

	void LevelService::update() 
	{ 
		level_controller->update();
	}

	void LevelService::render() 
	{ 
		level_controller->render();
	}

	void LevelService::spawnLevelElements(LevelNumber level_to_load)
	{
		float cell_width = level_controller->getCellWidth();
		float cell_height = level_controller->getCellHeight();

		std::vector<ElementData> element_data_list = level_controller->getElementDataList((int)level_to_load);
		ServiceLocator::getInstance()->getElementService()->spawnElements(element_data_list, cell_width, cell_height);
	}

	void LevelService::spawnFood()
	{
		ServiceLocator::getInstance()->getFoodService()->startFoodSpawning();
	}

	void LevelService::spawnPlayer()
	{
		ServiceLocator::getInstance()->getPlayerService()->spawnPlayer(current_linked_list_type);
	}

	void LevelService::createLevel(LinkedListType linked_list_type)
	{
		current_linked_list_type = linked_list_type;
		spawnLevelElements(current_level);
		spawnFood();
		spawnPlayer();
	}

	float LevelService::getCellWidth() const
	{
		return level_controller->getCellWidth();
	}

	float LevelService::getCellHeight() const
	{
		return level_controller->getCellHeight();
	}

	LevelNumber LevelService::getCurrentLevel() const
	{
		return current_level;
	}

	void LevelService::setCurrentLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
	}

	void LevelService::destroy()
	{
		delete(level_controller);
	}

}