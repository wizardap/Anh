#include<bits/stdc++.h>
using namespace std;
long long dp[1<<20],a[21][21],way[1<<20],k,n;
void init()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
    cin>>n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin>>a[i][j];
}
void solve()
{
    way[0]=1;
    for(int state=1; state<(1<<n); state++)
    {
        k=__builtin_popcount(state)-1;
        for (int i=0; i<n; i++)
        {
            if (((state>>i)&1)==1)
            {
                if (dp[state]<dp[state&~(1<<i)]+a[k][i])
                    dp[state]=dp[state&~(1<<i)]+a[k][i],way[state]=way[state&~(1<<i)];
                else if (dp[state]==dp[state&~(1<<i)]+a[k][i])
                    way[state]+=way[state&~(1<<i)];

            }
        }
    }
    cout<<dp[(1<<n)-1]<<" "<<way[(1<<n)-1];
}
int main()
{
    init();
    solve();
}
