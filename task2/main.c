#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

/*
 *  Реализовать поиск индекса числа в отсортированном массиве.
 *  Необходимо реализовать функцию int search_index(int *array, int size, int value)
 *  P.S.
 *  Для решения данной задачи необходимо спользовать бинарный поиск т.к. массив отсортирован
 */
int search_index(int *array, int size, int value)
{
    bool flag = false;
    uint32_t l = 0;
    uint32_t r = size - 1;
    uint32_t mid;

    while ((l <= r)) {
        mid = (l + r) / 2;

        if (array[mid] == value)
        {
            flag = true;
            break;
        }
        if (array[mid] > value)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return flag ? mid: -1;
}

int main()
{
    int array[] = {1, 5, 10, 11, 12, 14, 20, 25};
    printf("Hello, World! %d\n", search_index(array, sizeof(array), 20));
    return 0;
}
