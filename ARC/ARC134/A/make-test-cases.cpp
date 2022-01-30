/*    
* @file make-test-cases.cpp
* @brief ARC134 Problem A
* @author Keitaro Naruse
* @date 2022-01-29, 2022-01-30
* @copyright MIT License
* @details https://atcoder.jp/contests/arc134/tasks/arc134_a
*/

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

//  Debug flag
const bool Debug = false;

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist; 
    dist = std::uniform_int_distribution< int >( 1, 100000 );
    const int N  = dist( engine );
    
    std::uniform_int_distribution< long long > dist_ll; 
    dist_ll = std::uniform_int_distribution< long long >( 1LL, 1000000000000000000LL );
    const long long L = dist_ll( engine );
    dist_ll = std::uniform_int_distribution< long long >( 1LL, L );
    const long long W = dist_ll( engine );
    std::cout << N << " " << L << " " << W << std::endl;

    std::vector< long long > a( N );
    dist_ll = std::uniform_int_distribution< long long >( 1LL, L - W );
    for( int i = 0; i < N; i ++ ) {
        a.at( i ) = dist_ll( engine );
    }
    std::sort( a.begin(), a.end() );

    for( int i = 0; i < N; i ++ ) {
        std::cout << a.at( i ) << " ";
    }
    std::cout << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
