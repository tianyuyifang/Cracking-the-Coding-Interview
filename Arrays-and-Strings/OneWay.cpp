#include <iostream>
#include <vector>
#include <string>

using namespace std;

// check if str1 and str2 only differ by one character with same length;
bool oneEditReplace(const string &str1, const string &str2) {   
	int changes = 0;
	int len = str1.length();
	for(int i=0; i<len; i++) {
		if (str1[i] != str2[i]) changes++;
		if (changes >= 2) return false;
	}
	return true;
}

// check if you can insert a character into str1 to make str2;
bool oneEditInsert(const string &str1, const string &str2) {  
	int changes = 0;
	int len = str1.length();
	int i, j;
	for(i=0; i<len; i++) {
		if (str1[i] != str2[j]) {
			i--;
			j++;
			changes++;
			if (changes >= 2) return false;
		}
	}
	return true;
}

bool oneEditAway(const string &str1, const string &str2) {
	int l1 = str1.length();
	int l2 = str2.length();
	if (l1 == l2) return oneEditReplace(str1, str2);
	else if (l1 == l2 - 1) return oneEditInsert(str1, str2);
	else if (l2 == l1 - 1) return oneEditInsert(str2, str1);
	else return false;
}


int main() {
	string s1 = "pale";
	string s2 = "ple";
	cout << "whether " << s2 << " can be obtained via one edit by " 
	<< s1 << ": " << endl;

	// s1 = "pales";
	// s2 = "pale";
	// cout << "whether " << s2 << " can be obtained via one edit by " 
	// << s1 << ": " << oneEditAway(s1,s2) << endl;

	// s1 = "pale";
	// s2 = "bale";
	// cout << "whether " << s2 << " can be obtained via one edit by " 
	// << s1 << ": " << oneEditAway(s1,s2) << endl;

	// s1 = "pale";
	// s2 = "bake";
	// cout << "whether " << s2 << " can be obtained via one edit by " 
	// << s1 << ": " << oneEditAway(s1,s2) << endl;

	// s1 = "pale";
	// s2 = "palesa";
	// cout << "whether " << s2 << " can be obtained via one edit by " 
	// << s1 << ": " << oneEditAway(s1,s2) << endl;

	return 0;		
}






