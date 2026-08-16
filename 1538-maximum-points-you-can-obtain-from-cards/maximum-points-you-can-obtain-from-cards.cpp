class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ls=0,rs=0,maxs=0;
        for(int i=0;i<k;i++){
            ls=ls+cardPoints[i];
        }
        maxs=ls;
        for(int i = k-1;i>=0;i--){
            rs=rs+cardPoints[n-1];
            ls=ls-cardPoints[i];
            n--;
            maxs=max(maxs,ls+rs);

        }
        return maxs;
        
    }
};