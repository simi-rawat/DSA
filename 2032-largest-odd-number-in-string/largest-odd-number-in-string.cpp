class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        for(int i = num.size()-1;i>=0;i--){
            if(num[i]=='1'|| num[i]=='3'||num[i]=='5'||num[i]=='7'||num[i]=='9'){
                for(int j = 0;j<=i;j++){
                    ans.push_back(num[j]);
                }
                break;
            }
        }
        return ans;
        
    }
};