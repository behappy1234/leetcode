#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int minNum = INT_MAX;
        for (int num: nums) {
            cnt[num]++;
        }
        for (auto &[key, val]: cnt) {
            minNum = min(minNum, val);
        }

        int ret = 0;

        for (int k=minNum; k>=1; k--) {
            bool canSplit = true;
            for (auto &[key, val]: cnt) {
                int q = val / k;
                int r = val % k;
                if (q < r) {
                    canSplit = false;
                    break;
                }
            }

            if (canSplit) {
                for (auto &[key, val]: cnt) {
                    if (val % (k+1) == 0) {
                        ret += val / (k+1);
                    } else {
                        ret += val / (k+1) + 1;
                    }
                }
                break;
            }
        }

        return ret;
    }
};

int main() {
    Solution solu;
    vector<int> nums = {10,10,10,3,1,1};
    int ret = solu.minGroupsForValidAssignment(nums);
    cout << ret << endl;
    return 0;
}
