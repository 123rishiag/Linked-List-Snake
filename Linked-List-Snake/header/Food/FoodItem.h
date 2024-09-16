#pragma once
#include <SFML/Graphics.hpp>
#include "../header/UI/UIElement/ImageView.h"

namespace Food
{
    enum class FoodType;

    class FoodItem
    {
    private:
        UI::UIElement::ImageView* food_image;

        sf::Vector2i grid_position;

        float cell_width;
        float cell_height;

        FoodType food_type;

        void initializeFoodImage();
        sf::String getFoodTexturePath() const;
        sf::Vector2f getFoodImagePosition() const;
        void destroy();

    public:
        static const int number_of_foods = 8;
        static const int number_of_healthy_foods = 4;

        FoodItem();
        ~FoodItem();

        void initialize(sf::Vector2i grid_pos, float width, float height, FoodType type);
        void update();
        void render();

        FoodType getFoodType() const;
        sf::Vector2i getFoodPosition() const;
    };
}