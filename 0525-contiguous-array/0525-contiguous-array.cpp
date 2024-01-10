class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> track = {{0,-1}};
        int count = 0;
        int highest = 0;
        for(int i = 0; i < nums.size(); i++)  
        {   
            //cout<<count<<" "<<track[count]<<endl;
            if(nums[i] == 0)
            {
                count--;
                
            }else
            {
                count++;
            }
            
            if(track.find(count) != track.end())
            {
                cout<< i << " - " << track[count]<<endl;
                if(highest < i - track[count])
                {   
                    //cout<<count << " "<< i<< " - " << track[count]<<endl;
                    highest = i - track[count];
                }
            }else{
                track[count] = i;
            }
                           
        }

        return highest;
    }
};