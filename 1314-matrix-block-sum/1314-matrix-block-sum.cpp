class Solution {
    vector<vector<int>> getpref(vector<vector<int>>& mat, int m , int n){
        vector<vector<int>> prefix(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){ //creating prefix
            for(int j = 0; j < n; j++){
                prefix[i][j]  = getval(i-1,j,prefix) + getval(i,j-1,prefix) - getval(i-1,j-1,prefix) + mat[i][j];
            }
        }
        return prefix;
    }
    int getval(int i, int j, vector<vector<int>>& vec){
        if(i < 0 || j < 0){
            return 0;
        }
        cout<<i <<" "<< j<<endl;
        return vec[i][j];
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> prefix = getpref(mat,m,n);
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = getval(min(i+k,m-1),min(j+k,n-1),prefix)
                            - getval(min(i+k, m-1),j-k-1,prefix) 
                            - getval(i-k-1,min(j+k, n-1),prefix)
                            + getval(i-k-1,j-k-1,prefix);
                
            }
        }
        return ans;
        
       
        
    }
};