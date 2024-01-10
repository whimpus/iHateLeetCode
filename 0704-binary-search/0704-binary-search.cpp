class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() -1 ;
        int mid = lo + (hi - lo) / 2;      
        while(lo <= hi){
            mid = lo + (hi - lo) / 2;
            if(target > nums[mid]){
                lo = mid + 1;

            }else if (target < nums[mid]){
                hi = mid - 1;

            }else{
                return mid;
            }

        }
        
        
        
        return -1;
    }
};