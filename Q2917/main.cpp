#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        // unordered_map<int, int> bitCnt;
        // for (int num: nums) {
        //     int b = 0;
        //     int tmp = 1;
        //     while (tmp <= num) {
        //         if ((tmp & num) == tmp) bitCnt[b]++;
        //         b++;
        //         tmp <<= 1;
        //     }
        // }

        // int ret = 0;
        // for (auto &[key, val]: bitCnt) {
        //     if (k <= val) ret += pow(2, key);
        // }

        int ret = 0;
        for (int i=0; i<31; i++) {
            int cnt = 0;
            for (int num: nums) {
                num >>= i;
                if ((num & 1) == 1) cnt++;
            }
            if (cnt >= k) ret += (1 << i);
        }

        return ret;
    }

};

int main() {
    Solution solu;
    vector<int> nums = {7,12,9,8,9,15};
    int k = 4;
    int ret = solu.findKOr(nums, k);
    cout << ret << endl;
    return 0;
}
