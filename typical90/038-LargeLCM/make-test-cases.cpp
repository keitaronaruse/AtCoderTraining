/*
    make-test-cases.cpp
    038 - Large LCM
        https://atcoder.jp/contests/typical90/tasks/typical90_al
        Author: Keitaro Naruse
        Date:   2021-12-10, 2022-01-01
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
        const long long A = 1LL;
        const long long B = 1LL;
        std::cout << A << " " << B << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const long long A = 1000000000000000000LL;
        const long long B = 1000000000000000000LL;
        std::cout << A << " " << B << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< long long > dist; 

        dist = std::uniform_int_distribution< long long >( 1, 1000000000000000000LL );
        const long long A = dist( engine );
        const long long B = dist( engine );
        std::cout << A << " " << B << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
