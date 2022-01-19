/**
* @file bit-brute-force.cpp
* @brief an example of the bit brute force search
* @author Keitaro Naruse
* @date 2022-01-19
* @copyright MIT License
*/

#include <iostream>

const bool Debug = false;

int main()
{
    //  Read N
    int N = 0; 
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    } 

    //  Make the mixmum number of combinations
    int K = 1 << N;
    if( Debug ) {
        std::cerr << K << std::endl;
    }
    //  Brute force search
    for( int i = 0; i < K; i ++ ) {
        std::cout << i << ": ";
        for( int j = N - 1; j >= 0; j -- ) {
            if( i & ( 1 << j ) ) {
                std::cout << "1";
            }
            else {
                std::cout << "0";
            }
        }
        std::cout << std::endl;
    }
}