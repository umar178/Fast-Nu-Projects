#include<iostream>
using namespace std;

class investment{
	private:
		int i_investment;
		int c_value;
		int profit;
		float profit_percent;
			
	public:
		investment(int i, int c) : i_investment(i), c_value(c){
			profit = c_value - i_investment;
			profit_percent = profit/i_investment;
		}
		
		void display(){
			cout<<"Initial Investment: " << i_investment << endl << "Current value: " << c_value << endl;
			cout<<"Profit: " << profit << endl << "Profit Percentage: " << profit_percent << endl;
		}
		
};

class House{
	private:
		string address;
		int feet;
		
	public:
		House(string a, int f) : address(a), feet(f){}
		
		void display(){
			cout<<"Address: " << address << endl << "Area: " << feet << endl;
		}
};

class HouseThatIsAnInvestment: public investment, public House{
	public:
		HouseThatIsAnInvestment(string a, int f, int i, int c) : House(a, f), investment(i, c){}
		
		void Adisplay(){
			House::display();
			investment::display();
		}
};

int main(){
	HouseThatIsAnInvestment a("D.R.Q", 500, 200, 350);
	
	a.Adisplay();
}
