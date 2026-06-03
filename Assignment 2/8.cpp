class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        int j = 0;
        int tmp;
        for(int n: nums) {
            tmp = max(i + n, j);
            i = j;
            j = tmp;
        }
        return j;
    }
};