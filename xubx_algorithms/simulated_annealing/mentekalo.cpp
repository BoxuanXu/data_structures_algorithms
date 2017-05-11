
#include"iostream"
#include"cstdio"
#include"cstdlib"
#include"cmath"
using namespace std; 
int random(int m,int n);
int main(){
	int a=0,b=0;
	for(int i = 0;i < 400000000;++i)	
	{
		int c=(int)sqrt(pow(random(1,400000) - 200000,2)+pow(random(1,400000) - 200000,2));
		if(c > 200000)
			a=a+1;
		else
			b=b+1;
	}
	printf("a is %d,b is %d,pai is %.10lf",a,b,(4*(b/400000000.0)));
}

int random(int m,int n){
	int a;
	double x = (double)rand()/RAND_MAX;
	a = (int)(x*(n-m) + 0.5) +m;
	return a;
}
