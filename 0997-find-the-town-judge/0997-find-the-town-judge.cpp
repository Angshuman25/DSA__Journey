class Solution {
public:
    int getCelebrity(vector<vector<int>>& M) {
        int n = M.size();
        stack<int> s;

        for(int i = 0; i < n; i++) {
            s.push(i);
        }

        while(s.size() >= 2) {
            int i = s.top();  s.pop();
            int j = s.top();  s.pop();

            if(M[i][j] == 0) {
                s.push(i);
            } else {   // M[i][j] == 1
                s.push(j);
            }
        }

        int celeb = s.top();  s.pop();

        for(int i = 0; i < n; i++) {
            if(i != celeb) {
                if(M[i][celeb] == 0 || M[celeb][i] == 1) {
                    return -1;
                }
            }
        }

        return celeb;
    }

    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> M(n , vector<int> (n , 0));

        for(int k = 0; k < trust.size(); k++) {
            int personA = trust[k][0] - 1;
            int personB = trust[k][1] - 1;
            M[personA][personB] = 1;
        }

        int ans = getCelebrity(M);

        if(ans != -1) {
            return ans + 1;
        }

        return -1;
    }
};