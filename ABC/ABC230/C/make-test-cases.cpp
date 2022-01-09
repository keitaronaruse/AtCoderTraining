/*
    make-test-cases.cpp
    ABC230 Problem C - X drawing
        https://atcoder.jp/contests/abc230/tasks/abc230_c
        Author: Keitaro Naruse
        Date:   2021-12-03, 2022-01-09
        MIT License
*/

#include <iostream>
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

    //  Minimum case
    if( argv[1][0] == '1' ) {
        const long long N = 1LL;
        const long long A = 1LL;
        const long long B = 1LL;
        std::cout << N << " " << A << " " << B << std::endl;
        const long long P = 1LL;
        const long long Q = 1LL;
        const long long R = 1LL;
        const long long S = 1LL;
        std::cout << P << " " << Q << " " << R << " " << S << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const long long N = 1000000000000000000LL;
        const long long A = 1000000000000000000LL;
        const long long B = 1000000000000000000LL;
        std::cout << N << " " << A << " " << B << std::endl;
        const long long P = 1000000000000000000LL;
        const long long Q = 1000000000000000000LL;
        const long long R = 1000000000000000000LL;
        const long long S = 1000000000000000000LL;
        std::cout << P << " " << Q << " " << R << " " << S << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< long long > dist; 
        dist = std::uniform_int_distribution< long long >( 1LL, 1000000000000000000LL );
        const long long N = dist( engine );

        dist = std::uniform_int_distribution< long long >( 1LL, N );
        const long long A = dist( engine );
        const long long B = dist( engine );
        std::cout << N << " " << std::min( A, B ) << " " << std::max( A, B ) << std::endl;

        dist = std::uniform_int_distribution< long long >( 1LL, N );
        const long long Q = dist( engine );
        const long long S = dist( engine );

        dist = std::uniform_int_distribution< long long >( 1LL, 1000L );
        const long long P = Q - dist( engine );
        const long long R = S - dist( engine );
        std::cout << P << " " << Q << " " << R << " " << S << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
