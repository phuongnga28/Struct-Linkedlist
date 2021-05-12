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
	node* removeFirst()
	{
		return this->next;
	}
	void removeLast()
	{
		node* data = this;
		while (data->next->next != NULL) data = data->next;
		data->next = NULL;
	}
	void insertAfter(node* p, const char* c)
	{
		node* temp = new node(c);
		if (p->next == NULL) p->next = temp;
		else
		{
			temp->next = p->next;
			p->next = temp;
		}
	}
	node* removeNode(node* p)
	{
		if (this == p) return this->next;
		else if (p->next == NULL) { removeLast(); return this; }
		else
		{
			node* data = this;
			while (data->next != p) data = data->next;
			data->next = p->next;
			return this;
		}
	}
};
int main()
{
	node* f = new node("Nga");
	f = f->addFirst("Phuong");
	f->addLast("one of a kind");
	f->print();
	f = f->removeFirst();
	f->print();
	f->removeLast();
	f->print();
	f->insertAfter(f, "GDragon");
	f->print();
	f->insertAfter(f, "<3");
	f = f->removeNode(f->next);
	f->print();
}
