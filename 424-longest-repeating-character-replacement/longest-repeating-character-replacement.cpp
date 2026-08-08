class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen=0,l=0,r=0,mmf=0;
        int hash[26];
        while(r<s.size()){
            hash[s[r]-'A']++;
            mmf=max(mmf,hash[s[r]-'A']);
            while((r-l+1)-mmf>k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-mmf<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;

        
    }
};