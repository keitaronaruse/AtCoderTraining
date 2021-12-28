/*
    make-test-cases.cpp
    001 - Yokan Party（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_a
        Author: Keitaro Naruse
        Date:   2021-12-29
        MIT License
*/

#include <iostream>
#include <set>
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
        const int L = 1;
        std::cout << N << " " << L << std::endl;
        
        const int K = 1;
        std::cout << K << std::endl;
        
        const int A = 1;
        std::cout << A << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100000;
        const int L = 1000000000;
        std::cout << N << " " << L << std::endl;
        
        const int K = 100000;
        std::cout << K << std::endl;
        
        for( int i = 0; i < N; i ++ ) {
            std::cout << L - N + i << " ";
        }
        std::cout << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 100000 );
        const int N = dist( engine );

        dist = std::uniform_int_distribution< int >( N + 1, 1000000000 );
        const int L = dist( engine );
        std::cout << N << " " << L << std::endl;
        
        dist = std::uniform_int_distribution< int >( 1, N );
        const int K = 1;
        std::cout << K << std::endl;

        std::set< int > A;
        dist = std::uniform_int_distribution< int >( 1, L );
        while( A.size() != N ) {
            A.insert( dist( engine ) );
        }
        for( auto a : A ) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
