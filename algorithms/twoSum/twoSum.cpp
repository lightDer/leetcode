#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) == m.end()) {
                m[target-nums[i]] = i;
            }
            else {
                ret.push_back(m[nums[i]]+1);
                ret.push_back(i+1);
                break;

            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> v = s.twoSum({8, 3, 5, 7}, 15);

    for (int i : v)
        cout << i << endl;

    return 0;
}
