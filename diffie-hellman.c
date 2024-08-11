#include<stdio.h>
long long int power(long long int a, long long int b,
long long int P)
{
if (b == 1)
return a;
else
return (((long long int)pow(a, b)) % P);
}
int main()
{
long long int P, G, x, a, y, b, ka, kb;
printf("Enter the value of prime number P: ");
scanf("%lld", &P);
printf("Enter the value of primitive root G: ");
scanf("%lld", &G);
printf("Enter the private key for user A (a): ");
scanf("%lld", &a);
printf("Enter the private key for user B (b): ");
scanf("%lld", &b);
printf("\nThe value of P : %lld\n", P);
printf("The value of G : %lld\n\n", G);
printf("The private key a for user A : %lld\n", a);
printf("The private key b for user B : %lld\n\n", b);
x = power(G, a, P); 
y = power(G, b, P); 
ka = power(y, a, P); 
kb = power(x, b, P); 
printf("Secret key for User A is : %lld\n", ka);
printf("Secret key for user B is : %lld\n", kb);
return 0;
}
