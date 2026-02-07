#include <iostream>
#include <string>

using namespace std;

string longest_common_substring(string, string);

int main()
{
	string first = "the rain";
	string second = "in spain";

	cout << "Longest Common Substring: " << longest_common_substring(first, second) << endl;

	return 0;
}

string longest_common_substring(string a, string b) {
	string best = "";
	for (int i = 0; i < a.length(); i++) {
		int k = a.length() - i;
		for (int l = 0; l < a.length(); l++) {
			string s = a.substr(l, k);
			s.push_back('$');
			for (int j = 0, m = 0; j < b.length(); j++) {
				if (s[m] == b[j] && s[m + 1] == '$')
					s.pop_back();
				else if (s[m] == b[j])
					m++;
				else
					m = 0;

				if (m == s.length() - 1 && s.length() > best.length())
					best = s;
			}
			cout << "Testing... " << s << endl;
		}
	}

	return best;
}