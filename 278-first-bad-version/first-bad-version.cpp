// The API isBadVersion is already defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2; // overflow avoid
            if (isBadVersion(mid)) {
                high = mid; // first bad ho sakta hai ya uske pehle
            } else {
                low = mid + 1; // mid good hai, to bad mid ke baad hoga
            }
        }
        return low; // ya high, dono equal honge
    }
};
