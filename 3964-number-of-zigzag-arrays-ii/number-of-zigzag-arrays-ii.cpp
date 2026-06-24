class Solution {
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;
    using M = vector<vector<ll>>;

    M mul(M &a, M &b){
        int n = a.size();
        M c(n, vector<ll>(n));

        for(int i=0;i<n;i++)
            for(int k=0;k<n;k++)
                if(a[i][k])
                    for(int j=0;j<n;j++)
                        c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;

        return c;
    }

    M power(M a,long long e){
        int n=a.size();
        M r(n,vector<ll>(n));
        for(int i=0;i<n;i++) r[i][i]=1;

        while(e){
            if(e&1) r=mul(r,a);
            a=mul(a,a);
            e>>=1;
        }
        return r;
    }

    int zigZagArrays(int n, int l, int r) {

        int m=r-l+1;
        int S=2*m;

        vector<ll> base(S);

        for(int v=1;v<=m;v++){
            base[v-1]=v-1;
            base[m+v-1]=m-v;
        }

        if(n==2){
            ll ans=0;
            for(ll x:base) ans=(ans+x)%MOD;
            return ans;
        }

        M T(S,vector<ll>(S));

        for(int v=1;v<=m;v++){

            for(int u=1;u<v;u++)
                T[v-1][m+u-1]=1;

            for(int u=v+1;u<=m;u++)
                T[m+v-1][u-1]=1;
        }

        T=power(T,n-2);

        vector<ll> cur(S);

        for(int i=0;i<S;i++)
            for(int j=0;j<S;j++)
                cur[i]=(cur[i]+T[i][j]*base[j])%MOD;

        ll ans=0;
        for(ll x:cur) ans=(ans+x)%MOD;

        return ans;
    }
};