#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 #include <assert.h>
//字符串赋值函数
/*char *strcpy( char *strDestination, const char *strSource )
{
	//
	assert(strDestination != NULL && strSource != NULL);
	int i = 0;
	while (*strSource!= '\0')
	{
		strDestination[i++] = *strSource++;
	}
	strDestination[i] = '\0';
	return strDestination;
}
*/
int main()
{
	char* str1 = "123132565y342567475";
	char* str2;
	str2 = (char*)malloc(2);
	printf("strlen() is %d,size is %d,addrsee is %d,%d\n",strlen(str2),sizeof(str2),str2,str2 + 1);
	strcpy(str2,str1);
	printf("%s\n",str2);
	printf("strlen() is %d,size is %d,addrsee is %d,%d\n",strlen(str2),sizeof(str2),str2,str2 + 1);
	free(str2);
	return 1;
}
