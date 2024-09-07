#include "../header/Level/LevelService.h"
#include "../header/Level/LevelController.h"
#include "../header/Global/ServiceLocator.h"

namespace Level
{
	using namespace Global;

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

	void LevelService::spawnPlayer()
	{
		ServiceLocator::getInstance()->getPlayerService()->spawnPlayer();
	}

	void LevelService::createLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
		spawnPlayer();
	}

	void LevelService::destroy()
	{
		delete(level_controller);
	}

}