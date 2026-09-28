char* letters[] = {
    "",     "",     "abc",  "def",
    "ghi",  "jkl",  "mno",  "pqrs",
    "tuv",  "wxyz"
};

void backtrack(char* digits, int index, char* current,
               char** result, int* count) {

    if (digits[index] == '\0') {
        current[index] = '\0';

        result[*count] = malloc((index + 1) * sizeof(char));

        for (int i = 0; i <= index; i++) {
            result[*count][i] = current[i];
        }

        (*count)++;
        return;
    }

    int digit = digits[index] - '0';

    for (int i = 0; letters[digit][i] != '\0'; i++) {
        current[index] = letters[digit][i];

        backtrack(digits, index + 1, current, result, count);
    }
}

char** letterCombinations(char* digits, int* returnSize) {

    int len = strlen(digits);

    *returnSize = 0;

    int total = 1;

    for (int i = 0; i < len; i++) {
        int digit = digits[i] - '0';

        if (digit == 7 || digit == 9)
            total *= 4;
        else
            total *= 3;
    }

    char** result = malloc(total * sizeof(char*));
    char* current = malloc((len + 1) * sizeof(char));

    backtrack(digits, 0, current, result, returnSize);

    free(current);

    return result;
}