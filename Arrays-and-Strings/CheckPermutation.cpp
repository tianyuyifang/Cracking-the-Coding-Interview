#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool checkPermutationSort(string str1, string str2) {
	if(str1.length() != str2.length())
		return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	for(int i=0; i<str1.length(); i++) {
		if(str1[i] != str2[i]) return false;
	}
	return true;
}

bool checkPermutation(const string& str1, const string& str2) {
	int l1 = str1.length();
	int l2 = str2.length();
	if(l1 != l2) return false;

	vector<int> storage(128,0);
	for(int i=0; i<l1; i++){
		int pos = str1[i];
		storage[pos]++;
	}
	for(int i=0; i<str2.length(); i++){
		int pos = str2[i];
		storage[pos]--;
		if(storage[pos] < 0) return false;
	}
	return true;
}


int main() {
	//test checkPermutationSort
	string str1 = "testest";
	string str2 = "estxest";
	cout << "Test checkPermutationSort: " << endl;
	if(checkPermutationSort(str1, str2)) 
		cout << str1 << " and " << str2 << " are permutation of each other.\n";
	else
		cout << str1 << " and " << str2 << " are not permutation of each other.\n";

	str1 = "hello";
	str2 = "eollh";
	if(checkPermutationSort(str1, str2)) 
		cout << str1 << " and " << str2 << " are permutation of each other.\n";
	else
		cout << str1 << " and " << str2 << " are not permutation of each other.\n";

	//test checkPermutation
	str1 = "testest";
	str2 = "estxest";
	cout << endl;
	cout << "Test checkPermutation:" << endl;
	if(checkPermutation(str1, str2)) 
		cout << str1 << " and " << str2 << " are permutation of each other.\n";
	else
		cout << str1 << " and " << str2 << " are not permutation of each other.\n";

	str1 = "hello";
	str2 = "eollh";
	if(checkPermutation(str1, str2)) 
		cout << str1 << " and " << str2 << " are permutation of each other.\n";
	else
		cout << str1 << " and " << str2 << " are not permutation of each other.\n";
	return 0;
}