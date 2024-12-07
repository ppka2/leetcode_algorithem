//  Construct a number with all bits set to 1 in binary.
class Solution {
public:
    int findComplement(int num) {
        int tmp = 1;
        while (tmp < num) {
            tmp <<= 1;
            tmp += 1;
        }
        return (tmp ^ num);
    }
};