int main()
{
    char *ptr = new char[20];
    // delete []ptr;
    return 0;
}

// g++ -g mem_leak.cpp
// valgrind --leak-check=full ./a.out