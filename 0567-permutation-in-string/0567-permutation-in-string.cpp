class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int low =0;
        int high =0;
        int n = s1.length();
        unordered_map<char , int>f1;
        unordered_map<char , int>f2;
        if(n>s2.length()){
            return false;
        }
        for(int i=0; i<n; i++){
         f1[s1[i]]++;
        } 
         while(high<s2.length()){
            f2[s2[high]]++;
            
            if(high-low +1 == n){
                if(f1==f2){
                return true;
                }

            
               f2[s2[low]]--;
               if(f2[s2[low]]==0){
                f2.erase(s2[low]);
               }
               low++;
            }
            high++;
         }
        
return false;
        
    }
};