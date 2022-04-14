#include <iostream>

using namespace std;

// NODE
template <typename T>
struct Node
{
private:
	T data;
	Node<T>* next = nullptr;

public:
	Node(T d, Node<T>* pNode)
	{
		data = d;
		next = pNode;
	}
	~Node() {}

	Node<T>* getNext()
	{
		return next;
	}

	void setNext(Node<T>* pNode)
	{
		next = pNode;
	}

	T getData()
	{
		return data;
	}
};

// LINKED LIST
template <typename T>
class SinglyLinkedList
{
private:
	Node<T>* head;
	int size = 0;

public:
	SinglyLinkedList()
	{
		head = nullptr;
	}
	~SinglyLinkedList() {}

	void insert(T data)
	{
		Node<T>* node = new Node<T>(data, nullptr);

		if (isEmpty())
		{
			head = node;
		}
		else
		{
			Node<T>* prevNode = head;
			for (int i = 0; i < size - 1; i++)
			{
				prevNode = prevNode->getNext();
			}
			prevNode->setNext(node);
		}
		size++;
	}

	void insert(int idx, T data)
	{
		if (idx<0 || idx>size) // index range Error
		{
			cout << "INDEX RANGE ERROR" << endl;
			return;
		}
		Node<T>* node = new Node<T>(data, nullptr);

		if (idx == 0)
		{
			node->setNext(head); // 새로운 node의 next에 기존 head node를 연결
			head = node; // 새로운 node가 head 가 되었으므로 update 해줌
		}
		else
		{
			Node<T>* prevNode = head;
			for (int i = 0; i < idx - 1; i++)
			{
				prevNode = prevNode->getNext();
			}
			node->setNext(prevNode->getNext()); // 새로운 node의 next에 이전 node의 next를 대입
			prevNode->setNext(node); // 이전 node의 next에는 새로운 node를 연결
		}
		size++;
	}

	void remove(int idx)
	{
		if (isEmpty())
		{
			cout << "[Error] LIST IS EMPTY!" << endl;
			return;
		}

		if (idx<0 || idx>size)
		{
			cout << "INDEX RANGE ERROR" << endl;
			return;
		}

		if (idx == 0)
		{
			Node<T>* tempNode = head;
			head = tempNode->getNext();
			delete tempNode;
		}
		else
		{
			Node<T>* prevNode = head;
			for (int i = 0; i < idx - 1; i++)
			{
				prevNode = prevNode->getNext();
			}
			Node<T>* tempNode = prevNode->getNext();
			prevNode->setNext(tempNode->getNext());
			delete tempNode;
		}
		size--;
	}

	void display()
	{
		if (isEmpty())
		{
			cout << "LIST IS EMPTY" << endl;
			return;
		}

		Node<T>* tempNode = head;
		for (int i = 0; i < size; i++)
		{
			cout << "[" << tempNode->getData() << "]";
			tempNode = tempNode->getNext();
		}
		cout << endl;
	}

	bool isEmpty()
	{
		return size == 0;
	}
};


int main()
{
	SinglyLinkedList<int> list;

	cout << "===== INSERT VALUE =====" << endl;
	list.insert(1);
	list.insert(13);
	list.insert(45);
	list.insert(2, 27);
	list.display();

	cout << "===== REMOVE INDEX 1 =====" << endl;
	list.remove(1);
	list.display();

	return 0;
}
