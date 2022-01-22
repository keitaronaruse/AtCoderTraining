/**
* @file make-test-cases.cpp
* @brief make test cases for D - Knapsack 1
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_d
*/

#include <iostream>
#include <random>

const bool Debug = false; 

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist;
    
    //  Make N = [ 1, 100 ]
    dist = std::uniform_int_distribution< int >( 1, 100 );
    const int N = dist( engine ); 
    //  Make W = [ 1, 10^5 ]
    dist = std::uniform_int_distribution< int >( 1, 100000 );
    const int W = dist( engine ); 
    std::cout << N << " " << W << std::endl;

    //  Make wi = [ 1 ,W ], vi = [ 1, 10^9 ]
    for( int i = 0; i < N; i ++ ) {
        dist = std::uniform_int_distribution< int >( 1, W );
        const int w = dist( engine ); 
        dist = std::uniform_int_distribution< int >( 1, 1000000000 );
        const int v = dist( engine ); 
        std::cout << w << " " << v << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
