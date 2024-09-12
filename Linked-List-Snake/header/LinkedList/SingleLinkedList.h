#pragma once
#include <SFML/System/Vector2.hpp>
#include "../header/LinkedList/Node.h"
#include "../header/Player/Direction.h"

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		int linked_list_size;

		sf::Vector2i default_position;
		Player::Direction default_direction;

		Node* createNode() const;
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);
		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
		void shiftNodesAfterRemoval(Node* cur_node);
		Node* findNodeAtIndex(int index) const;
		int findMiddleNode() const;
		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation) const;
		Player::Direction getReverseDirection(Player::Direction reference_direction) const;
		Player::Direction reverse();
		void removeNodeAtHead();
		void removeNodeAtTail();
		void removeNodeAtIndex(int index);
		void removeNodeAtMiddle();
		void removeNodeAt(int index);

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void render();

		void insertNodeAtHead();
		void insertNodeAtTail();
		void insertNodeAtIndex(int index);
		void insertNodeAtMiddle();
		void updateNodeDirection(Player::Direction direction_to_set);
		void updateNodePosition();

		bool processNodeCollision() const;
		std::vector<sf::Vector2i> getNodesPositionList() const;
		Node* getHeadNode() const;
		void reverseNodeDirections();
		void removeHalfNodes();
		void removeAllNodes();
	};
}