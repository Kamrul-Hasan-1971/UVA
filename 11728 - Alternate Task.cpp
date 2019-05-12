#include<bits/stdc++.h>
using namespace std;

///...................................*****.................................................///
///                  Kamrul Hasan ( icthasan36@gmail.com )                                  ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

int ara[1005];

int SOD(int a)
{
    int sum=0;
    for(int i=1;i<=a;i++){
        if(a%i==0){
            sum=sum+i;
        }
    }
    return sum;
}

int main()
{
    int n,a,b,p,i,j;
    for(i=1;i<=1000;i++){
        ara[i]=SOD(i);
    }
    i=0;
    while(1)
    {
        p=0;
        scanf("%d",&a);
        if(a==0){
            break;
        }
        i++;
        for(j=1000;j>=1;j--){
            if(ara[j]==a){
                p=1;
                break;
            }
        }
        if(p==1){
            printf("Case %d: %d\n", i,j);
        }
        else{
            printf("Case %d: -1\n", i);
        }
    }
    return 0;
}
