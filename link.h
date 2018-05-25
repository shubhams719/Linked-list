struct Node;

Node* GetNode(int data);

void push(Node*& head,int data);

void pop(Node*& head);

void print(Node* head);

void Reverse(Node*& head);

Node* ReverseByK(Node* head,int k);

int Middle(Node* head);

void Swap(Node*& head,int x,int y);

void Delete(Node*& head);

Node* Merge(Node* head1, Node* head2);

void frontbacksplit(Node* source,Node*& a,Node*& b);

Node* SortedMerge(Node* a,Node* b);

void Merge(Node*& head);

void Rotate(Node*& head ,int k);

void Segragate(Node*& head);

void check(Node*);

void check1(Node*&);

void Add(Node*,Node*,Node*&);

Node* AddListSameSize(Node* head1,Node* head2,int& carry);

void AddCarryToRemaining(Node* head1,Node* cur, int& carry,Node*& result);
