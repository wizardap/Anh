#include<bits/stdc++.h>
using namespace std;
const int oo=1e9+7;
const int N=1e4+5;
long long ma,ma2=-oo,dp[N][256],a[9][N],nlst,lst[256];
int n;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=0; i<8; i++)
        for (int j=0; j<n; j++)
            cin>>a[i][j],ma2=max(ma2,a[i][j]);

}
void add_state()
{
    for (int s=0; s<(1<<8); s++)
    {
        bool ok=1;
        for (int i=0; i<7; i++)
            if (((s>>i)&3)==3)
            {
                ok=0;
                break;
            }
        if (ok)
            lst[nlst++]=s;
    }
}
long long sum(int i,int s)
{
    long long su=0;
    for (int c=0; c<8; c++)
        su+=(s>>c&1)*a[c][i];
    return su;
}
void solve()
{
    for (int i=0; i<nlst; i++)
        dp[0][lst[i]]=sum(0,lst[i]);
    for (int i=1; i<n; i++)
    {
        for (int j=0; j<nlst; j++)
        {
            dp[i][lst[j]]=-oo;
            for (int k=0; k<nlst; k++)
                if ((lst[j]&lst[k])==0)
                    dp[i][lst[j]]=max(dp[i][lst[j]],dp[i-1][lst[k]]+sum(i,lst[j]));
        }
    }
    ma=dp[n-1][0];
    for (int i=1; i<nlst; ++i)
        ma=max(ma,dp[n-1][lst[i]]);
    cout<<((ma==0&&ma2<0)?ma2:ma)<<"\n";
}
int main()
{
    init();
    add_state();
    solve();

}
