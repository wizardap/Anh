#include<bits/stdc++.h>
using namespace std;
long long a[105],n,m,d;
void solve(int idx,long long sum)
{
    if (sum>m) return;
    if (sum==m)
    {
        d++;
        return;
    }
  if (idx>n)
  {
      if (sum==m) d++;
      return ;
  }
   solve(idx+1,sum+a[idx]);
   solve(idx+1,sum);
}
int main()
{
     cin>>n>>m;
     for (int i=1;i<=n;i++)
         cin>>a[i];
         solve(1,0);
    cout<<d;
}
