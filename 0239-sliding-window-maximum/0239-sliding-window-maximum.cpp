class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deez;
        vector<int> ans;

        int l = 0;
        int r = 0;                 
        while(r < nums.size()){
            while(!deez.empty() && nums[deez.back()] <= nums[r]){
                deez.pop_back();
            }
            deez.push_back(r);
            if(l > deez.front()){
                deez.pop_front();      
            }
            if (r + 1 >= k){
                ans.push_back(nums[deez.front()]);
                l++;
            }
            r++;



        }
        return ans;
    }
};