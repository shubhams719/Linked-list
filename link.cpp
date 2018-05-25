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

void Rotate(Node*& head ,int k)
{
	Node* curr = head;
	Node* tail = head;
	Node* prev;
	int count =0;

	while(curr != NULL && count < k)
	{
			prev = curr;
			curr = curr->next;
			if(tail->next != NULL)
				tail = tail->next;
			count++;
	}
	while(tail->next != NULL)
		tail = tail->next;
	tail->next = head;
	head = curr;
	prev->next = NULL;
}

void check(Node* head)
{

}

void check1(Node*& head)
{
	Node* temp = head;
	temp = NULL;
}

int getsize(Node* head)
{
	int size=0;
	while(head != NULL)
	{
		head= head->next;
		size++;
	}
	return size;
}

void swap(Node*& head1,Node*& head2)
{
	Node* temp;
	temp = head1;
	head1 = head2;
	head2 = temp;
}

Node* AddListSameSize(Node* head1,Node* head2,int& carry)
{
	int sum;
	if(!head1)
		return NULL;
	Node* result = new Node();
	result->next = AddListSameSize(head1->next,head2->next,carry);
	sum = head1->data + head2->data + carry;
	carry = sum / 10;
	sum = sum%10;
	result->data = sum;
	return result;
}
void AddCarryToRemaining(Node* head1,Node* cur, int& carry,Node*& result)
{
	int sum;
	if(head1 != cur)
	{
		AddCarryToRemaining(head1->next,cur,carry,result);
		sum = head1->data + carry;
		carry = sum / 10;
		sum = sum % 10;
		push(result,sum);
	}
}


void Add(Node* head1,Node* head2,Node*& result)
{
	if(!head1)
	{
		result = head2;
		return;
	}
	
	if(!head2)
	{
		result = head1;
		return;
	}
	int carry = 0;
	int size1 = getsize(head1);
	int size2 = getsize(head2);
	if(size1 == size2)
		result = AddListSameSize(head1,head2,carry);
	else
	{
		if(size1 < size2)
			swap(head1,head2);
		int diff = (size1 > size2) ? (size1-size2) : (size2-size1);
		Node* cur;
		for(cur = head1;diff--;cur = cur->next);
		result = AddListSameSize(cur,head2,carry);
		AddCarryToRemaining(head1,cur,carry,result);
	}
	if(carry)
		push(result,carry);
}


	

