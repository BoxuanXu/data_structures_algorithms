/*******************************************************************************
*
* FileName : Auto_ptr_xubx.h
* Comment  : smart pointer auto pointer, it must point to an object on heap memory
* Version  : 1.0
* Author   : tranticket.com
* Date     : 2017-03-29 1:25
*
*******************************************************************************/

#ifndef _AUTO_PTR_XUBX_H_INCLUDED
#define _AUTO_PTR_XUBX_H_INCLUDED
#include <iostream>

template<typename T>
class Point
{
public:
	Point(){}
	Point(T x_var,T y_var):x(x_var),y(y_var){}

	~Point(){}

	T getX(){return x;}
	T getY(){return y;}
	void setX(T x_var){x = x_var;}
	void setY(T y_var){y = y_var;}
	
private:
	T x,y;
};

//辅助类

template<typename T>
class Smart_Autor;

template<typename T>
class help_Autor
{
private:
 friend class Smart_Autor<T>;

 help_Autor(T* ptr):p(ptr),count(0){}

 ~help_Autor(){delete p;}
 int count;
 T *p;
};


template<typename T>
class Smart_Autor
{
public:
	Smart_Autor(T *ptr):hp(new help_Autor<T>(ptr)){}

	Smart_Autor(const Smart_Autor<T>& rhs):hp(rhs.hp){++hp->count;}

	Smart_Autor& operator=(const Smart_Autor<T>& rhs)
	{
		++rhs->count;
		if(--hp->count == 0)
			delete hp;
		hp = rhs->hp;
		return *this;
	}	

	T& operator*()
	{
		return *(hp->p);
	}
	T* operator->()
	{
		return hp->p;
	}
	~Smart_Autor()
	{
		
		if(--hp->count == 0)
			delete hp;
		else
			std::cout<<"还有"<<hp->count<<"个对象"<<std::endl;
	}
      	
private:
	help_Autor<T> *hp;

};
#endif
