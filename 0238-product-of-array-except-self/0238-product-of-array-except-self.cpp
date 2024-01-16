class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0;
        for(int x : nums){
            if(x == 0){
                zeros++;
            } 
        }
        if(zeros > 1){
            return vector<int>(nums.size(),0);
        }
        else if( zeros == 1){
            int mult = 1;
            int idx = 0;
            
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0){
                    idx = i;
                    continue;
                }
                mult *= nums[i];
            }
            
            vector<int> ans(nums.size(), 0);
            ans[idx] = mult;
            return ans;
        }
        ////////////////////
        
        int mult = 1;
        for(int i = 0; i < nums.size(); i++){
            mult *= nums[i];
        }
        
        vector<int> ans;
        for(int x : nums){
            ans.push_back(mult/x);
        }
        return ans;
        
        
    }
};