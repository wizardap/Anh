#include<bits/stdc++.h>
using namespace std;
long long s[1000005],a[1000005],cnt[1000005],n,k,res;
int main()
{
    cin>>n>>k;
    cnt[0]=1;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=(s[i-1]+a[i])%k;
        res+=cnt[s[i]];
        cnt[s[i]]++;
    }
    cout<<res;
}
