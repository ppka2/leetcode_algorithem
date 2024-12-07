// Calculate the binary digit difference between two numbers using the XOR operation.
// same as 2220
class Solution {
public:
    int popcount(int x) {
        int cnt = 0;
        while (x) {
            x = x & (x - 1);
            cnt++;
        }
        return cnt;
    }
    int hammingDistance(int x, int y) { return popcount(x ^ y); }
};