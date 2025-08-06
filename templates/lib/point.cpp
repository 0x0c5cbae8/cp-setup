#include <templates/init>

template <typename T> struct point{
    T x, y;
    point():x(0),y(0){}
    point(T _x,T _y):x(_x),y(_y){}
    point& operator+=(const point &p){x+=p.x;y+=p.y;return *this;}
    point& operator-=(const point &p){x-=p.x;y-=p.y;return *this;}
    point& operator*=(const T &k){x*=k;y*=k;return *this;}
    point& operator/=(const T &k){x/=k;y/=k;return *this;}
    point operator-()const{return point(-x,-y);}
};
