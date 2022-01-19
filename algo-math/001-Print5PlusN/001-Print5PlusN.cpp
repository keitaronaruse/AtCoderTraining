/**
* @file 001-Print5PlusN.cpp
* @brief 001 - Print 5+N
* @author Keitaro Naruse
* @date 2022-01-19
* @copyright MIT License
*/

#include <iostream>

const bool Debug = false; 

int main()
{
    //  Read N = [ 1, 100 ]
    int N = 0; 
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Display the result
    std::cout << N + 5 << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
