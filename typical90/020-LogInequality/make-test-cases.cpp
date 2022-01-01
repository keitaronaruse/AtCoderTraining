/*
    make-test-cases.cpp
    020 - Log Inequality（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_t
        Author: Keitaro Naruse
        Date:   2021-12-09, 2022-01-01
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
        const long long A = 1;
        const int B = 1;
        const int C = 1;
        std::cout << A << " " << B << " " << C << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const long long A = 9000000000000000000LL;
        const int B = 17;
        const int C = 13;
        std::cout << A << " " << B << " " << C << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< long long > dist; 

        dist = std::uniform_int_distribution< long long >( 1LL, 9000000000000000000LL );
        const long long A = dist( engine );

        dist = std::uniform_int_distribution< long long >( 1LL, 17LL );
        const long long B = dist( engine );

        dist = std::uniform_int_distribution< long long >( 1LL, 13LL );
        const long long C = dist( engine );

        std::cout << A << " " << B << " " << C << std::endl;        
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
