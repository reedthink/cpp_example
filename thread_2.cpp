#include <iostream>
#include <thread>
#include <string>

void download(std::string file)
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Downloading" << file
                  << " (" << i * 10 << "%)..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    std::cout << "Download complete: " << file << std::endl;
}

void interact()
{
    std::string name;
    std::cin >> name;
    std::cout << "Hi, " << name << std::endl;
}

int main()
{
    // download("H.zip");
    std::thread t1([&]
                   { download("H.zip"); });
    interact();
    t1.join();//main函数等待t1线程执行完
    return 0;
}

/*
想法：其实用锁还是挺朴实的思路

mutex 的三种用法
1. 纯手动lock unlock
2. lock_guard 离开作用域自动解锁
3. unique_lock  更灵活，可以手动提前解锁，也可以用defer_lock实现手动上锁 
*/