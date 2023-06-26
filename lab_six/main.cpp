#include "sixth.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <list>

bool is_even(int x) {
    return (x % 2 == 0);
}

bool is_digit(double x) {
    return ((x >= 0) and (x <= 9));
}

int main() {
    std::vector<int> first_vector = {12, 8, 10, 94, 34, 18};
    std::vector<int> second_vector = {11, 7, 9, 35, 32, 15};
    std::list<int> my_list = {2, 6, 8, 10};
    Queue<int> Q;
    Q.Enqueue(3);
    Q.Enqueue(4);
    //Q.Dequeue();
    std::cout << std::boolalpha << All_of(first_vector.begin(), first_vector.end(), is_even) << std::endl;
    std::cout << std::boolalpha << All_of(Q.begin(), Q.end(), is_even) << std::endl;
    std::cout << std::boolalpha << One_of(my_list.begin(), my_list.end(), is_digit) << std::endl;
    std::cout << *Find_backwards(second_vector.begin(), second_vector.end(), 32) << std::endl;
    std::cout << std::distance(second_vector.begin(), Find_backwards(second_vector.begin(), second_vector.end(), 32)) << std::endl;

}
