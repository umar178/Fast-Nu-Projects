#include <iostream>
#include <string>

using namespace std;

void solveBruteForce(string T, string P) {
    cout << "--- Part 1: Brute Force Search ---\n";
    int n = T.length();
    int m = P.length();

    for (int i = 0; i <= 1; i++) { 
        cout << "\nWindow " << (i + 1) << " (Pattern at Index " << i << "):\n";
        cout << "Text:    " << T << endl;
        cout << "Pattern: ";
        for(int s=0; s<i; s++) cout << " "; 
        cout << P << endl;

        for (int j = 0; j < m; j++) {
            cout << "  Comparing T[" << (i + j) << "] ('" << T[i + j] << "') vs P[" << j << "] ('" << P[j] << "')... ";
            if (T[i + j] != P[j]) {
                cout << "Mismatch found! Shift pattern.\n";
                break; 
            } else {
                cout << "Match.\n";
            }
        }
    }
}

void solveBoyerMooreCalc(string P, char badChar, int mismatchIndexInP) {
    cout << "\n--- Part 2: Boyer-Moore Bad Character Heuristic ---\n";
    
    int m = P.length();
    int badCharIndexInP = -1;

    for (int i = mismatchIndexInP - 1; i >= 0; i--) {
        if (P[i] == badChar) {
            badCharIndexInP = i;
            break;
        }
    }

    cout << "Pattern: " << P << endl;
    cout << "Bad Character from Text: '" << badChar << "'" << endl;
    cout << "Mismatch occurred at Pattern Index: " << mismatchIndexInP << endl;

    int shift;
    if (badCharIndexInP == -1) {
        cout << "'" << badChar << "' does NOT exist in Pattern.\n";
        shift = mismatchIndexInP - (-1); 
    } else {
        cout << "Rightmost occurrence of '" << badChar << "' in Pattern is at index " << badCharIndexInP << endl;
        shift = mismatchIndexInP - badCharIndexInP;
    }

    cout << "Calculated Shift: " << shift << " positions." << endl;
}

int main() {
    string T = "GCAATGCCCTATGTGACC";
    string P = "TATGT";

    solveBruteForce(T, P);

    solveBoyerMooreCalc(P, 'C', 4);

    return 0;
}
