class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, one = 0, two = 0;

        // Step 1: Count occurrences
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zero++;
            else if (nums[i] == 1) one++;
            else two++;
        }

        // Step 2: Overwrite array
        int i = 0;
        while (zero--) nums[i++] = 0;
        while (one--)  nums[i++] = 1;
        while (two--)  nums[i++] = 2;
    }
};