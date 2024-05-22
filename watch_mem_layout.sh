# 一些查看内存布局的编译命令
g++ -fdump-lang-class multi_inheritance_2.cpp
# clang++ -Xclang -fdump-record-layouts -Xclang -fdump-vtable-layouts  multi_inheritance_2.cpp -O0 > a.txt