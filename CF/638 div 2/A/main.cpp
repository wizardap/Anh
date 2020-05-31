#include<bits/stdc++.h>
using namespace std;
int s1,s2,n,t;
void solve()
{
    s1=0,s2=0;
     cin>>n;
     for(int i=1;i<=n;++i)
         if (i<n/2||i==n) s1+=1<<i;
     else s2+=1<<i;
     //cout<<s1<<" "<<s2<<endl;
     cout<<abs(s1-s2)<<endl;
}
int main()
{
     cin>>t;
     while(t--)
        solve();
}
