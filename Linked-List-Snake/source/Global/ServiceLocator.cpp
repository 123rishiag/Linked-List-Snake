#include "../header/Global/ServiceLocator.h"
#include "../header/Main/GameService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Time;
	using namespace Level;
	using namespace Element;
	using namespace Food;
	using namespace Player;
	using namespace Sound;
	using namespace UI;
	using namespace Main;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		time_service = nullptr;
		level_service = nullptr;
		element_service = nullptr;
		food_service = nullptr;
		player_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		event_service = new EventService();
		time_service = new TimeService();
		level_service = new LevelService();
		element_service = new ElementService();
		food_service = new FoodService();
		player_service = new PlayerService();
		sound_service = new SoundService();
		ui_service = new UIService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		time_service->initialize();
		level_service->initialize();
		element_service->initialize();
		food_service->initialize();
		player_service->initialize();
		sound_service->initialize();
		ui_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		time_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			level_service->update();
			element_service->update();
			food_service->update();
			player_service->update();
		}
		// sound_service no update
		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		// event_service no render
		// time_service no render
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			level_service->render();
			element_service->render();
			food_service->render();
			player_service->render();
		}
		// sound_service no render
		ui_service->render();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(event_service);
		delete(time_service);
		delete(level_service);
		delete(element_service);
		delete(food_service);
		delete(player_service);
		delete(sound_service);
		delete(ui_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }
	EventService* ServiceLocator::getEventService() { return event_service; }
	TimeService* ServiceLocator::getTimeService() { return time_service; }
	LevelService* ServiceLocator::getLevelService() { return level_service; }
	ElementService* ServiceLocator::getElementService() { return element_service; }
	FoodService* ServiceLocator::getFoodService() { return food_service; }
	PlayerService* ServiceLocator::getPlayerService() { return player_service; }
	SoundService* ServiceLocator::getSoundService() { return sound_service; }
	UIService* ServiceLocator::getUIService() { return ui_service; }

	void ServiceLocator::deleteServiceLocator() { delete(this); }
}