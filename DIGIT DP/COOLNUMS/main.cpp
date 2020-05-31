#include<bits/stdc++.h>
using namespace std;
int dp[10][40][40][2],a,b;
vector<int> digit;
void get(int x)
{
    digit.clear();
    while(x)
    {
        digit.push_back(x%10);
        x/=10;
    }
}
long long calc(int idx,int sumA,int sumB,int tight)
{
  if (idx==-1)
 return (sumA>0&&sumA==sumB);
  if (dp[idx][sumA][sumB][tight]!=-1&&!tight)
    return dp[idx][sumA][sumB][tight];
  long long ans=0;
  int limit=(tight)?digit[idx]:9;
   for (int i=0;i<=limit;i++)
   {
    int newtight=(digit[idx]==i)?tight:0;
     ans+=calc(idx-1,sumA+i,sumB,newtight);
     if (ok==1) return 0;
     ans+=calc(idx-1,sumA,sumB+i,newtight);
  }
 if (!tight)
  dp[idx][sumA][sumB][tight]=ans;
return ans;
}
long long solve(int x)
{
    get(x);
    return calc(digit.size()-1,0,0,1);
}
int main()
{
    memset(dp,-1,sizeof(dp));
   while(1)
   {
       cin>>a>>b;
       if (a==0&&b==0)
         break;
      cout<<solve(b)-solve(a-1)<<"\n";
   }
}
