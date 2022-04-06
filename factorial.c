//Factorial using Recursion
#include<stdio.h>
long long factorial(long long n)
{
   if (n == 1)
      return 1;
   return n * factorial(n-1);
}
 
int main ()
{
  long long n = 40;
  printf("%lld", fib(n));
  return 0;
}