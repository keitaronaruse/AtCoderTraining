/*
    make-test-cases.cpp
    022 - Cubic Cake（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_v
        Author: Keitaro Naruse
        Date:   2021-12-28
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

    long long  A = 0LL, B = 0LL, C = 0LL;

    //  Minimum case
    if( argv[1][0] == '1' ) {
        A = 1LL; 
        B = 1LL; 
        C = 1LL; 
        std::cout << A << " " << B << " " << C << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        A = 1000000000000000000LL; 
        B = 1000000000000000000LL; 
        C = 1000000000000000000LL; 
        std::cout << A << " " << B << " " << C << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< long long > dist; 
        dist = std::uniform_int_distribution< long long >( 1LL, 1000000000000000000LL );
        A = dist( engine ); 
        B = dist( engine ); 
        C = dist( engine ); 
        std::cout << A << " " << B << " " << C << std::endl;        
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
