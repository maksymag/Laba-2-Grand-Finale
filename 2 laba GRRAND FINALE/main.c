#include <stdio.h>

int main()
{

double a, b, h, x, y, p, l, t, pr,  z, y1, i, y2, k, hf, s, s1, s2;
unsigned int   n, v;
y=0;
z=0;

do
{
printf("Variant 1: left triangle metod;\n");
printf("Variant 2: right triangle metod;\n");
printf("Variant 3: trapezoid metod;\n");
printf("Variant 4: Simpson's metod;\n");
printf("If you want find N, use 1 or 2 variant\n");
printf("Switch your variant:");
scanf("%d", &v);
printf("\nx1 must be less than x2;\n");
printf("\nEnter x1 (down number of x):");
scanf("%lf", &a);

printf("\nEnter x2(hight number of x):");
scanf("%lf", &b);
}
while (a>=b );

printf("\nEnter number of promizkiv rozbittia: ");
scanf("%d", &n);

printf("\nEnter number of pohibka (10^-5<=p<=10^-3): ");
scanf("%d", &p);




h=(b-a)/n;
hf=h;
z=a;

switch (v)
     {

case 1:
//left triangle metod
for ( i = 0; i < n; i++ )
{
    a=(z+h*i);
    y=(1+sqrt(a))/(a*a)+y;
}

l=y*h;
y1=0;
printf("\nl=%lf\n", l);
printf("l - value of integral couted by left triangle metod\n");

//pohibka of left triangle metod
do
 {
n++;
h=(b-a)/n;
for ( i = 0; i < n; i++ )
   {
    a=(z+h*i);
    y1=(1+sqrt(a))/(a*a)+y1;
   }

h=(b-a)/(n+2);

for ( i = 0; i < n+2; i++ )
    {
    a=(z+h*i);
    y2=(1+sqrt(a))/(a*a)+y2;
    }
 }
while (fabs(y2-y1)<=p);


printf ("\ni=%lf\n", i);
printf ("i - pohibka in left triangle metod \n ", i);

break;

case 2:
//right triangle metod
y1=0;
for ( i = 1; i < n+1; i++ )
{
    a=(z+h*i);
    y1=(1+sqrt(a))/(a*a)+y1;
}

pr=y1*h;
printf("\npr=%lf\n", pr);
printf("l - value of integral couted by right triangle metod\n");

k=y1;
y1=0;

//pohibka

do
 {
n++;
h=(b-a)/n;
for ( i = 1; i < n+1; i++ )
   {
    a=(z+h*i);
    y1=(1+sqrt(a))/(a*a)+y1;
   }

h=(b-a)/(n+2);

for ( i = 1; i < n+3; i++ )
    {
    a=(z+h*i);
    y2=(1+sqrt(a))/(a*a)+y2;
    }
 }
while (fabs(y2-y1)<=p);

printf ("\ni=%lf\n", i);
printf ("i - pohibka in right triangle metod \n ", i);

break;

case 3:
// Trapezoid metod:

y=0;
for ( i = 1; i < n; i++ )
{
    a=(z+hf*i);
    y=(1+sqrt(a))/(a*a)+y;
}

t=h*(y+((1+sqrt(a))/(a*a) + (1+sqrt(b))/(b*b)  )/2);

printf("\nt=%lf\n", t);
printf("t - value of integral couted by trapezoid metod\n");

break;

case 4:

    if (n%2==0)
    {
//Simpson`s metod:

s1=0;
for ( i = 1; i < n; i=i+2)
   {
    a=(z+h*i);
    s1=(1+sqrt(a))/(a*a)+s1;
   }

s2=0;
for ( i = 2; i < n-1; i=i+2 )
  {
    a=(z+h*i);
    s2=(1+sqrt(a))/(a*a)+s2;
  }

s=hf*((1+sqrt(z))/(z*z)+(1+sqrt(b))/(b*b)+4*s1+2*s2)/3;
printf("\n s=%lf\n", s);
printf("s - value of integral couted by Simpson's metod\n");
    } else
    printf ("n not pair");
    break;

    }
}
