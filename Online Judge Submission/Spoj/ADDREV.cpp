#include<stdio.h>

int main()
{
    int n1,n2,n3=0,n4=0,sum1,sum2=0,t;
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d%d",&n1,&n2);
        while(n1!=0)
        {
            n3=((n1%10)+n3)*10;
            n1=n1/10;
        }
        n3=n3/10;
        while(n2!=0)
        {
            n4=((n2%10)+n4)*10;
            n2=n2/10;
        }
        n4=n4/10;
        sum1=n3+n4;
        while(sum1!=0)
        {
            sum2=((sum1%10)+sum2)*10;
            sum1=sum1/10;
        }
        sum2=sum2/10;
        printf("%d\n",sum2);
        t--;
        n3=0,n4=0,sum2=0;
    }



    return 0;
}
