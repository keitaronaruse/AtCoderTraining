/*
    make-test-cases.cpp
    018 - Statue of Chokudai（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_r
        Author: Keitaro Naruse
        Date:   2021-12-08, 2022-01-01
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
        const int T = 2;
        std::cout << T << std::endl;
        const int L = 1;
        const int X = 1;
        const int Y = 1;
        std::cout << L << " " << X << " " << Y << std::endl;
        const int Q = 1;
        std::cout << Q << std::endl;
        const int E = 0;
        std::cout << E << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int T = 1000000000;
        std::cout << T << std::endl;
        const int L = 1000000000;
        const int X = 1000000000;
        const int Y = 1000000000;
        std::cout << L << " " << X << " " << Y << std::endl;
        const int Q = 1000;
        std::cout << Q << std::endl;
        for( int i = 0; i < Q; i ++ ) {
            const int E = T - Q + i;
            std::cout << E << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 

        dist = std::uniform_int_distribution< int >( 1, 1000000000 );
        const int T = dist( engine );
        std::cout << T << std::endl;

        const int L = dist( engine );
        const int X = dist( engine );
        const int Y = dist( engine );
        std::cout << L << " " << X << " " << Y << std::endl;
        
        dist = std::uniform_int_distribution< int >( 1, 1000 );
        const int Q = dist( engine );
        std::cout << Q << std::endl;

        dist = std::uniform_int_distribution< int >( 0, T - 1 );
        for( int i = 0; i < Q; i ++ ) {
            const int E = dist( engine );
            std::cout << E << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
