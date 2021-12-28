/*
    make-test-cases.cpp
    027 - Sign Up Requests （★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_x
        Author: Keitaro Naruse
        Date:   2021-11-27, 2021-12-29
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
        std::cout << "a" << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100000; 
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const std::string S = std::to_string( i );
            std::cout << S << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 100000 );
        
        const int N = dist( engine ); 
        std::cout << N << std::endl;

        for( int i = 0; i < N; i ++ ) {
            dist = std::uniform_int_distribution< int >( 1, 15 );
            const int K = dist( engine );

            dist = std::uniform_int_distribution< int >( 0, 10 + 26 - 1 );
            for( int k = 0; k < K; k ++ ) {
                int s = dist( engine ); 
                if( s < 10 ) {
                    std::cout << std::string( 1, s + '0' );
                }
                else {
                    std::cout << std::string( 1, s - 10 + 'a' );
                }
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
