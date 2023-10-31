#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        unordered_map<int, int> cnt;

        for (int i=n-1; i>=0; i--) {
            cnt[citations[i]] = n-i;
        }

        int h = citations[n-1];
        int key = citations[n-1];
        while (h >= 0) {
            if (cnt.find(h) != cnt.end()) {
                key = h;
            }

            if (cnt[key] >= h) {
                return h;
            }

            h--;
        }

        return 0;
    }
};

int main() {
    vector<int> citations = {1,2,2};
    Solution solu;
    int h = solu.hIndex(citations);
    cout << h << endl;
    return 0;
}
