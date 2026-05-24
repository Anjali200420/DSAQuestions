class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> C(n, 0);
        for(int ind1 = 0; ind1 < n; ind1++){
            for(int ind2 = 0; ind2 < n; ind2++){
                if(A[ind1] == B[ind2]){
                    int ind = max(ind1, ind2);
                    C[ind] += 1;
                }
            }
        }

        for(int ind = 1; ind < n; ind++){
            C[ind] += C[ind-1];
        }

        return C;
    }
};