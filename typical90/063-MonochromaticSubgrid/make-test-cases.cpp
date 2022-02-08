/*
* @file make-test-cases.cpp
* @brief make test cases for 063 - Monochromatic Subgrid（★4）
* @author Keitaro Naruse
* @date 2022-02-08
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_bk
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
    dist = std::uniform_int_distribution< int >( 1, 8 );
    const int H = dist( engine );
    dist = std::uniform_int_distribution< int >( 1, 10000 );
    const int W = dist( engine );
    std::cout << H << " " << W << std::endl;

    dist = std::uniform_int_distribution< int >( 1, H * W );
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
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
