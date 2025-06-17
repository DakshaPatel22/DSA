class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int maxl = 0, l = 0, r = 0;
        unordered_map<int, int> map;

        while (r < nums.size()) {
            map[nums[r]]++;
            while (map.size() > k) {
                map[nums[l]]--;
                if (map[nums[l]] == 0) {
                    map.erase(nums[l]);
                }
                l++;
            }
            if (map.size() <= k) {
                maxl = max(maxl, r - l + 1);
            }
            r++;
        }
        return maxl;
    }
};
