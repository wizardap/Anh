#include<bits/stdc++.h>
using namespace std;
int num,ma,uoc,x,even[10004],odd[10004],a,b,n,a1,b1;
int countdivisor(int x)
{
    int cnt=0;
    for (int i=1;i<=sqrt(x);i++)
         if (x%i==0)
    {
        if (x/i==i)
             cnt++;
        else cnt+=2;
    }
    return cnt;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        uoc=countdivisor(x);
        if (x%2==0)
        {
            a++;
            even[a]=x;
        }
        else
        {
            b++;
            odd[b]=x;
        }
      if (uoc>ma)
      {
          ma=uoc;
          num=x;
      }
    }
    sort(even+1,even+1+a);
    sort(odd+1,odd+1+b);
   for (int i=1;i<=b;i++)
     cout<<odd[i]<<" ";
   for (int i=1;i<=a;i++)
     cout<<even[i]<<" ";
    cout<<endl;
    cout<<num;

}
