#include <stdio.h>

typedef unsigned char uint8_t;

uint8_t delete_enum(uint8_t* data, uint8_t len, uint8_t target)
{
    uint8_t* p_slow = data;
    uint8_t* p_fast = data;
    
    /*若元素顺序不可变*/
    for(uint8_t i = 0; i < len; i++)
    {
        if(*(p_fast + i) != target)
        {
            *(p_slow++) = *(p_fast + i);
        }
    }
}


void main(void)
{
    uint8_t data[] = {0, 3, 6, 8, 4, 6, 8, 1, 2, 3, 4, 6, 7};

    printf("len = %d\r\n", delete_enum(data, sizeof(data) / sizeof(uint8_t), 3));

    for(uint8_t i = 0; i < sizeof(data) / sizeof(uint8_t); i++)
    {
        printf("%d ", data[i]);
    }
}
