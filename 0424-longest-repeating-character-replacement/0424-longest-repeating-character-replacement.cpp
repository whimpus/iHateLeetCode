class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> hashmapu;
        int l = 0;
        int wiw = 0;
        for(int i = 0; i < s.size(); i++){
            hashmapu[s[i]] += 1; 
            int max_value = max_element(hashmapu.begin(), hashmapu.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second < b.second;
            })->second;
            if((i - l + 1) - max_value > k){
                hashmapu[s[l]] -= 1;
                l++;
            }
            if(wiw <= i - l + 1){
                wiw = i - l + 1;
            }   
        }
        return wiw;
    }
};
