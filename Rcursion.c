#include <stdio.h>
int fact(int);
int main()
{
    int n, f;
    printf("\nEnter the number whose factorial you want to calculate?");
    scanf("%d", &n);
    f = fact(n);
    printf("factorial = %d\n", f);
}
int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}