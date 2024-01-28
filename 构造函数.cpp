#include<string>
#include<iostream>
using namespace std;

class Box
{
    public:
        double length;
        double breadth;
        double height;

        //函数声明
        double getVolume();
        void setLength(double len);
        void setBreadth(double bre);
        void setHeight(double hei);
};

double Box::getVolume()
{
    return length * breadth * height;
}

void Box::setLength(double len)
{
    length = len;
}
void Box::setBreadth(double bre)
{
    breadth = bre;
}
void Box::setHeight(double hei)
{
    height = hei;
}

//构造函数和析构函数
class Line
{
public:
    void setLength(double len);
    double getLength();
    Line();
    Line(double len);

private:
    double length = 0.0;
};

//构造函数
Line::Line()
{
    cout << "Object is being created" << endl;
}

//使用初始化列表来初始化字段
Line::Line(double len): length(len)
{
    cout << "Object is being created, length = " << len << endl;
    //length = len;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength()
{
    return length;
}
int main()
{
    /*Box Box1, Box2;
    double volume = 0.0;

    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    volume = Box1.getVolume();
    cout << "Box1 的体积" << volume << endl;

    volume = Box2.getVolume();
    cout << "Box2 的体积" << volume << endl;
    */

    Line line;
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;

    Line line1(180.0);
    cout << "Length of line:" << line1.getLength() << endl;


    return 0;
}
