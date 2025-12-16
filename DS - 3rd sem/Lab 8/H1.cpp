#include <iostream>
#include <string>
using namespace std;

class DispatchRecord {
public:
    int DispatchID;
    string CustomerName;
    int DeliveryTime;
};

void swap(DispatchRecord &a, DispatchRecord &b) {
    DispatchRecord temp = a;
    a = b;
    b = temp;
}

int partition(DispatchRecord arr[], int low, int high) {
    int pivot = arr[high].DeliveryTime;
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j].DeliveryTime < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(DispatchRecord arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void display(DispatchRecord arr[], int n) {
    cout << "\nDispatchID\tCustomerName\tDeliveryTime\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i].DispatchID << "\t\t"
             << arr[i].CustomerName << "\t\t"
             << arr[i].DeliveryTime << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of dispatch records: ";
    cin >> n;

    DispatchRecord *arr = new DispatchRecord[n];

    for(int i = 0; i < n; i++) {
        cout << "\nRecord " << i + 1 << endl;
        cout << "Dispatch ID: ";
        cin >> arr[i].DispatchID;
        cout << "Customer Name: ";
        cin >> arr[i].CustomerName;
        cout << "Delivery Time (mins): ";
        cin >> arr[i].DeliveryTime;
    }

    cout << "\n--- Before Sorting ---";
    display(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "\n--- After Sorting (By Delivery Time Ascending) ---";
    display(arr, n);

    delete[] arr;
    return 0;
}

