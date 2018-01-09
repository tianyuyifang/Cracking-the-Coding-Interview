#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isUniqueSort(string str) {
	sort(str.begin(), str.end());    //sort str;
	for(int i=1; i<str.length(); i++) {
		if(str[i] == str[i-1]) return false;
	}
	return true;
}



bool isUnique(const string & str) {
	vector<int> storage(128, 0);    //storage is used to calculate the occurrences of each char;
	for(int i=0; i<str.length(); i++) {
		int pos = str[i];
		if(storage[pos] == 0) storage[pos] = 1;    //record 1 if the char first occurs;
		else return false;
	}
	return true;
}

int main() {
	vector<string> words = {"isthisunique", "banana", "cat", "dogcat"};
	for(auto str : words) {
		if(isUniqueSort(str)) {
			cout << str << "'s characters are unique." << endl;
		}
		else
			cout << str << "'s characters are not unique." << endl;
	}

	for(auto str : words) {
		if(isUnique(str)) {
			cout << str << "'s characters are unique." << endl;
		}
		else
			cout << str << "'s characters are not unique." << endl;
	}
	return 0;
}