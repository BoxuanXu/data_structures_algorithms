#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 #include <assert.h>

size_t atoi_f(const char* str)
{
	char c;
	int i =0;
	while(c = *str++)
	{
		if(c >= '0' && c <= '9')
		{
			i = i * 10 + (c - '0');
		}
		else 	
			return -1;
	}
	return i;
}

int atoi_f2( const char *string )  
{  
    char *p = (char*)string;  
    char c;  
    int   i = 0;  
    while(c = *p++)  
    {  
        if(c>='0' && c<='9')  
        {  
            i = i*10 + (c-'0');  
        }  
        else  
            return -1;                     //无效的字符串  
    }  
    return i;  
}  

int main()
{
	char* str1 = "12325677891";
	printf("%d\n",atoi_f(str1));
	return 1;

}
