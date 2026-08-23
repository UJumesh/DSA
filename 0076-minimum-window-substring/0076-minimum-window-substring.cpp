class Solution {
public:
    string minWindow(string s, string t) {
        int low =0;
        int high =0;
        int len =INT_MAX;
        int count =0;
        int start =0;
        unordered_map<char, int>f1;
        unordered_map<char, int>f2;
        for(int i =0; i<t.length(); i++){
            f1[t[i]]++;
        }
        while(high< s.length()){
            f2[s[high]]++;
            if((f1.count(s[high]))&&(f2[s[high]]<=f1[s[high]])){
                count++;
            }
            while(count == t.length()){

            
            if(high-low+1<len){
                len = high - low +1;
                start =low;
            }
            if((f1.count(s[low]))&&(f2[s[low]]<=f1[s[low]])){
                count--;
              }
            
            f2[s[low]]--;
            if(f2[s[low]]==0){
                f2.erase(s[low]);
            }       

          low++;  
            }
     high++;    
     }
    

        
        if(len == INT_MAX){
            return "";
        
    }
      string result = s.substr(start, len);
return result;

    }
};