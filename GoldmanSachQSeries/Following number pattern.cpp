class Solution {
public:
    string printMinNumberForPattern(string S) {
        stack<int> st;
        string result;
        int n = S.length();

        // Initialize counter for the sequence of increasing numbers
        int counter = 1;

        for (int i = 0; i <= n; ++i) {
            st.push(counter++);
            
            if (i == n || S[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }

        return result;
    }
};
