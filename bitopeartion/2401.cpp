// Set Theory 
class Solution {
public:
    int longestNiceSubarray(vector<int> &nums) {
        int ans = 0;
        for (int left = 0, right = 0, or_ = 0; right < nums.size(); right++) {
            while (or_ & nums[right]) // 有交集
                or_ &= ~nums[left++]; // 从 or 中去掉集合 nums[left]
            or_ |= nums[right]; // 把集合 nums[right] 并入 or 中
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

