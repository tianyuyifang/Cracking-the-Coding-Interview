#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getCharNumber(const char & c){     //get the corresponding number of char c;
	int a = (int)'a';
	int z = (int)'z';
	int A = (int)'A';
	int Z = (int)'Z';
 	int val = (int)c;
 	if (val >= a && val <= z)
 		return c-'a';
 	else if (val >= A && val <= Z)
 		return c-'A';

 	return -1;
}

vector<int> buildCharFrequencyTable(const string &phrase) {     //build frequency table of chars in phrase;
	vector<int> table(getCharNumber('z') - getCharNumber('a') + 1, 0);
	for(const char &c : phrase) {
		int x = getCharNumber(c);
		if (x != -1) 
			table[x]++;
	}
	return table;
}

bool checkMaxOneOdd(const vector<int> &table) {     //table has at most one char with odd frequency;
	bool foundOne = false;
	for(auto ele : table) {
		if(ele % 2 == 1) {
			if (foundOne) return false;
			else foundOne = true;
		}
	}
	return true;
}

bool isPermutationOfPalindrome(const string& phrase) {
	vector<int> table = buildCharFrequencyTable(phrase);
	return checkMaxOneOdd(table);
}


// Another approach to optimize the above one;

bool isPermutationOfPalindrome2(const string& phrase) {
	int Oddnum = 0;
	vector<int> table(26, 0);
	int index;
	for(const char& c : phrase) {
		index = getCharNumber(c);
		if (index != -1) {
			table[index]++;
			if (table[index] % 2 == 1) {
				Oddnum++;
			}
			else Oddnum--; 
		}
	}
	return (Oddnum <= 1);
}


int main() {
	//test method 1
	cout << "Testing method 1:\n";
	string phrase = "Tact Coa";
	if (isPermutationOfPalindrome(phrase))
		cout << phrase << " is permutation of palindrome.\n";
	else
		cout << phrase << " is not permutation of palindrome.\n"; 

	phrase = "Rats live on no evil star";
	if (isPermutationOfPalindrome(phrase))
		cout << phrase << " is permutation of palindrome.\n";
	else
		cout << phrase << " is not permutation of palindrome.\n"; 

	//test method 2
	cout << "Testing method 2:\n";
	phrase = "Tact Coa";
	if (isPermutationOfPalindrome2(phrase))
		cout << phrase << " is permutation of palindrome.\n";
	else
		cout << phrase << " is not permutation of palindrome.\n"; 

	phrase = "Rats live on no evil star";
	if (isPermutationOfPalindrome2(phrase))
		cout << phrase << " is permutation of palindrome.\n";
	else
		cout << phrase << " is not permutation of palindrome.\n"; 
}




