#include<iostream>

using namespace std;

class Shape{
	private:
		int hieght;
		int width;
	
	public:
		
		void sethieght(int i){
			hieght = i;
		}
		void setwidth(int i){
			width = i;
		}
		
		int gethieght(){
			return hieght;
		}
		int getwidth(){
			return width;
		}
};

main(){
	Shape a;
	
	a.sethieght(4);
	a.setwidth(3);
	cout<<"Height: "<< a.gethieght() << endl << "Width: " << a.getwidth();
}
