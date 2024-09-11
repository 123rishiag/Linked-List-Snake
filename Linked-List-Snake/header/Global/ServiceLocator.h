#pragma once
#include "../header/Graphics/GraphicService.h"
#include "../header/Event/EventService.h"
#include "../header/Time/TimeService.h"
#include "../header/Level/LevelService.h"
#include "../header/Element/ElementService.h"
#include "../header/Food/FoodService.h"
#include "../header/Player/PlayerService.h"
#include "../header/Sound/SoundService.h"
#include "../header/UI/UIService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Graphics::GraphicService* graphic_service;
        Event::EventService* event_service;
        Time::TimeService* time_service;
        Level::LevelService* level_service;
        Element::ElementService* element_service;
        Food::FoodService* food_service;
        Player::PlayerService* player_service;
        Sound::SoundService* sound_service;
        UI::UIService* ui_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Graphics::GraphicService* getGraphicService();
        Event::EventService* getEventService();
        Time::TimeService* getTimeService();
        Level::LevelService* getLevelService();
        Element::ElementService* getElementService();
        Food::FoodService* getFoodService();
        Player::PlayerService* getPlayerService();
        Sound::SoundService* getSoundService();
        UI::UIService* getUIService();

        void deleteServiceLocator();
    };
}