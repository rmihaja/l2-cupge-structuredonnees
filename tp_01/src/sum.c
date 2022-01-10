#include <stdio.h>
#include <stdlib.h>

void display_message(char *msg) {
    printf("%s\n", msg);
    exit(1);
}

int isCharOperator(char c) {
    switch (c)
    {
    case '-':
    case '+':
        return 1;
        break;

    default:
        return 0;
        break;
    }
}

int isCharInteger(char c) {
    // ? method with ascii checkout
    // if (c >= 48 && c < 58)
    // {
    //     return 1;
    // }
    // return 0;

    // ? method with switch case (mandatory)
    switch (c)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

int charToInteger(char c) {
    return ((int)c - 48);
}

int power10(int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return 10 * power10(exponent - 1);
}

int stringToInteger(const char *c) {
    int integer = 0;
    int length = 0;
    while (c[length] != '\0')
    {
        length++;
    }
    for (int i = isCharOperator(c[0]); i < length; i++)
    {
        integer += charToInteger(c[i]) * power10(length - 1 - i);
    }
    if (c[0] == '-') {
        return -integer;
    }
    return integer;
}

int main(int argc, char const *argv[])
{
    // ? usage by args
    if (argc != 3) {
        display_message("Wrong usage, 2 parameters expected: ./sum param1 param2");
    }
    for (int i = 1; i < argc; i++) {
        if (!isCharInteger(argv[i][0]) && !isCharOperator(argv[i][0]))
            display_message("Wrong usage, parameters param1 and param2 should be integers when executing ./sum param1 param2");
        for (int j = 1; argv[i][j] != '\0'; j++) {
            if (!isCharInteger(argv[i][j])) {
                printf("Error at argument %d, col %d\n", i, j);
                display_message("Wrong usage, parameters param1 and param2 should be integers when executing ./sum param1 param2");
            }
        }
    }
    printf("%d\n", stringToInteger(argv[1]) + stringToInteger(argv[2]));

    // return stringToInteger(argv[1]) + stringToInteger(argv[2]);

    // ? usage by I/O
    // int param1;
    // int param2;
    // scanf("%d", &param1);
    // scanf("%d", &param2);
    // printf("%d\n", param1 + param2);

    // return param1 + param2;

    // return 0;
}

