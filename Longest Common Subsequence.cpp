#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

string longest_common_subsequence(string, string);

int main()
{
	string first = "abcdefgh";
	string second = "zapcieg";

	cout << "Longest Common Subsequence: " << longest_common_subsequence(first, second) << endl;

	return 0;
}

//string longest_common_subsequence(string a, string b) {
//	string best = "";
//	string shorter = a, longer = b;
//
//	if (shorter.length() > longer.length())
//		swap(shorter, longer);
//
//	string set;
//	int power_length = pow(2, shorter.length());
//	vector<string> subsets (power_length, set);
//
//	for (int i = 0; i < power_length; i++) {
//		for (int j = 0; j < shorter.length(); j++) {
//			if(((i >> j) & 1) == 1)
//				subsets[i].push_back(shorter[j]);
//		}
//	}
//
//	for (int i = 0; i < power_length; i++) {
//		for (int j = 0, k = 0; j < subsets[i].length() && k < longer.length(); k++) {
//			if (subsets[i][j] == longer[k])
//				j++;
//			if (j == subsets[i].length() && subsets[i].length() > best.length()) {
//				best = subsets[i];
//			}
//			//cout << i << ", " << j << ", " << k << endl;
//		}
//		cout << subsets[i] << endl;
//	}
//
//	return best;
//}

string longest_common_subsequence(string a, string b) {
	string best = "";
	string shorter = a, longer = b;

	if (shorter.length() > longer.length())
		swap(shorter, longer);

	string set;
	int power_length = pow(2, shorter.length());
	vector<string> subsets(power_length, set);

	for (int i = 0; i < power_length; i++) {
		for (int j = 0; j < shorter.length(); j++) {
			if (((i >> j) & 1) == 1)
				subsets[i].push_back(shorter[j]);
		}
		for (int j = 0, k = 0; j < subsets[i].length() && k < longer.length(); k++) {
			if (subsets[i][j] == longer[k])
				j++;
			if (j == subsets[i].length() && subsets[i].length() > best.length()) {
				best = subsets[i];
			}
			//cout << i << ", " << j << ", " << k << endl;
		}
		cout << subsets[i] << endl;
	}

	return best;
}