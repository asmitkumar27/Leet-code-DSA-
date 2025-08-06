class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            int current = numbers[i] + numbers[j];
    
            if (current == target) {
                return {i + 1, j + 1}; 
            } else if (current < target) {
                i++;
            } else {
                j--;
            }
        }

        return {};
    }
};