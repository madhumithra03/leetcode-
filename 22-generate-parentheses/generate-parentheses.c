char** result;
int count;

void backtrack(char* str, int pos, int open, int close, int n)
{
    if (pos == 2 * n)
    {
        str[pos] = '\0';

        result[count] = malloc((2 * n + 1) * sizeof(char));
        strcpy(result[count], str);
        count++;

        return;
    }

    // Add opening bracket
    if (open < n)
    {
        str[pos] = '(';
        backtrack(str, pos + 1, open + 1, close, n);
    }

    // Add closing bracket
    if (close < open)
    {
        str[pos] = ')';
        backtrack(str, pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    // For n <= 8, maximum combinations = 1430
    result = malloc(1430 * sizeof(char*));

    count = 0;

    char* str = malloc((2 * n + 1) * sizeof(char));

    backtrack(str, 0, 0, 0, n);

    free(str);

    *returnSize = count;

    return result;
}