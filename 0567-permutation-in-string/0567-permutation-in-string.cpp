class Solution {
public:
    bool areMapsEqual( unordered_map<char, int>& map1, unordered_map<char, int>& map2) {
    if (map1.size() != map2.size()) {
        return false;
    }

    for (const auto& pair : map1) {
        auto it = map2.find(pair.first);
        if (it == map2.end() || it->second != pair.second) {
            return false;
        }
    }

    return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count1;
        unordered_map<char, int> count2;
        int l = 0;
        for(char x : s1){
            count1[x] += 1;
        }
        for(int i = 0; i < s2.size(); i++){
            count2[s2[i]] += 1;
            if(i - l + 1 > s1.size()){
                count2[s2[l]] -= 1;
                if(count2[s2[l]] == 0){
                    count2.erase(s2[l]);
                }
                l++;
            }
            if(areMapsEqual(count1, count2)){
                return true;
            }
        }
        return false;
        
    }
};