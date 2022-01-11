/*
    make-test-cases.cpp
    ABC233 Problem A - 10yen Stamp
        https://atcoder.jp/contests/abc233/tasks/abc233_a
        Author: Keitaro Naruse
        Date:   2021-12-25, 2022-01-11
        MIT License
*/

#include <iostream>
#include <algorithm>
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
        const int X = 1;
        const int Y = 1;
        std::cout << X << " " << Y << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int X = 1000;
        const int Y = 1000;
        std::cout << X << " " << Y << std::endl;
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );
        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 1000 );

        const int X = dist( engine );
        const int Y = dist( engine );
        std::cout << X << " " << Y << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
