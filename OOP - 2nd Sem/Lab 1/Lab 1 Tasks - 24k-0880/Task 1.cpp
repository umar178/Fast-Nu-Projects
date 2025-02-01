#include<iostream>
using namespace std;

main(){
	int arr1[2][2], arr2[2][2], result[2][2];
	
	cout<<"Enter elements for first array: "<<endl;
	
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			cin>>arr1[i][j];
		}
	}
	
	cout<< endl << "Enter elements for second array: "<<endl;
	
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			cin>>arr2[i][j];
		}
	}
	
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			result[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	
	cout<< endl << "Sum: "<<endl;
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			cout<<result[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			result[i][j] = arr1[i][j] - arr2[i][j];
		}
	}
	
	cout<< endl << "difference: "<<endl;
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			cout<<result[i][j] << " ";
		}
		cout << endl;
	}
	
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			for(int k= 0; k < 2; k++){
				result[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	
	cout<< endl << "Product: "<<endl;
	for(int i = 0; i<2; i++){
		for(int j = 0; j<2; j++){
			cout<<result[i][j] << " ";
		}
		cout << endl;
	}
}
