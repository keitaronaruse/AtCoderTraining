/**
* @file make-test-cases.cpp
* @brief make test cases for H - Grid 1
* @author Keitaro Naruse
* @date 2022-02-05
* @copyright MIT License
* @details https://atcoder.jp/contests/dp/tasks/dp_h
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
    dist = std::uniform_int_distribution< int >( 2, 1000 );
    const int H = dist( engine ); 
    const int W = dist( engine ); 
    std::cout << H << " " << W << std::endl;

    //  Make aij = { '.', '#' }
    dist = std::uniform_int_distribution< int >( 0, 7 );
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            if( h == 0 && w == 0 ) {
                std::cout << '.';
            }
            else if( h == H - 1 && w == W - 1 ) {
                std::cout << '.';
            }
            else {
                if( dist( engine ) == 0 ) {
                    std::cout << '#';
                }
                else {
                    std::cout << '.';
                }
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
