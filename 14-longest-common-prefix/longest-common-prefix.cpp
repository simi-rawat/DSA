class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        //int k=0;
        for(int i=0;i<strs[0].size();i++){
            char ch= strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(i>strs[j].size() || ch!=strs[j][i]){
                    //ans.push_back(ch);
                    //k++;
                    return ans;
                }
            }
            ans.push_back(ch);
        }
        if(strs.size()==1 || strs[0]==""){
            ans=strs[0];
        }
        return ans;
    }
};