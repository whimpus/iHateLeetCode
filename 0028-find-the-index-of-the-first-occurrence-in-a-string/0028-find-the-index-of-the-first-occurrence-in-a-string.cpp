class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = 10000007;
        int base = 26;
        int hash = 0;
        int hash2 = 0;
        
        for(char x : needle){
            hash = (hash%m * base%m)%m;
            hash += (x - 'a' + 1);
            hash %= m;
        }
        int pw = 1;
        for(int i  = 0; i < haystack.size(); i++){
            char ch = haystack[i];
            
            hash2 = (hash2%m * base%m)%m;
            hash2 += (ch - 'a' + 1);
            hash2 %= m;
            cout<<"HASH1: "<<hash<<" HASH2 : "<<hash2<<endl;
            if(i >= needle.size()){ 
                hash2 = hash2 - ((haystack[i - needle.size()] - 'a'+ 1 )%m * pw%m)%m;
                hash2 = (hash2 + m)%m;
            }else{
                pw = (pw%m * base%m)%m;
            }
            cout<<"HASH1: "<<hash<<" HASH2 : "<<hash2<<endl;
            if(hash2 == hash){
                return i - needle.size() + 1;
            }
        }
        
        return -1;
    }
};