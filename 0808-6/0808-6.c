#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
int main()
{
    int k;
    printf("please enter a number to initilize the seed:");//初始化产生随机数的种子
    scanf("%d",&k);
    srand(k);

    uint32_t result=0;
    const int num=32;
    for(int i=1;i<=32;i++)
    {
        int rand_num = rand()%101;
        if(rand_num > 50)
        result |= (1u<<(i-1));//位运算
    }
    printf("the result is 0x%08x(%u)\n",result,result);
    return 0;
}