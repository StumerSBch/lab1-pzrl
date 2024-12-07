#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    if (argc < 5)
    {
        printf("Ошибка: недостаточно аргументов.\n");
        return EXIT_FAILURE;
    }

    int *results = NULL;
    int results_count = 0;
    int key = 0;
    int i = 1;

    while (i < argc)
    {
        if (strcmp(argv[i], "-k") == 0)
        {
            if (i + 1 >= argc)
            {
                printf(stderr, "Ошибка: отсутствует ключ после флага -k.\n");
                return EXIT_FAILURE;
            }
            key = atoi(argv[++i]);
            break;
        }

        if (i + 2 >= argc)
        {
            printf("Ошибка: некорректный формат ввода.\n");
            return EXIT_FAILURE;
        }

        int left_operand = atoi(argv[i]);
        char operator = argv[i + 1][0];
        int right_operand = atoi(argv[i + 2]);

        int result = calculate(left_operand, operator, right_operand);

        results = realloc(results, (results_count + 1) * sizeof(int));
        if (!results)
        {
            printf("Ошибка выделения памяти.\n");
            return EXIT_FAILURE;
        }

        results[results_count++] = result;
        i += 3;
    }

    decrypt_and_print(results, results_count, key);
    free(results);

    return 0;
}
