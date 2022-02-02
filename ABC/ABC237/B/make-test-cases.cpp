/*    
* @file make-test-cases.cpp
* @brief make test cases for ABC237 Problem B - Matrix Transposition
* @author Keitaro Naruse
* @date 2022-01-30
* @copyright MIT License
* @details https://atcoder.jp/contests/abc237/tasks/abc237_b
*/

#include <iostream>
#include <random>

//  Debug flag
const bool Debug = false;

int main()
{
    std::random_device seed_gen;
    std::default_random_engine engine( seed_gen() );
    std::uniform_int_distribution< int  > dist; 
    dist = std::uniform_int_distribution< int >( 1, 100000 );
    const int H = dist( engine );
    const int W = 100000 / H;
    std::cout << H << " " <<  W << std::endl;

    dist = std::uniform_int_distribution< int >( 1, 1000000000 );
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            const int A = dist( engine ); 
            std::cout << A << " ";
        }
        std::cout << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
