#include <iostream>
#ifndef CONTEST
#include "fullratio.h"
#endif
#include <cmath>

using namespace std;

rational::rational (int n, int d)
{
nom=n;
den=d;
}

int rational::gcd(int a,int b)
{
a = abs(a); b = abs(b);
 while (a > 0 && b > 0)
 if (a > b) a = a % b; else b = b % a;
 return(a+b);
}

rational operator + (const rational &x,const rational &y)
{
int r1=(x.nom*y.den)+(y.nom*x.den);
int r2=x.den*y.den;
int k=gcd(r1,r2);
r1=r1/k;
r2=r2/k;
if(r1<0 && r2<0)
{
r1=abs(r1);
r2=abs(r2);
}
return(rational(r1,r2));
}


rational operator-(const rational &x,const rational &y)
{
int r1=(x.nom*y.den)-(y.nom*x.den);
int r2=x.den*y.den;
int k=gcd(r1,r2);
r1=r1/k;
r2=r2/k;
if(r1<0 && r2<0)
{
r1=abs(r1);
r2=abs(r2);
}
return(rational(r1,r2));
}

rational operator*(const rational &x,const rational &y)
{
int r1=(x.nom*y.nom);
int r2=x.den*y.den;
int k=gcd(r1,r2);
r1=r1/k;
r2=r2/k;
if(r1<0 && r2<0)
{
r1=abs(r1);
r2=abs(r2);
}
return(rational(r1,r2));
}


rational operator/(const rational &x,const rational &y)
{
int r1=(x.nom*y.den);
int r2=x.den*y.nom;
int k=gcd(r1,r2);
r1=r1/k;
r2=r2/k;
if(r1<0 && r2<0)
{
r1=abs(r1);
r2=abs(r2);
}
return(rational(r1,r2));
}




ostream& operator<<(ostream &out, const rational &r)
{
out<<r.nom<<"/"<<r.den<<" ";
return out;
}


