class Solution {
public:
    bool isPalindrome(string s) {
         int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(!isalnum(s[start])){
                cout<<"START:"<< start <<  "END:" << end<<endl ; 
                start++; 

                continue;
            }
            if(!isalnum(s[end])){
                cout<<"START:"<< start <<  "END:" << end<<endl ; 
                end--;
                continue;}
            if(tolower(s[start])!=tolower(s[end]))
                return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};