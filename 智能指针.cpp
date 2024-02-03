#include <iostream>
using namespace std;


// class shape_wrapper
// {
// public:
//     explicit shape_wrapper(
//         shape *ptr = nullptr) : ptr_(ptr) {}
//     ~shape_wrapper()
//     {
//         delete ptr_;
//     }
//     shape *get() const { return ptr_; }

// private:
//     shape *ptr_;
// };

// 似乎还是第一次写模板
template <typename T>
class smart_ptr
{
public:
    explicit smart_ptr(T *ptr = nullptr)
        : ptr_(ptr)
    {
    }
    ~smart_ptr()
    {
        delete ptr_;
    }
    T *get() const { return ptr_; }

    T &operator*() const { return *ptr_; }
    T *operator->() const { return ptr_; }
    operator bool() const { return ptr_; }

private:
    T *ptr;
};

int main()
{
    return 0;
}