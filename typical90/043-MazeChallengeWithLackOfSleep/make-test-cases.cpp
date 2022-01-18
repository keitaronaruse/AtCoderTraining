/*
    make-test-cases.cpp
    043 - Maze Challenge with Lack of Sleep
        https://atcoder.jp/contests/typical90/tasks/typical90_aq
        Author: Keitaro Naruse
        Date:   2022-01-13, 2022-01-18
        MIT License
*/

#include <iostream>
#include <random>

//  Debug flag
const bool Debug = false;

int main( int argc, char* argv[] )
{
    if( argc != 2 ) {
        std::cerr << "make-test-cases [1-3]" << std::endl;
        return( -1 );
    }

    //  Minimum case
    if( argv[1][0] == '1' ) {
        const int H = 2;
        const int W = 2;
        std::cout << H << " " << W << std::endl;
        const int Rs = 1;
        const int Cs = 1;
        std::cout << Rs << " " << Cs << std::endl;
        const int Rt = H;
        const int Ct = W;
        std::cout << Rt << " " << Ct << std::endl;
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                char S = '.';
                std::cout << S;
            }
            std::cout << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int H = 1000;
        const int W = 1000;
        std::cout << H << " " << W << std::endl;
        const int Rs = 1;
        const int Cs = 1;
        std::cout << Rs << " " << Cs << std::endl;
        const int Rt = H;
        const int Ct = W;
        std::cout << Rt << " " << Ct << std::endl;
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                char S = '.';
                std::cout << S;
            }
            std::cout << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 1000 );
        const int H = dist( engine );
        const int W = dist( engine );
        std::cout << H << " " << W << std::endl;

        dist = std::uniform_int_distribution< int >( 1, H );
        const int Rs = dist( engine );
        const int Rt = dist( engine );

        dist = std::uniform_int_distribution< int >( 1, W );
        const int Cs = dist( engine );
        const int Ct = dist( engine );
        
        std::cout << Rs << " " << Cs << std::endl;
        std::cout << Rt << " " << Ct << std::endl;

        dist = std::uniform_int_distribution< int >( 0, 1 );
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                char S = dist( engine ) ? '.' : '#';
                std::cout << S;
            }
            std::cout << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
