#include <iostream>
#include <unordered_map>
#include <random>

using namespace std;


struct Node {
	int data;
	Node *next;
	Node(): data(0), next(0) {}
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


void removeDups(Node *head) {
	unordered_map<int, int> counter;   //used to find duplicated elements;
	if ((head == 0) || (head != 0 && head->next == 0)) return;
	Node *p = head->next;
	Node *prev = head;
	counter[head->data] = 1;
	Node *temp;    //used to point the node to be deleted;
	while(p->next != 0) {
		if (counter.find(p->data) == counter.end()) {    //p->data is not in the counter;
			counter[p->data] = 1;
			prev = prev->next;
			p = p->next;
		}
		else {
			prev->next = p->next;
			temp = p;
			p = p->next;
			delete temp;
		}
	}
	if (counter.find(p->data) != counter.end()) {
		prev->next = 0;
		delete p;
	}
}

//Method without using hash table
void removeDupsNoBuffer(Node *head) {
	if ((head == 0) || (head != 0 && head->next == 0)) return;    //if there are less than one head
	Node *cur = head;
	Node *runner, *temp;
	while(cur->next != 0) {
		runner = cur;
		while(runner->next != 0) {
			if (runner->next->data == cur->data) {
				temp = runner->next;
				runner->next = runner->next->next;
				delete temp;
			}
			else {
				runner = runner->next;
			}
		}
		cur = cur->next;
	}

}




int main() {
	//test removeDups
	cout << "Method 1: \n";
	Node* head = 0;
	int min = 1;
	int max = 5;
	for(int i=0; i<=10; i++) {
		insertFromHead(head, random_range(min, max));
	}
	printList(head);
	removeDups(head);
	printList(head);

	//test removeDupsNoBuffer
	cout << "Method 2: \n";
	Node *head1 = 0;
	for(int i=0; i<=10; i++) {
		insertFromHead(head1, random_range(min, max));
	}
	printList(head1);
	removeDupsNoBuffer(head1);
	printList(head1);
}

