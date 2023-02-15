#include <iostream>
using namespace std;
class linked_list
{
private:
	struct Node
	{
		int item;
		Node* next;
	};
	Node* first;
	Node* last;
	int length;
public:
	linked_list()
	{
		first = last = NULL;
		length = 0;
	}
	bool isempty()
	{
		return length == 0;
	}
	void insert_first(int element)
	{
		Node* newnode = new Node;
		newnode->item = element;
		if (isempty())
		{
			first =last= newnode;
			newnode->next = NULL;
		}
		else
		{
			newnode->next = first;
			first = newnode;
		}
		length++;
	}
	void insert_last(int element)
	{
		Node* newnode = new Node;
		newnode->item = element;
		if (isempty())
		{
			first = last = newnode;
			newnode->next = NULL;
		}
		else
		{
			last->next = newnode;
			newnode->next = NULL;
			last = newnode;
		}
		length++;
	}
	void insert_at_position(int position, int element)
	{
		if (position<0 || position>length)
			cout << "out of range" << endl;
		else
		{
			Node* newnode = new Node;
			newnode->item = element;
			if (position == 0)
				insert_first(element);
			else if (position == length)
				insert_last(element);
			else
			{
				Node* curr = first;
				for (int i = 1; i < position; i++)
				{
					curr = curr->next;
				}
				newnode->next = curr->next;
				curr->next = newnode;
				length++;
			}
		}
	}
	void remove_first()
	{
		if (isempty())
			cout << "The list is already empty" << endl;
		else if (length == 1)
		{
			delete first;
			first = last = NULL;
			length--;
		}
		else
		{
			Node* curr = first;
			first = first->next;
			delete curr;
			length--;
		}
	}
	void remove_last()
	{
		if (isempty())
			cout << "The list is already empty." << endl;
		else if (length == 1)
			remove_first();
		else
		{
			Node* curr = first->next;
			Node* prev = first;
			while (curr!=last)
			{
				prev = curr;
				curr = curr->next;
			}
			delete curr;
			prev->next = NULL;
			last = prev;
			length--;
		}
	}
	void remove_element(int element)
	{
		if (isempty())
		{
			cout << "The list is already empty" << endl;
		}

		Node* curr, *prev;
		if (first->item == element)
			remove_first();
		else
		{
			curr = first->next;
			prev = first;
			while (curr != NULL)
			{
				if (curr->item == element)
					break;
				prev = curr;
				curr = curr->next;
			}

			if (curr == NULL)
				cout << "The item is not there"<<endl;
			else
			{
				prev->next = curr->next;
				if (last == curr)
					last = prev;
				delete curr;
				length--;
			}
		}
	}
	void reverse()
	{
		Node* prev = NULL;
		Node* curr = first;
		Node* next=curr->next;
		while (next != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		first = prev;
	}
	int search(int element)
	{
		Node* curr = first;
		int pos = 0;
		while (curr != NULL)
		{
			if (curr->item == element)
				return pos;
			curr = curr->next;
			pos++;
		}
		return -1;
	}
	void print()
	{
		Node* curr = first;
		while (curr!=NULL)
		{
			cout << curr->item << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};

         /************************************************************************************************/

class Doubly_linked
{
private:
	struct Node
	{
		int item;
		Node* next;
		Node* prev;
	};
	Node* first;
	Node* last;
	int length;
public:
	Doubly_linked()
	{
		first = NULL;
		last = NULL;
		length = 0;
	}
	bool isempty()
	{
		return length == 0;
	}
	void insert_first(int element)
	{
		Node* newnode = new Node;
		newnode->item = element;
		if (isempty())
		{
			first = last = newnode;
			newnode->next =newnode->prev= NULL;
		}
		else
		{
			newnode->next = first;
			newnode->prev = NULL;
			first->prev = newnode;
			first = newnode;
		}
		length++;
	}
	void insert_last(int element)
	{
		Node* newnode = new Node;
		newnode->item = element;
		if (isempty())
		{
			first = last = newnode;
			newnode->next=newnode->prev = NULL;
		}
		else
		{
			newnode->next = NULL;
			newnode->prev = last;
			last->next = newnode;
			last = newnode;
		}
		length++;
	}
	void insert_at_position(int position, int element)
	{
		if (position<0 || position>length)
			cout << "out of range" << endl;
		else
		{
			Node* newnode = new Node;
			newnode->item = element;
			if (position == 0)
				insert_first(element);
			else if (position == length)
				insert_last(element);
			else
			{
				Node* curr = first;
				for (int i = 1; i < position; i++)
					curr = curr->next;
				newnode->next = curr->next;
				newnode->prev = curr;
				curr->next->prev = newnode;
				curr->next = newnode;
			}
			length++;
		}
		
	}
	void remove_first()
	{
		if (isempty())
			cout << "The list is already empty" << endl;
		else if (length == 1)
		{
			delete first;
			first = last = NULL;
			length--;
		}
		else
		{
			Node* curr = first;
			first = first->next;
			first->prev = NULL;
			delete curr;
			length--;
		}
	}
	void remove_last()
	{
		if (isempty())
			cout << "The list is already empty." << endl;
		else if (length == 1)
			remove_first();
		else
		{
			Node* curr = last;
			last = last->prev;
			last->next = NULL;
			delete curr;
			length--; 
		}
	}
	void remove_element(int element)
	{
		if (isempty())
		{
			cout << "The list is already empty" << endl;
		}

		Node* curr;
		if (first->item == element)
			remove_first();
		else
		{
			curr = first->next;
			while (curr != NULL)
			{
				if (curr->item == element)
					break;
				curr = curr->next;
			}

			if (curr == NULL)
				cout << "The item is not there" << endl;
			else if (curr->next == NULL)
				remove_last();
			else
			{
				curr->prev->next = curr->next;
				curr->next->prev = curr->prev;
				delete curr;
				length--;
			}
		}
	}
	void print()
	{
		Node* curr = first;
		while (curr != NULL)
		{
			cout << curr->item << " ";
			curr = curr->next;
		}
		cout << endl;
	}
	void reverse()
	{
		Node* curr = last;
		while (curr != NULL)
		{
			cout << curr->item << " ";
			curr = curr->prev;
		}
		cout << endl;
	}
};
int main()
{
	Doubly_linked x;
	x.insert_first(5);
	x.insert_last(80);
	x.insert_at_position(1, 10);
	x.insert_at_position(2, 15);
	x.insert_at_position(3, 20);
	x.insert_at_position(4, 25);
	x.insert_last(85);
	x.insert_first(0);
	x.remove_element(20);
	x.remove_first();
	x.remove_last();
	x.print();
	x.reverse();
}