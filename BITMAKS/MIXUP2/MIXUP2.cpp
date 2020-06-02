#include<bits/stdc++.h>
using namespace std;
long long res,dp[1<<17][20],a[20],n,k;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<n; i++)
        dp[1<<i][i]=1;
}
void solve()
{
    for (int mask=1; mask<(1<<n); mask++)
    {
        for (int i=0; i<n; i++)
            if ((mask>>i)&1)
            {
                for (int j=0; j<n; j++)
                    if (((mask>>j)&1)&&abs(a[i]-a[j])>k)
                        dp[mask][i]+=dp[mask&~(1<<i)][j];
            }
    }
    for (int i=0; i<n; i++)
        res+=dp[(1<<n)-1][i];
    cout<<res<<"\n";
}

int main()
{
    init();
    solve();
}
