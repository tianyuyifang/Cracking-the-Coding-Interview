#include <iostream>
#include <random>
#include <stack>

using namespace std;


struct Node {
	int data;
	Node *next;
	Node(): data(0), next(0) {}
	Node(int data, Node *next): data(data), next(next) {}
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
// for example 9->2 + 2->3 = 1->6 (29 + 32 = 61)
Node * sumLists(Node *head1, Node *head2) {
	int carry = 0;
	int sum;
	Node *head = new Node(-1, 0);
	Node *cur = head;
	while(head1 != 0 && head2 != 0) {
		sum = head1->data + head2->data + carry;
		carry = sum / 10;
		sum = sum % 10;
		cur->next = new Node(sum, 0);
		cur = cur->next;
 		head1 = head1->next;
		head2 = head2->next;
	}
	if (head1 != 0) head2 = head1;
	while(head2 != 0) {
		sum = head2->data + carry;
		carry = sum / 10;
		sum = sum % 10;
		cur->next = new Node(sum, 0);
		cur = cur->next;
		head2 = head2->next;
	}

	return head->next;
}



int main() {
	//test method1
	cout << "Method 1: \n";
	Node* list1 = 0;
	Node* list2 = 0;
	insertFromHead(list1, 1);
	insertFromHead(list1, 9);
	insertFromHead(list1, 9);
	insertFromHead(list2, 2);
	insertFromHead(list2, 0);
	insertFromHead(list2, 1);
	insertFromHead(list2, 1);
	
	printList(list1);
	printList(list2);
	cout << "The sum is: \n";
	printList(sumLists(list1, list2));

	return 0;
}