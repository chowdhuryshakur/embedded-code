#include <stdio.h>
long int operation(long int x, long int y, int o)
{
    switch(o)
    {
    case 1:
        return x+y;
        break;
    case 2:
        return x-y;
        break;
    case 3:
        if(x>y)
            return x;
        else
            return y;
        break;
    case 4:
        if(x<y)
            return x;
        else
            return y;
        break;
    case 5:
        return x>>y;
        break;
    case 6:
        return x<<y;
        break;
    default:
        printf("error\n");
    }
}
int main(){
long int a;
long int b;
int o;
long int r;
printf("Enter first number:");
scanf("%ld", &a);
printf("Enter second number:");
scanf("%ld", &b);
printf("Enter operation:");
scanf("%d", &o);
r = operation(a,b,o);
printf("%ld", r);
}
