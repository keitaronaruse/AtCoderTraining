/**
* @file make-test-cases.cpp
* @brief make test cases for B - Frog 2
* @author Keitaro Naruse
* @date 2022-01-20
* @copyright MIT LicenseA - Frog 1
* @details https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include <iostream>
#include <random>

const bool Debug = false; 

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist;
    
    //  Make N = [ 2, 100,000 ]
    dist = std::uniform_int_distribution< int >( 2, 100000 );
    const int N = dist( engine ); 

    //  Make K = [ 1, 100 ]
    dist = std::uniform_int_distribution< int >( 1, 100 );
    const int K = dist( engine ); 
    std::cout << N << " " << K << std::endl;

    //  Make Hi = [ 1, 10,000 ]
    dist = std::uniform_int_distribution< int >( 1, 10000 );
    for( int i = 0; i < N; i ++ ) {
        const int H = dist( engine ); 
        std::cout << H << " ";
    }
    std::cout << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
