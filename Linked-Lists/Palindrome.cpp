#include <iostream>
#include <random>
#include <stack>

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


//Method 1: reverse and check equality
Node * reverseAndClone(Node *head) {
	Node *newHead = 0;
	while (head != 0) {
		Node *node = new Node();
		node->data = head->data;
		node->next = newHead;
		newHead = node;
		head = head->next;
	}
	return newHead;
}
bool isEqual(Node *head1, Node *head2) {
	while((head1 != 0) && (head2 != 0)) {
		if (head1->data != head2->data) return false;
		head1 = head1->next;
		head2 = head2->next;
	}
	if ((head1 != 0) || (head2 != 0)) return false;
	return true;
}
bool method1(Node *head) {
	Node *reverse = reverseAndClone(head);
	return isEqual(head, reverse);
}

//Method 2: using a stack
bool method2(Node *head) {
	if ((head == 0) || (head != 0 && head->next == 0)) return true;
	stack<int> s;
	Node *p1 = head, *p2 = head;

	while(p2 != 0 && p2->next != 0) {
		s.push(p1->data);
		p1 = p1->next;
		p2 = p2->next->next;
	}
	if (p2 != 0) p1 = p1->next;

	while(p1 != 0) {
		if (p1->data != s.top()) return false;
		else {
			p1 = p1->next;
			s.pop();
		}
	}
	return true;
}

//Method 3: recursive
class Result {
public:
	Node * last;
	bool result;
	Result(Node *la, bool re): last(la), result(re) {}
};
int length(Node *head) {
	if (head == 0) return 0;
	int size = 0;
	while (head != 0) {
		size++;
		head = head->next;
	}
	return size;
}
// return last node and whether it is a palindrome
Result isPalindrome(Node *head, int len) {
	if (len == 1) {
		return Result(head->next, true);
	}
	else if (len == 2) {
		return Result(head->next->next, head->data == head->next->data);
	}

	Result res = isPalindrome(head->next, len-2);

	if (res.result == false) {
		res.last = res.last->next;
		return res;

	}

	res.result = res.last->data == head->data;
	res.last = res.last->next;
	return res;
}
bool method3(Node *head) {
	int len = length(head);
	Result res = isPalindrome(head, len);
	return res.result;
}



int main() {
	//test method1
	cout << "Method 1: \n";
	Node* head = 0;
	insertFromHead(head, 1);
	insertFromHead(head, 2);
	insertFromHead(head, 3);
	insertFromHead(head, 1);
	insertFromHead(head, 3);
	insertFromHead(head, 2);
	insertFromHead(head, 3);
	
	printList(head);
	cout << "Is it palindrome: " << method1(head) << endl;

	//test method2
	cout << "Method 2: \n";
	Node* head2 = 0;
	insertFromHead(head2, 1);
	insertFromHead(head2, 2);
	insertFromHead(head2, 3);
	insertFromHead(head2, 1);
	insertFromHead(head2, 1);
	insertFromHead(head2, 3);
	insertFromHead(head2, 2);
	insertFromHead(head2, 1);
	
	printList(head2);
	cout << "Is it palindrome: " << method2(head2) << endl;

	//test method3
	cout << "Method 3: \n";
	Node* head3 = 0;
	insertFromHead(head3, 1);
	insertFromHead(head3, 2);
	insertFromHead(head3, 3);
	insertFromHead(head3, 1);
	insertFromHead(head3, 2);
	insertFromHead(head3, 3);
	insertFromHead(head3, 2);
	insertFromHead(head3, 1);
	
	printList(head3);
	cout << "Is it palindrome: " << method3(head3) << endl;



	return 0;
}





