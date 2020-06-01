#include<bits/stdc++.h>
using namespace std;
int dp[1<<17][20],a[20][20],n;
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin>>a[i][j];
    memset(dp,1000000007,sizeof(dp));
    for (int i=0; i<n; ++i)
        dp[1<<i][i]=0;
    for (int s=0; s<(1<<n); ++s)
        for (int i=0; i<n; ++i)
            if ((s&(1<<i)))
            {
                for (int j=0; j<n; ++j)
                    if ((i!=j)&&(s&(1<<j)))
                        dp[s][i]=min(dp[s][i],dp[s&~(1<<i)][j]+a[j][i]);
            }
    cout<<*min_element(dp[(1<<n)-1],dp[(1<<n)-1]+n)<<"\n";
}
