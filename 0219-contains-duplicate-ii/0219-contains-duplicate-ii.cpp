class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mymapu;
        int lo = 0;

        for(int high = 0; high < nums.size(); high++){
            mymapu[nums[high]] += 1;
            
            if(high - lo > k){
                mymapu[nums[lo]] -= 1;
                lo++;
            }
            if(mymapu[nums[high]] >= 2){
                return true;
            }
            
        }
        return false;
    }
};