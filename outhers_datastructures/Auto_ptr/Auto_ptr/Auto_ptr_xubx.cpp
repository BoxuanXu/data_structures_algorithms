/*******************************************************************************
*
* FileName : Auto_ptr.cpp
* Comment  : test code for auto pointer
* Version  : 1.0
* Author   : haibindev.cnblogs.com
* Date     : 2007-10-10 1:25
*
*******************************************************************************/

#include <iostream>
#include "Auto_ptr_xubx.h"

int main()
{
	int *a = new int(5);
	{
		Smart_Autor<int> p(a);
		{
			Smart_Autor<int> p2(p);
			{
				Smart_Autor<int> p3 = p2;
				*p =20;
			}
		}
	}	
	return 0;
}
