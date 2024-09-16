#include "../header/UI/LinkedListSelection/LinkedListSelectionUIController.h"
#include "../header/Main/GameService.h"
#include "../header/Graphics/GraphicService.h"
#include "../header/Sound/SoundService.h"
#include "../header/Event/EventService.h"
#include "../header/Global/Config.h"
#include "../header/Global/ServiceLocator.h"
#include "../header/Level/LevelConfig.h"

namespace UI
{
    namespace LinkedListSelection
    {
        using namespace Global;
        using namespace Main;
        using namespace UIElement;
        using namespace Sound;
        using namespace Level;

        LinkedListSelectionUIController::LinkedListSelectionUIController()
        {
            createImage();
            createButtons();
        }

        LinkedListSelectionUIController::~LinkedListSelectionUIController()
        {
            destroy();
        }

        void LinkedListSelectionUIController::createImage()
        {
            background_image = new ImageView();
        }

        void LinkedListSelectionUIController::createButtons()
        {
            single_linked_list_button = new ButtonView();
            double_linked_list_button = new ButtonView();
            menu_button = new ButtonView();
        }

        void LinkedListSelectionUIController::initialize()
        {
            initializeBackgroundImage();
            calculateLeftOffsetForButton();
            registerButtonCallback();
        }

        void LinkedListSelectionUIController::initializeBackgroundImage()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
            background_image->setImageAlpha(background_alpha);
        }

        void LinkedListSelectionUIController::calculateLeftOffsetForButton()
        {
            single_linked_list_button->initialize("Single Linked List Button", Config::single_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(0, single_linked_list_button_y_position));
            double_linked_list_button->initialize("Double Linked List Button", Config::double_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(0, double_linked_list_button_y_position));
            menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, menu_button_y_position));

            single_linked_list_button->setCentreAlinged();
            double_linked_list_button->setCentreAlinged();
            menu_button->setCentreAlinged();
        }

        void LinkedListSelectionUIController::registerButtonCallback()
        {
            single_linked_list_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::singleLinkedListButtonCallback, this));
            double_linked_list_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::doubleLinkedListButtonCallback, this));
            menu_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::menuButtonCallback, this));
        }

        void LinkedListSelectionUIController::singleLinkedListButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void LinkedListSelectionUIController::doubleLinkedListButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::GAMEPLAY);
        }

        void LinkedListSelectionUIController::menuButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            GameService::setGameState(GameState::MAIN_MENU);
        }

        void LinkedListSelectionUIController::update()
        {
            background_image->update();
            single_linked_list_button->update();
            double_linked_list_button->update();
            menu_button->update();
        }

        void LinkedListSelectionUIController::render()
        {
            background_image->render();
            single_linked_list_button->render();
            double_linked_list_button->render();
            menu_button->render();
        }

        void LinkedListSelectionUIController::show()
        {
            background_image->show();
            single_linked_list_button->show();
            double_linked_list_button->show();
            menu_button->show();
        }

        void LinkedListSelectionUIController::destroy()
        {
            delete(menu_button);
            delete(single_linked_list_button);
            delete(double_linked_list_button);
            delete(background_image);
        }
    }
}