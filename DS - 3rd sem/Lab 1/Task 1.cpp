#include<iostream>

using namespace std;

class matrix{
	
	public:
		int **arr;
		int row, col;
	
		matrix(int r, int c){
			row = r;
			col = c;
			arr = new int*[r];
			for(int i = 0; i < r; i++){
				arr[i] = new int[c];
			}
		}
		
		~matrix(){
			for (int i = 0; i < row; i++) {
		        delete[] arr[i];
		    }
		    delete[] arr;
		}
		
		void resize(int r, int c){
			int **n_arr;
			
			n_arr = new int*[r];
			for(int i = 0; i<r; i++){
				n_arr[i] = new int[c];
			}
			
			for(int i = 0; i<r; i++){
				for(int j = 0; j<c; j++){
					if(i < row && j < col){
						n_arr[i][j] = arr[i][j];
					}
					else{
						n_arr[i][j] = 0;
					}
				}
			}
			
			for (int i = 0; i < row; i++) {
		        delete[] arr[i];
		    }
		    delete[] arr;
		
		    arr = n_arr;
		    row = r;
		    col = c;
		}
		
		void transpose(){
			int **n_arr;
			
			n_arr = new int*[col];
			for(int i = 0; i<col; i++){
				n_arr[i] = new int[row];
			}
			
			for(int i = 0; i<row; i++){
				for(int j = 0; j<col; j++){
					n_arr[j][i] = arr[i][j];
				}
			}
			
			for (int i = 0; i < row; i++) {
		        delete[] arr[i];
		    }
		    delete[] arr;
		
		    arr = n_arr;
		    int temp = row;
		    row = col;
		    col = temp;
		}
		
		void print(){
			for(int i = 0; i<row; i++){
				for(int j = 0; j<col; j++){
					cout<<arr[i][j]<<" ";
					if ((i % 2 == 1) || (j % 2 == 1)) {
			            arr[i][j] += 2;
			        }
				}
				cout<<endl;
			}
			
			cout<<endl<<"with 2 added to odd indexes:"<<endl;
			
			for(int i = 0; i<row; i++){
				for(int j = 0; j<col; j++){
					cout<<arr[i][j]<<" ";
				}
				cout<<endl;
			}
		}
};

int main() {
	cout<<"muhammad Umer Karim / 24k-0880"<<endl;
    matrix m(3, 3);

    int counter = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m.resize(3, 3);
        }
    }

    counter = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m.arr[i][j] = counter++;
        }
    }

    cout << "Original matrix + odd index update:\n";
    m.print(); 

    cout << "\nAfter resizing to 4x5:\n";
    m.resize(4, 5);
    m.print();

    cout << "\nAfter transposing:\n";
    m.transpose();
    m.print();

    return 0;
}
