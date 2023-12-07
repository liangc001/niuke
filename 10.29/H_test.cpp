#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
    long long t,p[55],a,b,n,k,s,i;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        k=1;
        for(i=0;i<n;i++)
            cin>>p[i];
        for(i=0;i<n;i++)
        {
            s=p[i]/2;
            if(b>=s&&s>0)
            {
                b=b-s;
                p[i]=p[i]-2*s;
            }
            if(b<s)
            {
                p[i]=p[i]-2*b;
                b=0;
            }
            if(p[i]>a)
            {
                int x=p[i]-a;
                b=b-x;
                p[i]=p[i]-x;
                if(b<0)
                {
                    k=0;
                    break;
                }
            }
           if(p[i]<=a)
           {
               a=a-p[i];
               p[i]=0;
           }
           else
           {
               k=0;
               break;
           }
        }
        if(k)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
    return 0;
}
