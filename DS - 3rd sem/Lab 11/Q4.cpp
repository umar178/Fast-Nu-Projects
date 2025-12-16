#include <iostream>
#include <string>

using namespace std;

void computeLPSArray(string pat, int* lps) {
    int len = 0; 
    int i = 1;
    int M = pat.length();

    lps[0] = 0; 

    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();

    int* lps = new int[M];

    computeLPSArray(pat, lps);

    cout << "--- LPS Array Construction ---" << endl;
    cout << "Pattern: " << pat << endl;
    cout << "LPS:     ";
    for (int k = 0; k < M; k++) {
        cout << lps[k] << " ";
    }
    cout << endl << endl;

    cout << "--- KMP Search Trace ---" << endl;
    int i = 0; 
    int j = 0; 
    
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            cout << "Found pattern at index " << (i - j) << endl;
            j = lps[j - 1];
        } 
        else if (i < N && pat[j] != txt[i]) {
            cout << "Mismatch at P[" << j << "] vs T[" << i << "]. ";
            if (j != 0) {
                cout << "Using LPS[" << (j - 1) << "] = " << lps[j - 1];
                j = lps[j - 1];
                cout << ". New Pattern Index: " << j << endl;
            } else {
                cout << "j is 0. Increment Text Index." << endl;
                i = i + 1;
            }
        }
    }

    delete[] lps;
}

int main() {
    string pattern = "ABABA";
    string text = "ABABBABABA"; 

    KMPSearch(pattern, text);

    return 0;
}
