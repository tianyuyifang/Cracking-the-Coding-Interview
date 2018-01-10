#include <iostream>
#include <unordered_map>
#include <random>

using namespace std;


struct Node {
	int data;
	Node *next;
	Node() {
		data = 0;
		next = 0;
	}
};

void insertFromHead(Node *& head, int val) {
	Node *newNode = new Node();
	newNode->data = val;
	newNode->next = head;
	head = newNode;
}

void printList(Node *head) {
	while(head != 0) {
		cout << head->data << "-->";
		head = head->next;
	}
	cout << "nullptr" << endl;
}

int random_range(int min, int max) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> distribution(min, max);
	return distribution(mt);
}

//Method 1, recursive
int method1(Node *head, int k) {    //assume k is less than the length of the list;
	if (head == 0) return 0;
	int index = method1(head->next, k) + 1;
	if (index == k) 
		cout << "The last " << k << "th data is " << head->data << "." << endl;
	return index;
}

//Method 2, recursive
Node * method2Helper(Node *head, int k, int &i) {
	if (head == 0) return 0;
	Node *p = method2Helper(head->next, k, i);
	i = i + 1;
	if (i == k) {
		return head;
	}
	return p;
}
Node * method2(Node *head, int k) {
	int i = 0;
	return method2Helper(head, k, i);
}

//Mehtod 3, iterative
Node * method3(Node *head, int k) {
	Node *p1 = head, *p2 = head;
	for(int i=1; i<=k; i++) {
		p2 = p2->next;
	}
	while(p2 != 0) {
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}



int main() {
	//test method1
	cout << "Method 1: \n";
	Node* head = 0;
	int min = 1;
	int max = 5;
	for(int i=0; i<=10; i++) {
		insertFromHead(head, random_range(min, max));
	}
	printList(head);
	int index = method1(head, 3);

	//test method2
	cout << "Method 2: \n";
	Node* head1 = 0;
	for(int i=0; i<=10; i++) {
		insertFromHead(head1, random_range(min, max));
	}
	printList(head1);
	Node* kth = method2(head1, 3);
	printList(kth);

	//test method3
	cout << "Method 3: \n";
	Node* head2 = 0;
	for(int i=0; i<=10; i++) {
		insertFromHead(head2, random_range(min, max));
	}
	printList(head2);
	Node* kth2 = method3(head2, 4);
	printList(kth2);



	return 0;
}



