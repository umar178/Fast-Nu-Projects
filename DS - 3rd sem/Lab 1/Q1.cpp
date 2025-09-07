//umer karim 24k-0880
#include<iostream>

using namespace std;

int main(){
	int **nums;
	int a,b;
	int *total;
	float *avg;
	
	cout<<"Umer karim: 24k-0880"<<endl;
	cout<<"enter number of students: ";
	cin>>a;
	cout<<"enter number of subjects: ";
	cin>>b;
	
	nums = new int*[a];
	
	for(int i = 0; i < a; i++){
		nums[i] = new int[b];
	}
	
	cout<<endl<<"Enter number of students:"<<endl;
	for(int i = 0; i<a; i++){
		for(int j = 0; j<b; j++){
			cout<<"student "<<i<<", subject "<<j<<":";
			cin>>nums[i][j];
		}
	}
	
	//total marks
	total = new int[a];
	
	for(int i = 0; i<a; i++){
		int sum = 0;
		for(int j = 0; j<b; j++){
			sum += nums[i][j];
		}
		total[i] = sum;
	}
	
	//avg marks
	avg = new float[b];
	
	for(int i = 0; i<b; i++){
		float _avg = 0;
		for(int j = 0; j<a; j++){
			_avg += nums[i][j];
		}
		avg[i] = _avg/a;
	}
	
	//output
	cout<<"total marks of each student:"<<endl;
	for(int i = 0; i<a; i++){
		cout<<"Student "<<i<<":"<<total[i]<<endl;
	}
	
	cout<<endl<<"avg of each subject:"<<endl;
	for(int i = 0; i<b; i++){
		cout<<"Subject "<<i<<":"<<avg[i]<<endl;
	}
	
	int high = 0;
	int student;
	for(int i = 0; i<a; i++){
		if(total[i] > high){
			high = total[i];
			student = i;
		}
	}
	cout<<endl<<"student "<<student<<" has highest marks: "<<high<<endl;
	
	//memory clean up
	for(int i = 0; i<a; i++){
		delete [] nums[i];
	}
	delete [] nums;
	delete [] total;
	delete[] avg;
}
