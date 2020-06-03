#include<bits/stdc++.h>
using namespace std;
int x,n,sum,sumcp,c;
bool prime(int x)
{
    if (x<=1) return 0;
    for (int i=2;i<=sqrt(x);i++)
         if (x%i==0)
          return 0;
 return 1;
}
bool prime2(int a,int b)
{
    if (prime(a)==1&&prime(b)==1)
         return 1;
  return 0;
}
int main()
{
    cin>>n;
    x=n;
    while(x>0)
    {
        c=x%10;
        sum+=c;
        sumcp+=c*c*c;
        x/=10;
    }
     cout<<sumcp<<" "<<prime2(sum,n);

}
