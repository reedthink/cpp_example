#include <cstdio>
#include <memory>

struct C
{
    C()
    {
        printf("分配内存\n");
    }
    ~C()
    {
        printf("释放内存\n");
    }
};

int main()
{
    C *p_old = new C;
    std::unique_ptr<C> p = std::make_unique<C>();
    std::shared_ptr<C> p_shared = std::make_shared<C>();
    // p.func 和p->func的区别
}