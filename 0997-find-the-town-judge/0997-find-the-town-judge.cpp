class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       // Create a 1D Array of size n + 1 filled with 0s
       // We use size n + 1 so we can use people's actual names ( 1 to n ) as indices
       vector<int> scores(n + 1 , 0);

       // Step 1 : Loop through all trust pairs and update scores
       for(int k = 0; k < trust.size(); k++) {
           int personA = trust[k][0];   // The Person who trusts
           int personB = trust[k][1];   // The Person who being trusted

           scores[personA]--;   // personA loses a point( Judge dont trusts anyone )
           scores[personB]++;   // personB gains a point( Judges are trusted )
       }

       // Step 2 : Check who has a score of exactly n - 1
       for(int i = 1; i <= n; i++) {
           if(scores[i] == n - 1) {
              return i;   // Found the judge
           }
       }

       // If no one got a score of n - 1 , there is no judge
       return -1;
    }
};