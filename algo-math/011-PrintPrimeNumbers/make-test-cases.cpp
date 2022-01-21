/**
* @file make-test-cases.cpp
* @brief make test cases for 011 - Print Prime Numbers
* @author Keitaro Naruse
* @date 2022-01-21
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_k
*/

#include <iostream>
#include <random>

const bool Debug = false; 

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    
    //  Make N = [ 1, 50 ]
    std::uniform_int_distribution<> dist( 2, 3000 );
    const int N = dist( engine );
    std::cout << N << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
