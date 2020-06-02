#include<bits/stdc++.h>
using namespace std;
const int oo=-4e5;
const int N=1e4+5;
int lst[]= {0,1,2,4,5,8,9,10};
int a[5][N],f[N][11],n;
int ma=oo,ma2=-4e5;
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1; i<=4; i++)
        for (int j=1; j<=n; ++j)
            cin>>a[i][j],ma2=max(ma2,a[i][j]);
}
int sum(int i,int j)
{
    int s=0;
    for (int t=0; t<4; t++)
        if ((j&(1<<t))!=0)
            s+=a[t+1][i];
    return s;
}
void solve()
{
    for (int i=0; i<8; i++)
        f[1][lst[i]]=sum(1,lst[i]);
    for (int i=2; i<=n; i++)
    {
        for (int j=0; j<8; j++)
        {
            f[i][lst[j]]=oo;
            for (int k=0; k<8; k++)
                if ((lst[j]&lst[k])==0)
                    f[i][lst[j]]=max(f[i][lst[j]],f[i-1][lst[k]]+sum(i,lst[j]));
        }
    }
    ma=max(f[n][lst[0]],ma);
    for (int i=1; i<8; i++)
        ma=max(f[n][lst[i]],ma);
    cout<<((ma==0&&ma2<0)?ma2:ma)<<"\n";
}

int main()
{
    init();
    solve();
}
