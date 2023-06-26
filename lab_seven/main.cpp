#include "init.h"
#include <iostream>
int main() {
    Buffer<double> My_buf(5);
    try {
        My_buf.insert_back(3);
        std::cout << My_buf[0] << std::endl;
        My_buf.insert_begin(4);
        My_buf.insert_back(6);
        My_buf.print();
        std::cout << "\n";
        My_buf.insert_index(5, 1);
        My_buf.print();
        My_buf.insert_begin(8);
        std::cout << My_buf[3] << std::endl;
        //My_buf.it_print();
        My_buf.pop_beginnig();
        My_buf.insert_begin(10);
        My_buf.pop_beginnig();
        My_buf.print();
        std::cout << "\n";
        My_buf.pop_beginnig();
        My_buf.insert_begin(7);
        My_buf.insert_begin(10);
        My_buf.insert_index(11, 2);
        My_buf.print();
        std::cout << "\n";
        My_buf.pop_index(2);
        My_buf.print();
    }
    catch (WrongAction &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
