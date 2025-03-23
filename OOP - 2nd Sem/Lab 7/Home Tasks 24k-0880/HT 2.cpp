#include<iostream>
using namespace std;

class Matrix{
	int array[2][2];
	public:
		Matrix(){
		}
		Matrix(int a,int b,int c,int d){
			array[0][0]=a;
			array[0][1]=b;
			array[1][0]=c;
			array[1][1]=d;
		}
		Matrix operator+(Matrix &obj){
			Matrix temp;
			temp.array[0][0]=array[0][0]+obj.array[0][0];
			temp.array[0][1]=array[0][1]+obj.array[0][1];
			temp.array[1][0]=array[1][0]+obj.array[1][0];
			temp.array[1][1]=array[1][1]+obj.array[1][1];
			return temp;
		}
		void display(){
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					cout<<array[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};

int main(){
	Matrix m1(1,2,3,4);
	cout<<"Matrix 1: "<<endl;
	m1.display();
	Matrix m2(5,6,7,8);
	cout<<"Matrix 2: "<<endl;
	m2.display();
	Matrix m3=m1+m2;
	cout<<"Sum: "<<endl;
	m3.display();
}
