#include <stdio.h>

/*二分法*/
/*左闭右开[left, right)*/
int find_index(int* array, unsigned int len, int target)
{
    if(array == NULL)
    {
        return -1;
    }
    int right = len - 1;
    int left = 0;
    int middle = 0;

    while(left <= right)
    {
        middle = left + ((right - left) >> 1);/*防止溢出，同(left + right) / 2*/

        if(target < array[middle])
        {
            right = middle - 1;
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
    /*
    分别处理如下四种情况:
    1.目标值在数组所有元素之前  [0, -1]
    2.目标值等于数组中某一个元素  return middle;
    3.目标值插入数组中的位置 [left, right]，return  right + 1
    4.目标值在数组所有元素之后的情况 [left, right]， return right + 1
    */
    return right + 1;
}

void main(void)
{
    int data[] = {1, 2, 4, 7, 10, 19, 21};

    int index = find_index(data, sizeof(data) / sizeof(int), 4);

    printf("index: %d\r\n", index);
}
