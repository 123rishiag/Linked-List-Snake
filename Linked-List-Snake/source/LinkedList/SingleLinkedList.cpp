#include "../header/LinkedList/SingleLinkedList.h"
#include "../header/Player/BodyPart.h"
#include "../header/Level/LevelView.h"

namespace LinkedList
{
	using namespace Player;
	using namespace Level;

	SingleLinkedList::SingleLinkedList()
	{
		head_node = nullptr;
	}

	SingleLinkedList::~SingleLinkedList() = default;

	void SingleLinkedList::initialize(float width, float height, sf::Vector2i position, Direction direction)
	{
		node_width = width;
		node_height = height;
		default_position = position;
		default_direction = direction;
	}

	void SingleLinkedList::render() { }

	Node* SingleLinkedList::createNode()
	{
		return new Node();
	}

}