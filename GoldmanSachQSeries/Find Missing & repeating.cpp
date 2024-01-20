class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> result;

        // Find the repeating element using a set
        unordered_set<int> numSet;
        int repeatingNumber = -1;
        for (int num : arr) {
            if (numSet.find(num) != numSet.end()) {
                repeatingNumber = num;
                break;
            }
            numSet.insert(num);
        }

        result.push_back(repeatingNumber);

        // Find the smallest positive missing number
        for (int i = 0; i < n; ++i) {
            int correctIndex = abs(arr[i]) - 1;
            if (correctIndex < n && arr[correctIndex] > 0) {
                arr[correctIndex] = -arr[correctIndex];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (arr[i] > 0) {
                result.push_back(i + 1);
                break;
            }
        }

        return result;
    }
};
