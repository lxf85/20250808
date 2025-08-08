#ifndef _5_H
#define _5_H
struct vector3f{
    double x,y,z;
};
typedef struct vector3f v;
v add(v,v);//加
v sub(v,v);//减
double dot(v,v);//点乘
double modulo(v);//求模
v unitize(v);//单位化
v cross(v,v);//叉乘

#endif