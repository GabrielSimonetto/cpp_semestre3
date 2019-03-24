#include  <iostream>
using  namespace  std;

int  main() {
    int * b = new  int[5];
    int * it = &b[0];
    (*it++) = 8;
    *it = 4;
    b[2] = 3;

    std::cout <<'b'<<std::endl;
    std::cout <<b[0]<<std::endl;
    std::cout <<b[1]<<std::endl;
    std::cout <<"it"<<std::endl;
    std::cout <<it[0]<<std::endl;
    std::cout <<it[1]<<std::endl;
}