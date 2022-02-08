/*
* @file make-test-cases.cpp
* @brief make test cases for 072 - Loop Railway Plan（★4）
* @author Keitaro Naruse
* @date 2022-02-08
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_bt
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
    dist = std::uniform_int_distribution< int >( 1, 16 );
    const int N = dist( engine );
    const int H = dist( engine );
    const int W = N / H + 1;
    std::cout << H << " " << W << std::endl;

    dist = std::uniform_int_distribution< int >( 0, 1 );
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            if( dist( engine ) == 1) {
                std::cout << ".";
            }
            else {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
