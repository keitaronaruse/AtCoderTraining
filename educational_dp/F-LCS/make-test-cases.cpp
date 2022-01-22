/**
* @file make-test-cases.cpp
* @brief make test cases for F - LCS
* @author Keitaro Naruse
* @date 2022-01-22
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_f
*/

#include <iostream>
#include <random>

const bool Debug = false; 

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist;
    
    //  Make M, N = [ 1, 3000 ]
    dist = std::uniform_int_distribution< int >( 1, 3000 );
    const int M = dist( engine ); 
    const int N = dist( engine ); 

    //  Make s
    std::string s( M, ' ' );
    dist = std::uniform_int_distribution< int >( 0, 25 );
    for( int i = 0; i < M; i ++ ) {
        s.at( i ) = dist( engine ) + 'a';
    }
    std::cout << s << std::endl;

    //  Make t
    std::string t( N, ' ' );
    dist = std::uniform_int_distribution< int >( 0, 25 );
    for( int j = 0; j < N; j ++ ) {
        t.at( j ) = dist( engine ) + 'a';
    }
    std::cout << t << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
