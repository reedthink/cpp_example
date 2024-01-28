// 析构函数不会返回任何值，也不能带有任何参数
#include <iostream>

using namespace std;

class Line
{
public:
    void setLength(double len);
    double getLength();
    Line();
    ~Line(); //析构函数声明

private:
    double length;
};

Line::Line()
{
    cout << "Object is being created" << endl;
}

Line::~Line()
{
    cout << "Object is being deleted" << endl;
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
    Line line;

    line.setLength(666.0);
    cout << "Length of line:" << line.getLength() << endl;
}
