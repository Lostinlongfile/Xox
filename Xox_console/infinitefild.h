#ifndef INFINITEFILD_H
#define INFINITEFILD_H
#include <vector>
#include <iostream>
#include <ostream>
class point{
public:
    point(int a=0,int b=0):x(a),y(b){}
    int x;
    int y;
    void show()
    {
        std::cout<<"("<<x<<";"<<y<<") ";
    }
    bool operator==(const point& b)
    {
        return (x==b.x)&&(y==b.y);
    }
};
std::ostream & operator<<(std::ostream& out,const point p);
class InfiniteFild
{
    int min_x,min_y,max_x,max_y;
    std::vector< std::vector<short> >fild;
    public:
        InfiniteFild();
        ~InfiniteFild();
        int get_mix(){return min_x;};
        int get_max(){return max_x;};
        int get_miy(){return min_y;};
        int get_may(){return max_y;};
        bool isExist(int x,int y);
        bool isNearExist(int x,int y);
        void show();
        void add_right_colmn();
        void add_bottom_row();
        void add_top_row();
        void add_left_colmn();
        short get(int x,int y);
        void set(int x,int y,short type);
        bool isAll(int x,int y,short type);
        bool isTypeWin(short type);
        bool isAnyNear(int x,int y);
        void clear();
};

#endif // INFINITEFILD_H
