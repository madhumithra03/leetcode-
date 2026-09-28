char* intToRoman(int num) {
    static char result[20];
    int pos = 0;

    int values[] = {
        1000, 900, 500, 400,
        100, 90, 50, 40,
        10, 9, 5, 4, 1
    };

    char *symbols[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            char *s = symbols[i];

            while (*s) {
                result[pos++] = *s;
                s++;
            }

            num -= values[i];
        }
    }

    result[pos] = '\0';

    return result;
}