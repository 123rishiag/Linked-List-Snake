#include "../header/Level/LevelController.h"
#include "../header/Level/LevelView.h"
#include "../header/Level/LevelModel.h"

namespace Level
{
	using namespace Element;

	LevelController::LevelController()
	{
		level_view = new LevelView();
		level_model = new LevelModel();
	}

	LevelController::~LevelController()
	{
		destroy();
	}

	void LevelController::initialize() 
	{
		level_view->initialize();
		level_model->initialize(level_view->getGridWidth(), level_view->getGridHeight());
	}

	void LevelController::update() 
	{
		level_view->update();
	}

	void LevelController::render() 
	{ 
		level_view->render();
	}

	float LevelController::getCellWidth() const
	{
		return level_model->getCellWidth();
	}

	float LevelController::getCellHeight() const
	{
		return level_model->getCellHeight();
	}

	const std::vector<ElementData>& LevelController::getElementDataList(int level_to_load) const
	{
		return level_model->getElementDataList(level_to_load);
	}

	void LevelController::destroy()
	{
		delete(level_model);
		delete(level_view);
	}

}