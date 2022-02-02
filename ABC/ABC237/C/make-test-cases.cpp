/*    
* @file make-test-cases.cpp
* @brief make test cases for ABC237 Problem C - kasaka
* @author Keitaro Naruse
* @date 2022-01-30, 2022-02-01
* @copyright MIT License
* @details https://atcoder.jp/contests/abc237/tasks/abc237_c
*/

#include <iostream>
#include <random>
#include <string>

//  Debug flag
const bool Debug = false;

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int  > dist; 
    dist = std::uniform_int_distribution< int >( 1, 1000000 );
    const int N = dist( engine );

    std::string S( N, ' ' ); 
    dist = std::uniform_int_distribution< int >( 'a', 'z' );
    for( int i = 0; i < N; i ++ ) {
        S.at( i ) = dist( engine );
    }
    std::cout << S << std::endl;
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
