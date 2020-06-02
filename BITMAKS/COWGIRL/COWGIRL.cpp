#include<bits/stdc++.h>
using namespace std;
long long dp[1<<6][40];
unsigned long long res=0;
int m,n,t;
void init()
{
    cin>>m>>n;
    if (m<n) swap(m,n);
    for (int i=0;i<(1<<n);i++)
         dp[i][0]=1;
}
bool ok(int a,int b)
{
    for (int i=1;i<n;i++)
    {
        int x=(a&(1<<i))!=0,y=(a&(1<<(i-1)))!=0;
        int z=(b&(1<<i))!=0,w=(b&(1<<(i-1)))!=0;
     if (x==y&&y==z&&z==w)
          return 0;
    }
    return 1;
}
void solve()
{
    res=0;
     for (int i=1;i<m;i++)
    for (int mask=0;mask<(1<<n);mask++)
    {
        dp[mask][i]=0;
        for (int mask2=0;mask2<(1<<n);mask2++)
                 if (ok(mask,mask2))
                    dp[mask][i]+=dp[mask2][i-1];
    }
for (int i=0;i<(1<<n);i++)
     res+=dp[i][m-1];
     cout<<res<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
     init();
     solve();
    }
}
