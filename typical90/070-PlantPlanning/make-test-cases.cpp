/*
* @file make-test-cases.cpp
* @brief make test cases for 070 - Plant Planning（★4）
* @author Keitaro Naruse
* @date 2022-02-08
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_br
*/

#include <iostream>
#include <random>

//  Debug flag
const bool Debug = false;

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );

    std::uniform_int_distribution< int > dist; 
    dist = std::uniform_int_distribution< int >( 1, 100000 );
    const int N = dist( engine );
    std::cout << N << std::endl;

    dist = std::uniform_int_distribution< int >( -1000000000, 1000000000 );
    for( int i = 0; i < N; i ++ ) {
        const int X = dist( engine ), Y = dist( engine );
        std::cout << X << " " << Y << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
