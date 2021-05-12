#include<iostream>

using namespace std;

struct node
{
	const char* data;
	node* next;
	node(const char* string)
	{
		data = string;
		this->next = NULL;
	}
	~node()
	{
		delete[]data;
		delete[]next;
	}
	node* addFirst(const char* c)
	{
		node* temp = new node(c);
		temp->next = this;
		return temp;
	}
	void addLast(const char* c)
	{
		node* temp = new node(c);
		node* p = this;
		while (p->next != NULL) p = p->next;
		p->next = temp;
	}
	void print()
	{
		node* p = this;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
};
int main()
{
	node* f = new node("Nga");
	f = f->addFirst("Phuong");
	f->addLast("one of a kind");
	f->print();
}
