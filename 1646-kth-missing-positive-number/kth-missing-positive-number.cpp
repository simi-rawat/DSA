class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> mis(arr.size());
        for(int i=0;i<arr.size();i++){
            mis[i]=arr[i]-(i+1);
        }
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(arr[mid] - mid - 1 < k)
                low = mid + 1;
            else
                high = mid - 1;

        }
        if(high==-1) return k;

        int left = k - (arr[high] - high - 1);
        return arr[high] + left;
        
    }
};