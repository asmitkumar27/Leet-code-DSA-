class NumArray {
public:
    vector<int> seg;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, nums);
    }

    void build(int idx, int low, int high, vector<int>& nums) {
        if (low == high) {
            seg[idx] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateHelper(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (pos <= mid)
            updateHelper(2 * idx + 1, low, mid, pos, val);
        else
            updateHelper(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void update(int index, int val) {
        updateHelper(0, 0, n - 1, index, val);
    }

    int query(int idx, int low, int high, int l, int r) {
        if (r < low || high < l) return 0; // no overlap
        if (l <= low && high <= r) return seg[idx]; // complete overlap

        int mid = (low + high) / 2;
        return query(2 * idx + 1, low, mid, l, r) +
               query(2 * idx + 2, mid + 1, high, l, r);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};