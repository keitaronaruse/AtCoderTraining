/*
    make-test-cases.cpp
    010 - Score Sum Queries（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_j
        Author: Keitaro Naruse
        Date:   2021-11-27, 2021-12-27
        MIT License
*/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

//  Debug flag
const bool Debug = false;

int main( int argc, char* argv[] )
{
    if( argc != 2 ) {
        std::cerr << "make-test-cases [1-3]" << std::endl;
        return( -1 );
    }

    int N = 0, Q = 0;
    int C = 0, P = 0, L = 0, R = 0;
    //  Minimum case
    if( argv[1][0] == '1' ) {
        N = 1; 
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            C = 1, P = 0;
            std::cout << C << " "<< P << std::endl;
        }
        Q = 1;
        std::cout << Q << std::endl;
        for( int j = 0; j < Q; j ++ ) {
            L = 1, R = 1;
            std::cout << L << " "<< R << std::endl;
        }
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        N = 100000; 
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            C = 2, P = 100;
            std::cout << C << " "<< P << std::endl;
        }
        Q = 100000;
        std::cout << Q << std::endl;
        for( int j = 0; j < Q; j ++ ) {
            L = 1, R = N;
            std::cout << L << " "<< R << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 100000 );
        N = dist( engine ); 
        std::cout << N << std::endl;
        
        for( int i = 0; i < N; i ++ ) {
            dist = std::uniform_int_distribution< int >( 1, 2 );
            C = dist( engine );
            dist = std::uniform_int_distribution< int >( 0, 100 );
            P = dist( engine );
            std::cout << C << " " << P << std::endl;
        }

        dist = std::uniform_int_distribution< int >( 1, 100000 );
        Q = dist( engine ); 
        std::cout << Q << std::endl;
        dist = std::uniform_int_distribution< int >( 1, N );
        for( int j = 0; j < Q; j ++ ) {
            L = dist( engine );
            R = dist( engine );
            std::cout << std::min( L, R ) << " " << std::max( L, R ) << std::endl;
        } 
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
