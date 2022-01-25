/*    
* @file make-test-cases.cpp
* @brief make test cases for ABC236 Problem A - chukodai
* @author Keitaro Naruse
* @date 2022-01-23
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_a
*/

#include <iostream>
#include <random>
#include <string>
#include <algorithm>

//  Debug flag
const bool Debug = false;

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist; 
    dist = std::uniform_int_distribution< int >( 2, 10 );
    const int N  = dist( engine );
    
    std::string S( N, ' ' );
    dist = std::uniform_int_distribution< int >( 'a', 'z' );
    for( int i = 0; i < N; i ++ ) {
        S.at( i ) = dist( engine );
    }
    std::cout << S << std::endl;

    dist = std::uniform_int_distribution< int >( 1, N );
    const int a = dist( engine ), b = dist( engine );
    std::cout << std::min( a, b)  << " " << std::max( a, b ) << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
