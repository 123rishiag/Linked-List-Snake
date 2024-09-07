#pragma once
#include<SFML/Graphics.hpp>
#include "../header/UI/UIElement/ImageView.h"
#include "../header/Player/Direction.h"

namespace Player
{
	class BodyPart
	{
	protected:
		UI::UIElement::ImageView* bodypart_image;

		sf::Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;
	};
}