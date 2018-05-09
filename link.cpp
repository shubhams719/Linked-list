#include<iostream>

struct Node
{
	int data;
	Node* next;
};

Node* GetNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void push(Node*& head,int data)
{
	Node* temp = GetNode(data);
	if(head == NULL)
	{
		head = temp;
		return;
	}
	temp->next = head;
	head = temp;
	return;
}

void pop(Node*& head)
{
	if(head == NULL)
		return;
	Node* temp = head;
	head = temp->next;
	temp->next = NULL;
	delete(temp);
	return;
}

void print(Node* head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		std::cout << temp->data << " ";
		temp= temp->next;
	}
	std::cout <<"\n";
	return;
}

void Reverse(Node*& head)
{
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;

	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return;
}

Node* ReverseByK(Node* head,int k)
{
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;
	int count =0;

	while(curr != NULL && count < k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if(next != NULL)
	{
		head->next = ReverseByK(next,k);
	}
	return prev;
}

int Middle(Node* head)
{
	Node* fast = head;
	Node* slow = head;
	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->data;
}
	






