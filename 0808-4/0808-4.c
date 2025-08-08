#include<stdio.h>
#include<string.h>
#include<stdint.h>
void method1(float a,float b,char *buffer)//第一种方法，使用memcpy
{
	memcpy(buffer,&a,sizeof(float));
	memcpy(buffer+sizeof(float),&b,sizeof(float));
}
void extract1(const char *buffer,float *a,float *b)
{
	memcpy(a,buffer,sizeof(float));
	memcpy(b,buffer+sizeof(float),sizeof(float));
}
void method2(float a,float b,char *buffer)//第二种方法，强制类型转换
{
	char *p=(char *)(&a);
	for(int i=0;i<sizeof(float);i++)
	*(buffer+i)=*(p+i);
	p=(char *)(&b);
	for(int i=0;i<sizeof(float);i++)
	buffer[sizeof(float)+i]=p[i];
}
void extract2(char *buffer,float *a,float *b)
{
	*a=*((float *)buffer);
	*b=*((float *)(buffer+sizeof(float)));
}

void method3(float a, float b, char* buffer)//第三种方法，使用位域和位运算+memcpy
{
    
    uint32_t a_bits, b_bits;
    memcpy(&a_bits, &a, sizeof(float));
    memcpy(&b_bits, &b, sizeof(float));
  
    for (int i = 0; i < sizeof(float); i++) {
        buffer[i] = (a_bits >> (8 * i)) & 0xFF;
        buffer[sizeof(float) + i] = (b_bits >> (8 * i)) & 0xFF;
    }
}

void extract3(const char* buffer, float* a, float* b) {
    uint32_t a_bits = 0, b_bits = 0;
    for (int i = 0; i < sizeof(float); i++) 
	{
        a_bits |= ((uint32_t)(buffer[i] & 0xFF)) << (8 * i);
        b_bits |= ((uint32_t)(buffer[sizeof(float) + i] & 0xFF)) << (8 * i);
    }
    memcpy(a, &a_bits, sizeof(float));
    memcpy(b, &b_bits, sizeof(float));
}

int main()
{
	float a,b,a1,b1;
	printf("please enter two real numbers:");
	scanf("%f%f",&a,&b);
	char buffer[8];
	method1(a,b,buffer);
	extract1(buffer,&a1,&b1);
	printf("after method1 and extract1 a1=%f b1=%f\n",a1,b1);

	method2(a,b,buffer);
	extract2(buffer,&a1,&b1);
	printf("after method2 and extract2 a1=%f b1=%f\n",a1,b1);

	method3(a,b,buffer);
	extract3(buffer,&a1,&b1);
	printf("after method3 and extract3 a1=%f b1=%f\n",a1,b1);

	return 0;
}