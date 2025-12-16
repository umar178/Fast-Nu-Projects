#include <iostream>
#include <vector>
using namespace std;

void findSubsets(int arr[], int n, int start, int k,
                 int currentSum, vector<int> &currentSet,
                 vector<vector<int>> &results) {
    if (currentSum == k) {
        results.push_back(currentSet);
        return;
    }
    if (start == n || currentSum > k) {
        return;
    }

    currentSet.push_back(arr[start]);
    findSubsets(arr, n, start + 1, k,
                currentSum + arr[start], currentSet, results);
    currentSet.pop_back();

    findSubsets(arr, n, start + 1, k,
                currentSum, currentSet, results);
}

int main() {
    int arr[] = {2, 3, 5, 7};
    int n = 4;
    int k = 10;

    vector<vector<int>> results;
    vector<int> currentSet;

    findSubsets(arr, n, 0, k, 0, currentSet, results);

    if (results.empty()) {
        cout << "No subsets found with sum " << k << endl;
    } else {
        cout << "Subsets with sum " << k << ":\n";
        for (const auto &subset : results) {
            cout << "{ ";
            for (int num : subset) {
                cout << num << " ";
            }
            cout << "}\n";
        }
    }

    return 0;
}

