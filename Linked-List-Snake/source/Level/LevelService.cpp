#include "../header/Level/LevelService.h"
#include "../header/Level/LevelController.h"

namespace Level
{
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

	void LevelService::createLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
	}

	void LevelService::destroy()
	{
		delete(level_controller);
	}

}