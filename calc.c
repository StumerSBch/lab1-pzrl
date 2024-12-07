#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

// Функция вычисления результата арифметического выражения
int calculate(int left_operand, char operator, int right_operand)
{
    switch (operator)
    {
        case '+': return left_operand + right_operand;
        case '-': return left_operand - right_operand;
        case '*': return left_operand * right_operand;
        case '%': 
            if (right_operand == 0)
            {
                fprintf(stderr, "Ошибка: деление на ноль.\n");
                exit(EXIT_FAILURE);
            }
            return left_operand % right_operand;
        default:
            fprintf(stderr, "Ошибка: некорректный оператор '%c'.\n", operator);
            exit(EXIT_FAILURE);
    }
}

// Функция дешифрации и вывода результата
void decrypt_and_print(int *results, int count, int key)
{
    printf("Результаты:\n");
    char *decrypted_str = (char *)malloc((count + 1) * sizeof(char));
    if (!decrypted_str)
    {
        fprintf(stderr, "Ошибка выделения памяти.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++)
    {
        printf("Ответ №%d: %d\n", i + 1, results[i]);
        decrypted_str[i] = (char)(results[i] - key);
    }
    decrypted_str[count] = '\0'; // Завершаем строку

    printf("Результирующая строка: %s\n", decrypted_str);
    free(decrypted_str);
}
