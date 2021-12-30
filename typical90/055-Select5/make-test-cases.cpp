/*
    make-test-cases.cpp
    055 - Select 5（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bc
        Author: Keitaro Naruse
        Date:   2021-11-30, 2021-12-30
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
        const int N = 5, P = 1, Q = 0;
        std::cout << N << " " << P << " " << Q << std::endl;
        const int A = 0;
        std::cout << A << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100, P = 1000000000, Q = 999999999;
        std::cout << N << " " << P << " " << Q << std::endl;
        for( int i = 0; i < N; i ++ ) {
            std::cout << "1000000000" << " ";
        }
        std::cout << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 5, 100 );
        const int N = dist( engine );
        dist = std::uniform_int_distribution< int >( 1, 1000000000 );
        const int P = dist( engine ); 
        dist = std::uniform_int_distribution< int >( 0, P - 1 );
        const int Q = dist( engine );
        std::cout << N << " " << P << " " << Q << std::endl;
        
        dist = std::uniform_int_distribution< int >( 0, 1000000000 );
        for( int i = 0; i < N; i ++ ) {
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
