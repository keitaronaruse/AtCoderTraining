/*
    make-test-cases.cpp
    016 - Minimum Coins（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_p
        Author: Keitaro Naruse
        Date:   2021-12-06, 2022-01-01
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
        const int N = 1;
        std::cout << N << std::endl;
        const int A = 1;
        const int B = 1;
        const int C = 1;
        std::cout << A << " " << B << " " << C << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 1000000000;
        std::cout << N << std::endl;
        const int A = 1000000000;
        const int B = 1000000000;
        const int C = 1000000000;
        std::cout << A << " " << B << " " << C << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 

        while( true ) {
            dist = std::uniform_int_distribution< int >( 1, 1000000 );
            const int A = dist( engine );
            const int B = dist( engine );
            const int C = dist( engine );

            const int L = 9999;
            dist = std::uniform_int_distribution< int >( 0, L );
            const int kA = dist( engine );
            dist = std::uniform_int_distribution< int >( 0, L - kA );
            const int kB = dist( engine );
            dist = std::uniform_int_distribution< int >( 0, L - kA - kB );
            const int kC = dist( engine );

            const long long N 
                = ( long long ) kA * ( long long ) A 
                + ( long long ) kB * ( long long ) B 
                + ( long long ) kC * ( long long ) C;
            if( N <= 1000000000LL ) {
                std::cout << N << std::endl;
                std::cout << A << " " << B << " " << C << std::endl;
                break;
            }
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
