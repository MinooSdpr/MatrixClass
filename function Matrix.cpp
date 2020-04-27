#include <iostream>
#include <stdlib.h>
#include "Header Matrix.h"
using namespace std;

Matrix::Matrix(int x,int y)
		{
			i=x;	j=y;
			A=new double *[i];
			for(int k=0;k<i;k++)
			{
				A[k]=new double [j];
			}
			if(!A)
			{
				cout<<"error in allocation \n";
				exit(-1);
			}
		}
Matrix::Matrix(const Matrix& mat)
		{
			i=mat.i;
			j=mat.j;
			A=new double *[i];
			for(int k=0;k<i;k++)
			{
				A[k]=new double [j];
			}
			for(int v=0;v<i;v++)
			{
				for(int u=0;u<j;u++)
				A[v][u]=mat.A[v][u];
			}
			if(!A)
			{
				cout<<"error in allocation \n";
				exit(-1);
			}
		}
	Matrix& Matrix:: operator =(const Matrix& mat1)
		{
			i=mat1.i;
			j=mat1.j;
			A=new double *[i];
			for(int k=0;k<i;k++)
			{
				A[i]=new double [j];
			}
			for(int v=0;v<i;v++)
			{
				for(int u=0;u<j;u++)
				A[i][j]=mat1.A[i][j];
			}
			return *this;
		}

Matrix operator+(const Matrix& mat1,const Matrix& mat2)
{
	
	if(mat1.i==mat2.i && mat1.j==mat2.j)
	{
		Matrix temp;
		temp.i=mat1.i;
		temp.j=mat1.j;
		for(int x=0;x<temp.i;x++)
		{
			for(int y=0;y<temp.j;y++)
			temp.A[x][y]=mat1.A[x][y]+mat2.A[x][y];
		}
		return temp;
	}
	else 
	{
		cout<<"Error :: Two argument i,j are not equal \n";
		return -1;
	}
	
}

Matrix operator*(const Matrix& mat1,const Matrix& mat2)
{
	
	if(mat1.j==mat2.i)
	{
		Matrix temp;
		temp.i=mat1.i;
		temp.j=mat2.j;
		for(int x=0;x<temp.i;x++)
		{
		for(int y=0;y<temp.j;y++){
		
		temp.A[x][y]+=mat1.A[x][y]*mat2.A[x][y];
	}
		}
		return temp;
	}
	else 
	{
		cout<<"Error :: Two argument i,j are not equal \n";
		return -1;
	}
	
}

Matrix operator-(const Matrix& mat1,const Matrix& mat2)
{
	
	if(mat1.i==mat2.i && mat1.j==mat2.j)
	{
		Matrix temp;
		temp.i=mat1.i;
		temp.j=mat1.j;
		for(int x=0;x<temp.i;x++)
		{
			for(int y=0;y<temp.j;y++)
			temp.A[x][y]=mat1.A[x][y]-mat2.A[x][y];
		}
		return temp;
	}
	else 
	{
		cout<<"Error :: Two argument i,j are not equal \n";
		return -1;
	}
	
}

Matrix& Matrix::operator +=(const Matrix& mat1)
{
		if(i==mat1.i && j==mat1.j)
	{
		for(int x=0;x<i;x++)
		{
			for(int y=0;y<j;y++)
			A[x][y]+=mat1.A[x][y];
		}
		return *this;
	}
	else
	{
		cout<<"ERROR :: choosing two matrix that dont have equal i , j \n";
		exit(-1);
	}
	
}

Matrix& Matrix::operator -=(const Matrix& mat1)
{
		if(i==mat1.i && j==mat1.j)
	{
		for(int x=0;x<i;x++)
		{
			for(int y=0;y<j;y++)
			A[x][y]-=mat1.A[x][y];
		}
		return *this;
	}
	else
	{
		cout<<"ERROR :: choosing two matrix that dont have equal i , j \n";
		exit(-1);
	}
	
}

Matrix& Matrix::operator --()
{
		for(int x=0;x<i;x++)
		{
			for(int y=0;y<j;y++)
			A[x][y]--;
		}
		return *this;
	
}

Matrix& Matrix::operator --(int)
{
	Matrix temp=*this;
		for(int x=0;x<i;x++)
		{
			for(int y=0;y<j;y++)
			A[x][y]--;
		}
		return temp;
	
}

Matrix& Matrix::operator ++()
{
		for(int x=0;x<i;x++)
		{
			for(int y=0;y<j;y++)
			A[x][y]++;
		}
		return *this;
	
}

Matrix& Matrix::operator ++(int)
{
	Matrix temp=*this;
		for(int x=0;x<i;x++)
		{
			for(int y=0;y<j;y++)
			A[x][y]++;
		}
		return temp;
	
}

	double  Matrix::operator () (int m , int n)
		{
			if(m<=i && n<=j)
			return A[m][n];
			else
			{
				cout<<" Wrong i , j entered :'( \n";
				return -1;
			}
		}
		
		int operator ==(const Matrix& mat1,const Matrix& mat2)
		{
			if(mat1.i==mat2.i && mat1.j==mat2.j)
			{
				for(int m=0;m<mat1.i;m++)
				{
					for(int n=0;n<mat1.j;n++)
					{
						if(mat1.A[m][n]!=mat2.A[m][n])
						return 0;
					}
				}
				return 1;
			}
			return 0;
		}
		
		int operator !=(const Matrix& mat1,const Matrix& mat2)
		{
			if(mat1.i==mat2.i && mat1.j==mat2.j)
			{
				for(int m=0;m<mat1.i;m++)
				{
					for(int n=0;n<mat1.j;n++)
					{
						if(mat1.A[m][n]!=mat2.A[m][n])
						return 1;
					}
				}
				return 0;
			}
			return 1;
		}
int main()
{
	
	system("pause");
	
}
