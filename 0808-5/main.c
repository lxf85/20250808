#include<stdio.h>
#include"0808-5.h"
int main()
{
    v AB,AC1,n,AF;
    AB.x=0.0;AB.y=1.0;AB.z=0.0;//给定点到直线上点A的方向向量
    AC1.x=-1.0;AC1.y=1.0;AC1.z=-1.0;//直线AC1的方向向量
    float d1=modulo(cross(AB,AC1))/modulo(AC1);

    AF.x=0.0;AF.y=0.5;AF.z=0.0;//直线与平面平行 取其上一点即可F
    n.x=1.0;n.y=2.0;n.z=1.0;//法向量 易得
    float d2=dot(n,AF)/modulo(n);

    printf("(distance between B and AC1)d1:%.2f\n",d1);
    printf("(distance between FC and AEC1)d2:%.2f\n",d2);

    return 0;
}