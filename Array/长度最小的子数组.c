#include <stdio.h>

typedef unsigned char uint8_t;

uint8_t minSubArrayLen(uint8_t* array, uint8_t len, uint8_t val)
{
    uint8_t win_len = 0;
    uint8_t left_pos = 0;
    int sum = 0;
    uint8_t rst = 255;

    for(uint8_t i = 0; i < len; i++)
    {
        sum += *(array + i);
        while(sum >= val)
        {
            win_len = i - left_pos + 1;
            rst = win_len < rst ? win_len : rst;
            sum -= *(array + left_pos);
            left_pos++;
        }
    }
    return rst;
}

void main(void)
{
    uint8_t array[] = {2, 3, 1, 2, 4, 8, 7, 7, 1, 3, 2, 4};
    uint8_t rst = minSubArrayLen(array, sizeof(array) / sizeof(uint8_t), 15);
    printf("%d\r\n", rst);
}