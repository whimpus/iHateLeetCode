class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> mymap;
        mymap[0] = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            sum %= k;
            if(mymap.find(sum) != mymap.end()){
                if(i - mymap[sum] >= 2){
                    return true;
                }
            }else{
                mymap[sum % k]  = i;
            }
        }
        return false;
    }
};