class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int left = 0;
        for(int x : nums){
            total += x;
        }
        for(int i = 0; i < nums.size(); i++){
            if(total - nums[i] - left == left){
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};