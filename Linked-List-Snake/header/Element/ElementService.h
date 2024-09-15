#pragma once
#include <SFML/System/Vector2.hpp>
#include "../header/LinkedListLib/Node.h"
#include <vector>

namespace Element
{
	class Obstacle;
	struct ElementData;

	class ElementService
	{
	private:
		std::vector<Obstacle*> obstacle_list;

		void spawnObstacle(sf::Vector2i position, float cell_width, float cell_height);

	public:
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();

		const void spawnElements(std::vector<ElementData>& element_data_list, float cell_width, float cell_height);
		bool processElementsCollision(LinkedListLib::Node* head_node) const;
		std::vector<sf::Vector2i> getElementsPositionList() const;
	};
}