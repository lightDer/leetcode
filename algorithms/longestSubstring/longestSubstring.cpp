#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		if (s.size() == 0) return 0;

		int maxLength = 0;
        int lastRepeatPos = -1;
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) != m.end() && lastRepeatPos < m[s[i]])
                lastRepeatPos = m[s[i]];
            if (i - lastRepeatPos > maxLength)
                maxLength = i - lastRepeatPos;
            m[s[i]] = i;
        }
		return maxLength;
	}
};


int main() {
	Solution sol;
	string s;
	int length = -1;

    s = "dvdf";
	length = sol.lengthOfLongestSubstring(s);
	cout << "s: "  << s << ", length: " << length << endl;

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
