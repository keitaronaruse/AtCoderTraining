/**
* @file make-test-cases.cpp
* @brief 007 - Number of Multiples 1
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT License
* @details https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_g
*/

#include <iostream>
#include <random>
#include <algorithm>

const bool Debug = false; 

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    
    //  Make N = [ 1, 10^6 ]
    std::uniform_int_distribution<> dist;
    dist = std::uniform_int_distribution<> ( 1, 1000000 );
    const int N = dist( engine );
    
    dist = std::uniform_int_distribution<> ( 1, N );
    const int X = dist( engine );
    const int Y = dist( engine );
    std::cout << N << " " << std::min( X, Y ) << " " << std::max( X, Y ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
