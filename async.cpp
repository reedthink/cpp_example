#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <future>

using namespace std;

mutex output_lock;

int func(const char* name)
{
    this_thread::sleep_for(100ms); // 自定义字面量
    lock_guard<mutex> guard(output_lock);
    cout << "thread id : " << this_thread::get_id() << ' ';
    cout << "I am thread " << name << '\n';

    return 0;
}

int main()
{
    // thread t1{func, "A"};
    // thread t2{func, "B"};
    // t1.join();
    // t2.join();

    //可能同时可能延时
    auto a1 = std::async(func, "1 Hello");
    
    // prints "world!" when a2.get() or a2.wait() is called
    auto a2 = std::async(std::launch::deferred, func, "2 world!");
    // concurrently
    auto a3 = std::async(std::launch::async, func, "3 JKJK");

    auto val = a2.get();

    return 0;
}
