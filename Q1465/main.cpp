#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int modulo = pow(10, 9) + 7;
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        int maxHeight = horizontalCuts[0];
        maxHeight = max(maxHeight, h - horizontalCuts[n-1]);
        int maxWidth = verticalCuts[0];
        maxWidth = max(maxWidth, w - verticalCuts[m-1]);

        for (int i=0; i<=n-2; i++) {
            maxHeight = max(maxHeight, horizontalCuts[i+1] - horizontalCuts[i]);
        }

        for (int i=0; i<=m-2; i++) {
            maxWidth = max(maxWidth, verticalCuts[i+1] - verticalCuts[i]);
        }

        long f = maxHeight;
        f = (f * maxWidth) % modulo;

        return (int) f;
    }
};

int main() {
    Solution solu;
    int h = 5, w = 4;
    vector<int> horizontalCuts = {1,2,4};
    vector<int> verticalCuts = {1,3};
    int ret = solu.maxArea(h, w, horizontalCuts, verticalCuts);
    cout << ret << endl;
    return 0;
}
