class Solution {
public:
    int prod(int a){
        int m=1;
        int b;
        while(a>0){
            b=a%10;
            a /= 10;
            m= m*b;
        }
        return m;
    }
    int smallestNumber(int n, int t) {
        int ans;
        if(prod(n) % t ==0){
            return n;
        }
        else{
            while(prod(n)% t != 0 ){
                n++;

            }
        }
        return n;
        
    }
};