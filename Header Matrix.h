#include <iostream>
#include <stdlib.h>
using namespace std;

class Matrix
{
	int i,j;
	double **A;
	friend Matrix operator+(const Matrix& mat1,const Matrix& mat2);
	friend Matrix operator*(const Matrix& mat1,const Matrix& mat2);
	friend Matrix operator-(const Matrix& mat1,const Matrix& mat2);
	friend int operator ==(const Matrix& mat1,const Matrix& mat2);
	friend int operator !=(const Matrix& mat1,const Matrix& mat2);
	public:
		Matrix(int x=1,int y=1);
		Matrix(const Matrix& mat);
		~Matrix() {delete A;}
		void seti(int x){ i=x;}
		void setj(int y){ j=y;}
		int geti(){return i;}
		int getj(){ return j;}
		
		void readMat()
		{
			for(int x=0;x<i;x++){
			for(int y=0;y<j;y++){
			cout <<"Enter A("<<x<<" , "<<y<<")= \n";
			cin>>A[x][y];}
		}
		}
		
		void showMat()
		{
			for(int x=0;x<i;x++){
			for(int y=0;y<j;y++){
			cout <<" A("<<x<<" , "<<y<<") = ";
			cout<<A[x][y]<<"\t";}
			cout<<endl;}
		}
		
		void fill_value(double val)
		{
			for(int m=0;m<i;m++)
			{
				for(int n=0;n<j;n++)
				{
					A[m][n]=val;
				}
			}
		}
		
		void setVal(int i,int j,double Val) { A[i][j]=Val; }
		double getVal(int i, int j) { return A[i][j]; }
		Matrix& operator =(const Matrix& mat1);
		double operator () (int m , int n);
		Matrix& operator +=(const Matrix& mat1);
		Matrix& operator -=(const Matrix& mat1);
		Matrix& operator --();
		Matrix& operator --(int);
		Matrix& operator ++();
		Matrix& operator ++(int);
};
