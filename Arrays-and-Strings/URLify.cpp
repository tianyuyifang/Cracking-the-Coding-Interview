#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void urlify(char str[], int len) {
	int addlen = 0;
	for(int i=0; i<len; i++) {
		if (str[i] == ' ')
			addlen++;
	}
	int j = len + addlen * 2 - 1;
	for(int i=len-1; i>=0; i--) {
		if (str[i] == ' ') {
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else 
			str[j--] = str[i];
	}
}

int main() {
	char str[] = "Mr John Smith    ";
	cout << "URL of " << str << " is ";
	urlify(str, 13);
	cout << str << endl;

	char str1[] = "My name is Charlie      ";
	cout << "URL of " << str1 << " is ";
	urlify(str1, 18);
	cout << str1 << endl;
	return 0;
}