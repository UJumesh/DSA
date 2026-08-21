class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int low =0;
        int high =0;
        vector<int> result;
        unordered_map<char, int> f1;
        unordered_map<char, int> f2;
        for( int i =0; i<p.length(); i++){
            f1[p[i]]++;
        }
        while(high<s.size()){
            f2[s[high]]++;
            if(high-low+1==p.length()){
                if(f1==f2){
                   result.push_back(low);
                }
                f2[s[low]]--;
                if(f2[s[low]]==0){
                    f2.erase(s[low]);
                }
                low++;
            }
            high++;
        }
        return result;
    }
};