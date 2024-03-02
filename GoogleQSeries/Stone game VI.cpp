class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
       int n = aliceValues.size();
        vector<pair<int, int>> stoneSum(n);
        
        // Store the sum of aliceValues and bobValues for each stone
        for (int i = 0; i < n; ++i) {
            stoneSum[i] = make_pair(aliceValues[i] + bobValues[i], i);
        }
        
        // Sort the stones in descending order of the sum of values
        sort(stoneSum.begin(), stoneSum.end(), greater<pair<int, int>>());
        
        int aliceScore = 0;
        int bobScore = 0;
        
        // Alternately pick stones starting from the highest sum
        for (int i = 0; i < n; ++i) {
            int stoneIndex = stoneSum[i].second;
            if (i % 2 == 0) {
                // Alice's turn
                aliceScore += aliceValues[stoneIndex];
            } else {
                // Bob's turn
                bobScore += bobValues[stoneIndex];
            }
        }
        
        // Compare scores to determine the winner
        if (aliceScore > bobScore) {
            return 1;
        } else if (aliceScore < bobScore) {
            return -1;
        } else {
            return 0;
        } 
    }
};