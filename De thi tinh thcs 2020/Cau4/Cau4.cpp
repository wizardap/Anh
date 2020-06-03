#include<bits/stdc++.h>
using namespace std;
char t;
string a,b;
int d=1,so;
int main()
{
    cin>>a;
    cin>>b;
    for (int i=0;i<a.size()-1;i++)
        if (i+1<a.size()-2)
    {
        if (a[i]==a[i+1])
            d++;
       else {

        cout<<a[i]<<d;
        d=1;
       }
    }
    else
    {
        if (a[i]==a[i+1])
             {
                 d+=2;
                 cout<<a[i]<<d;
                 break;
             }
         else
         {
             cout<<a[i]<<d;
             cout<<a[i+1]<<1;
         }

    }
    cout<<endl;
    //-----------------------------------
    for (int i=0;i<b.size();i++)
        if (b[i]>='a') continue;
     else
        {
            t=b[i-1];
            while(b[i]>='0'&&b[i]<='9')
            {
                so=so*10+(b[i]-'0');
                i++;
            }
            for (int j=1;j<=so;j++)
                 cout<<t;
            i--;
            so=0;
        }



}
