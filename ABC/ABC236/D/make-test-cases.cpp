/*    
* @file make-test-cases.cpp
* @brief make test cases for ABC236 Problem D - Dance
* @author Keitaro Naruse
* @date 2022-01-23, 2022-01-28
* @copyright MIT License
* @details https://atcoder.jp/contests/abc236/tasks/abc236_d
*/

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <string>

//  Debug flag
const bool Debug = false;

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int > dist; 
    dist = std::uniform_int_distribution< int >( 1, 8 );
    const int N  = dist( engine );
    std::cout << N << std::endl;
    
    dist = std::uniform_int_distribution< int >( 0, 1 << 30 );
    for( int i = 0; i < 2 * N - 1; i ++ ) {
        for( int j = i + 1; j < 2 * N; j ++ ) {
            std::cout << dist( engine ) << " ";
        }
        std::cout << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
