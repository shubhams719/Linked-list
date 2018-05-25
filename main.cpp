#include<iostream>
#include "link.h"

int main()
{
	Node* head = NULL;
	Node* head1 = NULL;
	Node* head2 = NULL;
	push(head,8);
	push(head,1);
	push(head1,9);
	push(head1,9);
	push(head1,9);
	Add(head,head1,head2);
	print(head2);
	return 0;
}
