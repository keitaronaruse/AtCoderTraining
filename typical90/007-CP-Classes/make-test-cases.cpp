/*
    make-test-cases.cpp
    007 - CP Classes（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_g
        Author: Keitaro Naruse
        Date:   2021-12-05, 2021-12-31
        MIT License
*/

#include <iostream>
#include <vector>
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
        const int N = 1;
        std::cout << N << std::endl;
        const int A = 0;
        std::cout << A << std::endl;

        const int Q = 1;
        std::cout << Q << std::endl;
        const int B = 0;
        std::cout << B << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 300000;
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int A = 1000000000;
            std::cout << A << " ";
        }
        std::cout << std::endl;

        const int Q = 300000;
        std::cout << Q << std::endl;
        for( int j = 0; j < Q; j ++ ) {
            const int B = 1000000000;
            std::cout << B << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 300000 );
        const int N = dist( engine );
        std::cout << N << std::endl;

        dist = std::uniform_int_distribution< int >( 0, 1000000000 );
        for( int i = 0; i < N; i ++ ) {
            const int A = dist( engine );
            std::cout << A << " ";
        }
        std::cout << std::endl;

        dist = std::uniform_int_distribution< int >( 1, 300000 );
        const int Q = dist( engine );
        std::cout << Q << std::endl;

        dist = std::uniform_int_distribution< int >( 0, 1000000000 );
        for( int j = 0; j < Q; j ++ ) {
            const int B = dist( engine );
            std::cout << B << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
