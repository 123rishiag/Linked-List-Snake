#include "../header/Player/BodyPart.h"
#include "../header/Global/Config.h"

namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;

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

	void BodyPart::update() { }

	void BodyPart::render()
	{
		bodypart_image->render();
	}

	void BodyPart::destroy()
	{
		delete(bodypart_image);
	}
}