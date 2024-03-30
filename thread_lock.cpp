// 死锁

// 两种解决方案：
// 1. 同样顺序上锁
// 2. 标准库 lock(lk1, lk2, lk3)

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx1, mtx2, mtx3;

int counter = 0;

void func1()
{
    for (int i = 0; i < 100000; i++)
    {
        {
            // unique_lock<mutex> lock1(mtx1);
            // unique_lock<mutex> lock2(mtx2);
            unique_lock<std::mutex> lk1(mtx1, std::defer_lock);
            unique_lock<std::mutex> lk2(mtx2, std::defer_lock);
            std::lock(lk2, lk1);
            counter++;
            // cout << "thread 1 running" << endl;
        }
    }
}

void func2()
{
    for (int i = 0; i < 100000; i++)
    {
        {
            unique_lock<mutex> lock1(mtx1);
            unique_lock<mutex> lock2(mtx2);
            counter++;
            // cout << "thread 2 running" << endl;
        }
    }
}

void func3()
{
    for (int i = 0; i < 100000; i++)
    {
        {
            unique_lock<mutex> lock1(mtx1);
            unique_lock<mutex> lock2(mtx2);
            counter++;
            // cout << "thread 2 running" << endl;
        }
    }
}

int main()
{
    thread thr1(func1), thr2(func2), thr3(func3);
    thr1.join();
    thr2.join();
    thr3.join();

    cout << counter << endl;

    return 0;
}