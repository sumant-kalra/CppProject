// Linked list (forward_list in C++)
// 'current' and 'nextNode' nodes
// 'previousNode' node while deallocating memory

// Singly linked list
// [0] Each node has 'data' and 'next'
// [1] Draw diagram on paper
// [2] Visualize each operation
// [3] Remember the traversal: 
//		I.   Node* current = headNode; 
//		II.  Node* nextNode = current->next;
//		III. Keep updating the 'current' node to the 'nextNode' and nextNode = current->next;
// [4] Sometimes, we may have to keep a track of the previous node as well, for example while deallocating the memory.
//
// 
// Comparing various kinds of Linked Lists like DoublyLinkedLists, CircularLinkedLists
// It all comes down to the application or the problem at hand.
// There should not be a standard way of the solving problem, you can implement your class depending upon the problem. 			
//

#include <iostream>

struct Node
{
	int data = 0;
	Node* next = nullptr;
};

class LinkedList
{
private:
	Node* m_listHead;
	unsigned int m_nodeCount;

public:
	// [1] Parameterized constructor
	explicit LinkedList(unsigned int count)
		:m_nodeCount(count) // [TESTED]
	{	
		if (m_nodeCount <= 0)
		{
			std::cout << "The total number of nodes must be greater than 0 !\n";
			exit(-1);
		}

		m_listHead = new Node;
		Node* previousNode = m_listHead;

		for (unsigned int i = 1; i < m_nodeCount; ++i)
		{
			Node* current = new Node;
			previousNode->next = current;
			previousNode = current;		
		}
		previousNode->next = nullptr;

	}

	// [2] Deleted copy constructor
	LinkedList(const LinkedList& list) = delete;

	// [3]  Deleted assignment operator
	LinkedList& operator=(const LinkedList& list) = delete;

	// [4] Destructor
	~LinkedList() // [TESTED]
	{
		Node* current = m_listHead;
		Node* nextNode = nullptr;
		while (current)
		{
			nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}

	// Getters
	// [5] get the head node
	Node* getHead() const // [TESTED]
	{
		return m_listHead;
	}

	// [6] get the total nodes count
	unsigned int getTotalNodesCount() const // [TESTED]
	{
		return m_nodeCount;
	}

	// [7] get the node at any at index n, indexing starts from 0.
	Node* getNode(unsigned int n) const // [TESTED]
	{
		if (n >= m_nodeCount)
		{
			std::cout << "The total number of nodes in the list are: " << m_nodeCount << ". There is no node at the index: " << n << "\n";
			return nullptr;
		}

		Node* current = m_listHead;
		Node* nextNode = current->next;
		for (unsigned int i = 1; i <= n; ++i)
		{
			current = nextNode;
			nextNode = current->next;
		}
		return current;
	}

	// [8] return the node with the data as 'value'
	Node* searchDataValue(int value) const // [TESTED]
	{
		Node* current = m_listHead;
		Node* nextNode = current->next;
		for (unsigned int i = 0; i < m_nodeCount; ++i)
		{
			if (current->data == value)
				return current;
			current = nextNode;
			nextNode = current->next;
		}
		std::cout << "The value is not present in the list.\n";
		return nullptr;
	}

	// [9] print the linked list
	void printList() const // [TESTED]
	{
		Node* current = m_listHead;
		while (current)
		{
			std::cout << current->data << " ";
			current = current->next;
		}	
		std::cout << "\n";
	}

	// Setters
	// [10] Inserting a new node in the list at index n
	bool insertNode(Node* node, unsigned int n) // [TESTED]
	{
		if (n <= m_nodeCount)
		{
			Node* current = m_listHead;
			Node* nextNode = current->next;
			for (unsigned int i = 1; i < n; ++i)
			{
				current = nextNode;
				nextNode = current->next;
			}

			current->next = node;
			node->next = nextNode;

			++m_nodeCount;
			return true;
		}
		else
		{
			std::cout << "The node can not be inserted at the index: " << n << "as the size of the list is: "<<m_nodeCount << "\n";
			return false;
		}

	}

	// [11] Deleting node at index n from the list
	bool deleteNodeExceptFirstorLast(unsigned int n) // [TESTED]
	{
		if ((n < m_nodeCount) && (n != 0) && (n < (m_nodeCount-1)))
		{
			Node* current = m_listHead;
			Node* nextNode = current->next;
			for (unsigned int i = 1; i < n; ++i)
			{
				current = nextNode;
				nextNode = current->next;
			}

			current->next = nextNode->next;
			nextNode->next = nullptr;
			delete nextNode;

			--m_nodeCount;
			return false;
		}
		else if((n==0) || (n==(m_nodeCount-1)))
		{
			std::cout << "This method can not be used to delete first or the last node\n";
			return false;
		}
		else
		{
			std::cout << "There is no node at the index: " << n << "as the size of the list is: " << m_nodeCount << "\n";
			return false;
		}
	}

	bool deleteFirstNode() // [TESTED]
	{
		Node* current = m_listHead;
		m_listHead = current->next;
		current->next = nullptr;
		delete current;
		--m_nodeCount;
		current = nullptr;
		return true;
	}

	bool deleteLastNode() // [TESTED]
	{
		Node* current = m_listHead;
		Node* nextNode = current->next;
		for (unsigned int i = 1; i < m_nodeCount-1; ++i)
		{
			current = nextNode;
			nextNode = current->next;
		}
		current->next = nullptr;
		delete nextNode;
		--m_nodeCount;
		nextNode = nullptr;
		return true;
	}

};

int main()
{
	LinkedList myList(5);

	myList.getNode(0)->data = 0;
	myList.getNode(1)->data = 1;
	myList.getNode(2)->data = 2;
	myList.getNode(3)->data = 3;
	myList.getNode(4)->data = 4;
	
#if 0
	Node* node = myList.searchDataValue(4);
	if(node)
		std::cout << node->data << "\n";

	Node* newNode = new Node;
	newNode->data = 45;
	myList.insertNode(newNode,5);

	myList.deleteFirstNode();
	myList.deleteLastNode();

	std::cout << myList.getTotalNodesCount() << "\n";
#endif

	myList.deleteNodeExceptFirstorLast(1);

	myList.printList();
	
	return 0;
}