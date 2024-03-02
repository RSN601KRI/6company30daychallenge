class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length(), l = 0, r = n - 1, mid, peak_pos;
    // Find peak position
    while (l < r) {
        mid = l + (r - l) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
            l = peak_pos = mid + 1;
        } else {
            r = mid;
        }
    }
    // Find left part
    l = 0;
    r = peak_pos;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (mountainArr.get(mid) < target) {
            l = mid + 1;
        } else if (mountainArr.get(mid) > target) {
            r = mid - 1;
        } else {
            return mid;
        }
    }
    // Find right part
    l = peak_pos;
    r = n - 1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (mountainArr.get(mid) > target) {
            l = mid + 1;
        } else if (mountainArr.get(mid) < target) {
            r = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}
};