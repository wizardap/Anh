#include<bits/stdc++.h>
using namespace std;
map<string,int> pain;
map<string,int>::iterator it;
string sub[1000006];
string s,c;
int l,sum,n;
bool cmp(string a,string b)
{
    return a[0]<b[0];
}
int main()
{
    freopen("THU.inp","r",stdin);
    freopen("THU.out","w",stdout);
    while(cin>>s)
    {
        sub[++n]=s;
        if (pain.find(s)==pain.end())
            pain.insert(make_pair(s,n));
    }
    sort(sub+1,sub+1+n,cmp);
    if (pain.size()<2)
    {
        cout<<0;
        return 0;
    }
    for (int i=1; i<=n; i++)
        if (sub[i]!=sub[i-1])
        {
            c=sub[i];
            reverse(c.begin(),c.end());
            it=pain.find(c);
            if (it!=pain.end())
                sum++,pain.erase(c),pain.erase(sub[i]);
        }

    cout<<sum;



}
