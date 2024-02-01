#include <iostream>
using namespace std;
class Quote
{
public:
    Quote() = default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const;
    virtual double net_price(std::size_t n) const;

private:
    string bookNo;

protected:
    double price = 0.0;
};

class Bulk_quote : public Quote // 继承
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);
    // overside显式注明使用哪个成员函数改写基类的虚函数
    double net_price(std::size_t) const override;

private:
    std::size_t min_qty = 0; // 适用折扣政策的最低购买量
    double discount = 0.0;    // 以小数表示的折扣额
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    // 根据传入的item的形参对象类型调用net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << "total due : " << ret << endl;
    return ret;
}

int main()
{
    // std::cout << "vvvvhjKjjK" ;
    return 0;
}