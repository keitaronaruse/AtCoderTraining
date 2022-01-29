/*    
* @file make-test-cases.cpp
* @file make test cases for arc133-a.cpp
* @brief ARC133 Problem A - Erase by Value
* @author Keitaro Naruse
* @date 2022-01-22, 2022-01-29
* @copyright MIT License
* @details https://atcoder.jp/contests/arc133/tasks/arc133_a
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
    dist = std::uniform_int_distribution< int >( 1, 200000 );
    const int N  = dist( engine );
    std::cout << N << std::endl;
    
    dist = std::uniform_int_distribution< int >( 1, N );
    for( int i = 0; i < N; i ++ ) {
        const int a = dist( engine );
        std::cout << a  << " ";
    }
    std::cout << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
