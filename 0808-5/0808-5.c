#include<stdio.h>
#include<math.h>
#include"0808-5.h"
v add(v v1,v v2)//+
{
    v v3;
    v3.x=v1.x+v2.x;
    v3.y=v1.y+v2.y;
    v3.z=v1.z+v2.z;
    return v3;
}
v sub(v v1,v v2)//-
{
    v v3;
    v3.x=v1.x-v2.x;
    v3.y=v1.y-v2.y;
    v3.z=v1.z-v2.z;
    return v3;
}
double dot(v v1,v v2)//点乘
{
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}
double modulo(v v1)//求模
{
    return sqrt(dot(v1,v1));
}
v unitize(v v1)//化成单位向量
{
    v v2;
    v2.x=v1.x/modulo(v1);
    v2.y=v1.y/modulo(v1);
    v2.z=v1.z/modulo(v1);
    return v2;
}
v cross(v v1,v v2)//叉乘
{
    v v3;
    v3.x=v1.y*v2.z-v1.z*v2.y;
    v3.y=v2.x*v1.z-v1.x*v2.z;
    v3.z=v1.x*v2.y-v1.y*v2.x;
    return v3;
}

