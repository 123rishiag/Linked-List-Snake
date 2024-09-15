#pragma once
#include <SFML/System/Vector2.hpp>
#include "../header/LinkedListLib/Node.h"
#include "../header/LinkedListLib/LinkedList.h"

namespace LinkedListLib
{
	namespace SingleLinked
	{
		class SingleLinkedList : public LinkedList
		{
		protected:
			virtual Node* createNode() override;
			void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
			void shiftNodesAfterRemoval(Node* cur_node);

		public:
			SingleLinkedList();
			~SingleLinkedList();

			void insertNodeAtTail() override;
			void insertNodeAtHead() override;
			void insertNodeAtMiddle() override;
			void insertNodeAtIndex(int index) override;

			void removeNodeAtTail() override;
			void removeNodeAtHead() override;
			void removeNodeAtMiddle() override;
			void removeNodeAtIndex(int index);
			void removeNodeAt(int index) override;
			void removeAllNodes() override;
			void removeHalfNodes() override;

			Direction reverse() override;
		};
	}
}