#include<stdio.h>
int main()
{
     // declare variables
     float p, t, r, interest;

     // take inputs
     printf("Enter principal amount(p), 
             time(t) and rate(r) values: ");
     scanf("%f %f %f",&p,&t,&r);

     // calculate simple interest
     interest = ( p*t*r ) / 100;

     // display result
     printf("interest = %.2f\n",interest);

     return 0;
}
