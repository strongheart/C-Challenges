#include <stdio.h>
#include <stdlib.h>
#define QS "\n\t__: " // prompt for input
#define LIMIT2 10 // used in root2 for precision
#define LIMIT3 15 // used in root3 for precision


/**
udemy / {LP}
"C For Beginners"
9:60 Functions Challenge
@instructor Jason Fedin
@author Steve Strongheart
@date 20180213

Objective:
create functions
1) to find Greatest Common Denominator of 2 integers
2) to return the absolute value of a number
3) to calculate the Square Root of a number not using a built in function.

Also added a cube root function.

I hope this serves as a decent sample
*/

int gcd(int a, int b);
float absVal(float x);
float root2(float x);
float avg(float x, float y);
float root3(float x);
void testGCD();
void testAbs();
void testRoot2();
void testRoot3();

/**@return zero if affirmative
ask() asks if user wants to repeat the test.
y or Y will return 0, which will be taken as affirmative.
*/
int ask()
{
	char y= 'y'|32 ; // the difference between upper and lower case is 32, the single binary bit in the 5th place.
	y|='Y'; // just to make sure the 32 bit is set

	printf ( "Repeat this test test? " );
	printf("y/n %s",QS);
	char r;
	char R[1]; // a string
	scanf("%c",&r);
	//scanf("%s",&R);
	//r=R[0];
	r|=32;
	printf("r=%c\n",r);
	return r-y	;
}

int main()
{
	// test the ask function
//	int r= ask();
//	printf("ask R= %d\n",r);


// using do while so that each test is executed at least once.
// user will be asked if she or he would like to repeat the test
	do
	{
		testRoot2();

	}
	while(ask()==0);

	printf(" \n==================\n\n");

	do
	{
		testGCD();
	}
	while(ask()==0);
	printf(" \n==================\n\n");

	do
	{
		testAbs();
	}
	while(ask()==0);
	printf(" \n==================\n\n");

	do
	{
		testRoot3();
	}
	while(ask()==0);

	printf ("Good Bye - Happy Coding ");
    return 0;
}

///////////////  functions   ////////////////////////////////////

/**@return absolute value of x */
float absVal(float x)
{
	return x>=0?x:-x;
}

/**@return square root of x,
divides x by an initial denominator (2) and gets a quotient q.
the right answer is somewhere between denominator an quotient.
subsequent averages and divides close in toward the correct result.
*/
float root2(float x)
{
	if (x<0)
	{
		printf ("You entered a negative number - imagine that ;) we fix it");
		x=absVal(x);
	}

	float d=2;
	float q=x/d;
	for (int n=0; n<LIMIT2; n++)
	{
		d=avg(d,q);
		q=x/d;
	}
	return q;
}
/**@return average of x and y, helper in root functions. */
float avg(float x, float y)
{
	return (x+y)/2;
}


// min is not prototyped, it's defined before it's called from gcd()
/**@return minimum of a and b - helper for gcd()
*/
int min(int a, int b)
{
	return a<=b? a:b;
}

// complementary function of min
int max(int a, int b)
{
	return a>=b? a:b;
}

/**@return greatest common denominator for x and y or zero if none.
It probably should return 1 as that would be the truth. (fixed)
The algorithm starts with the minimum of a and b.
int test is set to min(a,b)
if test divides into both a and b evenly ( a%test ==0  and b%test==0 ) then it is returned as the greatest common denominator.
If not, it is decremented and retested.
*/
int gcd(int x, int y)
{
	x=absVal(x);
	y=absVal(y);
	int test=min(x,y);
	int lcd=1 ; // returned as 1 if no other common denominator
	int mx,my;
	while (test>1)
	{
		mx=x%test;
		if (mx==0) // might be good news
		{
			my=y%test;
			if (my==0) // good news
			{
				lcd=test;
				break; // get out of here with the goods
			}
		}
		test--;
	}
	return lcd;
}

/**@return cube root.
takes an initial guess and divides x by that number and then
*/
float root3(float x )
{
	float p,q,r=x/3;
	for (int n=0; n<LIMIT3; n++ )
	{
		q=x/r;
		p=q/r;
		r=avg(p,r);
		// test  intermediate values
		// printf("  %f, %f, %f \n", p,q,r);
	}
	return r;
}

void testAbs()
{
	float x, a;
	printf("Enter a number and I will return it's absolute value.%s",QS) ;
	scanf("%f",&x);
	a=absVal(x);
	printf("the absVal of %f is %f \n",x,a);
}

void testGCD()
{
	int a, b, c;
	printf ("input to integers to find the lcd");
	printf (QS);
	scanf("%d %d",&a, &b);
	c=gcd(a,b);
	printf("\nhighest common denominator of (%d, %d) = %d\n\n",a,b,c) ;
}

void testRoot2()
{
	float x,q;
	printf("enter a number to find sqroot:") ;
	printf (QS);
	scanf("%f",&x);
	q=root2(x);
	printf ("\nroot2 of %f = %f and root*root = %f\n\n", x,q,q*q);
}

void testRoot3()
{
	float x,q;
	printf("enter a number to find cube root of: \n\t__: ") ;
	scanf("%f",&x);
	q=root3(x);
	printf("\n root3 of %f = %f r*r*r=%f\n\n", x,q,q*q*q);
}



