#include "../header/LinkedListLib/DoubleLinked/DoubleLinkedList.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		DoubleLinkedList::DoubleLinkedList() = default;

		DoubleLinkedList::~DoubleLinkedList() = default;

		Node* DoubleLinkedList::createNode()
		{
			return nullptr;
		}

		void DoubleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
		{
		}

		void DoubleLinkedList::shiftNodesAfterRemoval(Node* cur_node)
		{
		}

		void DoubleLinkedList::insertNodeAtTail()
		{
		}

		void DoubleLinkedList::insertNodeAtHead()
		{
		}

		void DoubleLinkedList::insertNodeAtMiddle()
		{      
		}

		void DoubleLinkedList::insertNodeAtIndex(int index)
		{
		}

		void DoubleLinkedList::removeNodeAtTail()
		{
		}

		void DoubleLinkedList::removeNodeAtHead()
		{
		}

		void DoubleLinkedList::removeNodeAtMiddle()
		{
		}

		void DoubleLinkedList::removeNodeAtIndex(int index)
		{
		}

		void DoubleLinkedList::removeNodeAt(int index)
		{
		}

		void DoubleLinkedList::removeAllNodes()
		{
		}

		void DoubleLinkedList::removeHalfNodes()
		{
		}

		Direction DoubleLinkedList::reverse()
		{
			return Player::Direction::UP;
		}
	}
}