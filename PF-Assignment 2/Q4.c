#include <stdio.h>
#include <string.h>

int areAnagrams(char *word1, char *word2) {
    int count1[26] = {0}, count2[26] = {0};

    for (int i = 0; word1[i] != '\0'; i++) {
        count1[word1[i] - 'a']++;
    }

    for (int i = 0; word2[i] != '\0'; i++) {
        count2[word2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) return 0;
    }
    return 1;
}

int main() {
    char *transactions[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int numTransactions = 6;
    int grouped[6] = {0};  

    for (int i = 0; i < numTransactions; i++) {
        if (grouped[i]) continue;

        printf("[ %s", transactions[i]);
        grouped[i] = 1;

        for (int j = i + 1; j < numTransactions; j++) {
            if (!grouped[j] && areAnagrams(transactions[i], transactions[j])) {
                printf(", %s", transactions[j]);
                grouped[j] = 1;
            }
        }
        printf(" ]\n");
    }

    return 0;
}
