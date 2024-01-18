class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        int sum = 0;
        mymap[0] = 1;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            count+= mymap[sum - k];
            mymap[sum]++;
            
            
        }
        return count;
    }
};