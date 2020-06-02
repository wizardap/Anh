#include<bits/stdc++.h>
using namespace std;
long long dp[16][10][16][2],a,b,d,k;
vector<int> digit;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>a>>b>>d>>k;
}
void get(long long x)
{
    digit.clear();
    while(x)
    {
        digit.push_back(x%10);
        x/=10;
    }
}
long long calc(int idx,int num,int ugly,int tight)
{
    if (idx==-1)

        return (ugly<=k);
    if (dp[idx][num][ugly][tight]!=-1&&tight!=1)
        return dp[idx][num][ugly][tight];
    long long res=0;
    int lmt=(tight)?digit[idx]:9;
    for (int i=0; i<=lmt; i++)
    {
        int newtight=(digit[idx]==i)?tight:0;
        int nugly=ugly;
        if ((abs(i-num)<=d)&&(idx!=digit.size()-1)&&(num!=0))
            nugly++;
        res+=calc(idx-1,i,nugly,newtight);
    }
    if (!tight)
        dp[idx][num][ugly][tight]=res;
    return res;
}
long long solve(long long x)
{
    get(x);
    return calc(digit.size()-1,0,0,1);
}
int main()
{
    init();
    cout<<solve(b)-solve(a-1);
}
