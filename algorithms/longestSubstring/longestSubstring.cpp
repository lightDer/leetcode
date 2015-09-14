#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		if (s.size() == 0) return 0;

		int maxLength = 0;
		auto index = s.begin();

		for (auto it = s.begin(); it != s.end(); ++it) {
			unordered_map<char, int> m;
			//cout << " ------------------------" << endl;
			for (auto jit = it; jit != s.end(); ++jit) {
				if (m.find(*jit) == m.end()) {
					int val = m.size();
					m.insert({(*jit), val});
					//cout << "jit: " << *jit << " val: " << val  << endl;
					//cout << "m size: " << m.size()  << endl;
				}
				else {
					if (m.size() > maxLength)
						maxLength = m.size();
					//cout << " >> inside length: " << length << endl;
					break;
				}

				if (m.size() > maxLength)
					maxLength = m.size();

			}
		}

		return maxLength;
	}

};


int main() {
	Solution sol;
	string s;
	int length = -1;


	length = sol.lengthOfLongestSubstring(s);
	cout << "s: "  << s << ", length: " << length << endl;
	return 0;
	
	s = "pwwkew";
	length = sol.lengthOfLongestSubstring(s);
	cout << "s: "  << s << ", length: " << length << endl;


	s = "3345678";
	length = sol.lengthOfLongestSubstring(s);
	cout << "s: "  << s << ", length: " << length << endl;


	s = "au";
	length = sol.lengthOfLongestSubstring(s);
	cout << "s: "  << s << ", length: " << length << endl;

	s = "ttttttt";
	length = sol.lengthOfLongestSubstring(s);
	cout << "s: "  << s << ", length: " << length << endl;

	s = "anviaj";
	length = sol.lengthOfLongestSubstring(s);
	cout << "s: "  << s << ", length: " << length << endl;

	s = "";
	length = sol.lengthOfLongestSubstring(s);
	cout << "s: "  << s << ", length: " << length << endl;


	return 0;
}
