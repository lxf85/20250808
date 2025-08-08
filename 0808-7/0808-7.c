#include<stdio.h>
#include<stdint.h>
uint32_t swap_endian(uint32_t num)
{
    return ((num>>24)&0xFF)|((num>>8)&0xFF00)|((num<<8)&0xFF0000)|((num<<24)&0xFF000000);//位运算实现大端模式小端模式的互换
}
int main()
{
    uint32_t original_num=0x12253647;
    uint8_t *ptr= (uint8_t *)(&original_num);
    if(*ptr==0x47)
    {
        printf("本机为小端模式:0x%08x\n",original_num);
        printf("大端模式下为:0x%08x\n",swap_endian(original_num));
    }
    
    else if(*ptr==0x12)
    {
        printf("本机为大端模式:0x%08x\n",original_num);
        printf("小端模式下为:0x%08x\n",swap_endian(original_num));
    }
    return 0;
}