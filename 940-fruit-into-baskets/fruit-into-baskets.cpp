class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen=0;
        int left=0;
        //int f=0,no=0;
        map<int,int> mpp;
        for(int right = 0;right<fruits.size();right++){
            mpp[fruits[right]]++;
            while(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0)
                    mpp.erase(fruits[left]);
                left++;
            }           
            
            maxlen= max(maxlen,right-left+1);
        }
        return maxlen;
        
    }
};