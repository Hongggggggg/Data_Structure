#include <stdio.h>

/*二分法*/
/*左闭右闭，最终区间为[target, target]*/
int find_index(int* array, int len, int target)
{
    if(array == NULL)
    {
        printf("ERROR\r\n");
        return -1;
    }
    int left = 0;
    int right = len - 1;
    int middle = 0;

    while(left <= right)
    {
        middle = left + ((right - left) >> 1);//防止溢出，相当于(right + left) / 2

        if(target < array[middle])
        {
            right = middle - 1;//因为middle已经判断过，所以-1
        }
        else if(target > array[middle])
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }   
    }
    return right + 1;
}

void main(void)
{
    int data[] = {1, 2, 4, 7, 10, 19, 21};

    int index = find_index(data, sizeof(data) / sizeof(int), 4);

    printf("index: %d\r\n", index);
}