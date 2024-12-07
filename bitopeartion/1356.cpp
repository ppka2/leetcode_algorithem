
// popcount 实现 计算 二进制下1的个数

class Solution {
public:
    int popcount(int x) {
        int count = 0;
        while (x) {
            x = x & (x - 1);
            count++;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            return popcount(a) == popcount(b) ? a < b
                                              : popcount(a) < popcount(b);
        });
        return arr;
    }
};