#include "../header/Player/BodyPart.h"
#include "../header/Level/LevelView.h"
#include "../header/Global/Config.h"

namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;
	using namespace Level;

	BodyPart::BodyPart()
	{
		grid_position = sf::Vector2i(0, 0);
		createBodyPartImage();
	}

	BodyPart::~BodyPart()
	{
		destroy();
	}

	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new ImageView();
	}

	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		grid_position = pos;
		direction = dir;

		inititalizeBodyPartImage();
	}

	void BodyPart::inititalizeBodyPartImage()
	{
		bodypart_image->initialize(Config::snake_body_texture_path, bodypart_width, bodypart_height, sf::Vector2f(0, 0));
	}

	void BodyPart::updatePosition() 
	{ 
		bodypart_image->setPosition(getBodyPartScreenPosition());
		bodypart_image->setRotation(getRotationAngle());
		bodypart_image->update();
	}

	void BodyPart::render()
	{
		bodypart_image->render();
	}

	sf::Vector2f BodyPart::getBodyPartScreenPosition() const
	{
		float x_screen_position = LevelView::border_offset_left + (grid_position.x * bodypart_width) + (bodypart_width / 2);
		float y_screen_position = LevelView::border_offset_top + (grid_position.y * bodypart_height) + (bodypart_height / 2);

		return sf::Vector2f(x_screen_position, y_screen_position);
	}

	float BodyPart::getRotationAngle() const
	{
		switch (direction)
		{
		case Direction::UP:
			return 270.f;
		case Direction::DOWN:
			return 90.f;
		case Direction::LEFT:
			return 180.f;
		case Direction::RIGHT:
			return 0.f;
		}
	}

	sf::Vector2i BodyPart::getNextPositionUp() const
	{
		return sf::Vector2i(grid_position.x, grid_position.y + 1);
	}

	sf::Vector2i BodyPart::getNextPositionDown() const
	{
		return sf::Vector2i(grid_position.x, grid_position.y - 1);
	}

	sf::Vector2i BodyPart::getNextPositionLeft() const
	{
		return sf::Vector2i(grid_position.x - 1, grid_position.y);
	}

	sf::Vector2i BodyPart::getNextPositionRight() const
	{
		return sf::Vector2i(grid_position.x + 1, grid_position.y);
	}

	Direction BodyPart::getDirection() const
	{
		return direction;
	}

	void BodyPart::setDirection(Direction dir)
	{
		direction = dir;
	}

	sf::Vector2i BodyPart::getPosition() const
	{
		return grid_position;
	}

	void BodyPart::setPosition(sf::Vector2i position)
	{
		grid_position = position;
	}

	sf::Vector2i BodyPart::getNextPosition() const
	{
		switch (direction)
		{
		case Direction::UP:
			return getNextPositionUp();
		case Direction::DOWN:
			return getNextPositionDown();
		case Direction::LEFT:
			return getNextPositionLeft();
		case Direction::RIGHT:
			return getNextPositionRight();
		}
	}

	void BodyPart::destroy()
	{
		delete(bodypart_image);
	}
}