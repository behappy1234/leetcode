#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long base1=0, zero1=0;
        long long base2=0, zero2=0;

        for (int num: nums1) {
            base1 += num;
            if (num == 0) zero1++;
        }

        for (int num: nums2) {
            base2 += num;
            if (num == 0) zero2++;
        }

        if (zero1 == 0) {
            if (base2+zero2 > base1) return -1;
            if (zero2 == 0) {
                if (base1 == base2) return base1;
                return -1;
            }
            return base1;
        } else {
            if (zero2 == 0) {
                if (base1+zero1 > base2) return -1;
                return base2;
            }
            return max(base1+zero1, base2+zero2);
        }

        return -1;
    }
};

int main() {
    Solution solu;
    vector<int> nums1 = {2,0,2,0};
    vector<int> nums2 = {1,4};
    long long ret = solu.minSum(nums1, nums2);
    cout << ret << endl;
    return 0;
}
