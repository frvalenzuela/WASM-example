// C code to implement Fibonacci series
// Example extracto from https://www.geeksforgeeks.org/recursion/
#include<stdio.h>
long long fib(long long n)
{
   // Stop condition
    if (n == 0)
        return 0;
 
    // Stop condition
    if (n == 1 || n == 2)
        return 1;
 
    // Recursion function
    else
        return (fib(n - 1) + fib(n - 2));
}
 
int main ()
{
  long long n = 40;
  printf("%lld\n", fib(n));
  return 0;
}