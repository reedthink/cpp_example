#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

using namespace std;

void atomic_example()
{
    auto begin_time = chrono::steady_clock::now();
    atomic<int> counter = 0; // 原子化,相比于加锁解锁省时间
    // int counter = 0;
    mutex mtx;
    thread t1([&]
              {
        for (int i=0;i<1000000;i++)
        {
            // lock_guard grd(mtx);
            counter += 1;
        } });
    thread t2([&]
              {
        for (int i=0;i<1000000;i++)
        {
            // lock_guard grd(mtx);
            counter += 1;
        } });
    t1.join();
    t2.join();

    cout << counter << endl;
    auto dt = chrono::steady_clock::now() - begin_time;
    cout << "time: " << chrono::duration_cast<chrono::milliseconds>(dt).count() << "ms" << endl;
}

void mutex_example()
{
    auto begin_time = chrono::steady_clock::now();
    int counter = 0;
    mutex mtx;
    thread t1([&]
              {
        for (int i=0;i<1000000;i++)
        {
            lock_guard grd(mtx);
            counter += 1;
        } });
    thread t2([&]
              {
        for (int i=0;i<1000000;i++)
        {
            lock_guard grd(mtx);
            counter += 1;
        } });
    t1.join();
    t2.join();

    cout << counter << endl;
    auto dt = chrono::steady_clock::now() - begin_time;
    cout << "time: " << chrono::duration_cast<chrono::milliseconds>(dt).count() << "ms" << endl;
}

int main()
{
    atomic_example();
    mutex_example();
    return 0;
}