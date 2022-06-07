#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

/**
 * Написать функцию, на вход которой поступает строка содержащая в себе цифры, математические операторы, скобки.
 * Результат функции - булево значение отвечающее на вопрос - правильно ли расставлены скобки или нет.
 */
char brackets[3][2] = {'{', '}', '(', ')', '[', ']'};

bool check(char *str, size_t size, size_t *curr, uint32_t level)
{
    if (size <= *curr)
    {
        return false;
    }
    size_t start;
    bool first_bracket = true;
    uint8_t ch;
    uint8_t i;
    while (*curr < size)
    {
        ch = str[*curr];
        if (ch == '{' || ch == '(' || ch == '[')
        {
            if (first_bracket)
            {
                start = *curr;
                first_bracket = false;
            }
            (*curr)++;
            for (i = 0; i < 3; ++i)
            {
                if (brackets[i][0] == ch)
                {
                    break;
                }
            }
            if (check(str, size, curr, level + 1) && (*curr) < size && str[*curr] == brackets[i][1])
            {
                (*curr)++;
            }
            else
            {
                return false;
            }
        }
        else if (ch == ']' || ch == ')' || ch == '}')
        {
            return level != 0;
        }
        else
        {
            (*curr)++;
        }
    }
    ch = str[start];
    return ch == '{' || ch == '(' || ch == '[';
}

bool wrap_check(char *str, size_t size)
{
    size_t curr = 0;
    size = str[size - 1] == '\0' ? size - 1 : size;
    return check(str, size, &curr, 0);
}

int main()
{

    char str[] = "(()){{[]()}}"; // (()()())(), 1 + 2 * (2 + 1), ()
    if (wrap_check(str, sizeof(str)))
    {
        printf("true!\n");
    }
    else
    {
        printf("false!\n");
    }
    return 0;
}
