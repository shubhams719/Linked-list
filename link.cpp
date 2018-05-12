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

void print( Node* head)
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


void Swap(Node*& head,int x,int y)
{
	Node* CurrX=NULL;
	Node* CurrY=NULL;
	Node* temp = head;
	while(temp != NULL && ((CurrX == NULL) || (CurrY == NULL)))
	{
		if(x == temp->data)
			CurrX = temp;
		if(y == temp->data)
			CurrY = temp;
		temp = temp->next;
	}
	int data = CurrX->data;
	CurrX->data = CurrY->data;
	CurrY->data = data;
	return;
}

void Delete(Node*& head)
{
	Node* temp = head;
	Node* Next = NULL;
	while(temp != NULL)
	{
		Next = temp->next;
		delete(temp);
		temp = Next;
	}
	head = NULL;
	return;
}

void frontbacksplit(Node* source,Node*& a,Node*& b)
{
	Node* fast= source;
	Node* slow = source;

	while(fast->next != NULL && fast != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	a = source;
	b = slow->next;
	slow->next = NULL;
}

Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;
	if(a == NULL)
		return(b);
	if(b==NULL)
		return(a);
	if(a->data > b->data)
	{
		result = b;
		result->next = SortedMerge(a,b->next);
	}
	if(a->data < b->data)
	{
		result = a;
		result->next = SortedMerge(a->next,b);
	}
	return(result);
}

void Merge(Node*& head)
{
	Node* source = head;
	Node* a = NULL;
	Node* b = NULL;
	if(head == NULL || head->next == NULL)
		return ;
	frontbacksplit(source,a,b);
	Merge(a);
	Merge(b);
	head = SortedMerge(a,b);
}

void Segragate(Node*& head)
{
	Node* curr = head;
	Node* prev = NULL;
	Node* tail = head;
	int count = 0;
	int len = 0;
	while(tail->next != NULL)
	{
		tail = tail->next;
		len++;
	}

		print(head);
	while(head != NULL && ((head->data % 2) ==0) && count < len)
	{
		Node* new_tail = GetNode(curr->data);
		tail->next = new_tail;
		tail = new_tail;
		prev = curr->next;
		delete(curr);
		curr = prev;
		head = head->next;
		count++;
		print(head);
	}
	
	while(curr != NULL && count < len)
	{
		if((curr->data % 2) != 0)
		{
			prev = curr;
			curr = curr->next;
		}
		else
		{
			Node* new_tail = GetNode(curr->data);
			tail->next = new_tail;
			tail = new_tail;
			prev->next = curr->next;
			delete(curr);
			curr = prev->next;
		}
		count++;
	}
}




			

		




