
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;

                int sum = nums.at(i) + nums.at(j);
                if (sum == target) {

                    int index1 = i;
                    int index2 = j;
                    if (i > j) {
                       index1 = j;
                       index2 = i;
                    }

                    ret.push_back(index1+1);
                    ret.push_back(index2+1);
                    return ret;
                }
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
