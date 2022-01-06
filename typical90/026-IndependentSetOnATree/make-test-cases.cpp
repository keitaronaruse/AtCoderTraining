/*
    make-test-cases.cpp
    026 - Independent Set on a Tree（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_z
        Author: Keitaro Naruse
        Date:   2022-01-06
        MIT License
*/

#include <iostream>
#include <random>

//  Debug flag
const bool Debug = false;

int main( int argc, char* argv[] )
{
    if( argc != 2 ) {
        std::cerr << "make-test-cases [1-4]" << std::endl;
        return( -1 );
    }

    //  Minimum case
    if( argv[1][0] == '1' ) {
        const int N = 2;
        std::cout << N << std::endl;
        for( int i = 0; i < N - 1; i ++ ) {
            const int A = 1, B = 2;
            std::cout << A << " " << B << std::endl;
        }        
    }
    //  Maximum case 1: deep
    else if( argv[1][0] == '2' ) {
        const int N = 100000;
        std::cout << N << std::endl;
        for( int i = 0; i < N - 1; i ++ ) {
            const int A = i + 1, B = i + 2;
            std::cout << A << " " << B << std::endl;
        }        
    }
    //  Maximum case 2: wide
    else if( argv[1][0] == '3' ) {
        const int N = 100000;
        std::cout << N << std::endl;
        for( int i = 0; i < N - 1; i ++ ) {
            const int A = 1, B = i + 2;
            std::cout << A << " " << B << std::endl;
        }        
    }
    //  Random case
    else if( argv[1][0] == '4' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 100000 );
        const int N = dist( engine );
        std::cout << N << std::endl;
        

        for( int i = 0; i < N - 1; i ++ ) {
            const int A = i + 1;
            dist = std::uniform_int_distribution< int >( i + 2, N );
            const int B = dist( engine );
            std::cout << A << " " << B << std::endl;
        }        
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
