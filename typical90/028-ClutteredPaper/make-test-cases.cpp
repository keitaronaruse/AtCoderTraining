/*
    make-test-cases.cpp
        https://atcoder.jp/contests/typical90/tasks/typical90_ab
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
        std::cerr << "make-test-cases [1-3]" << std::endl;
        return( -1 );
    }

    //  Minimum case
    if( argv[1][0] == '1' ) {
        const int N = 1;
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int lx = 0, ly = 0, rx = 1, ry = 1;
            std::cout << lx << " " << ly << " " << rx << " " << ry << std::endl;
        }        
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int N = 100000;
        std::cout << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            const int lx = 0, ly = 0, rx = 1000, ry = 1000;
            std::cout << lx << " " << ly << " " << rx << " " << ry << std::endl;
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

        dist = std::uniform_int_distribution< int >( 1, 1000 );
        for( int i = 0; i < N; i ++ ) {
            const int lx = dist( engine ), ly = dist( engine ), 
                rx = dist( engine ), ry = dist( engine );
            std::cout << std::min( lx, rx ) << " " << std::min( ly, ry ) << " " 
                << std::max( lx, rx ) << " " << std::max( ly, ry ) << std::endl;
            ;
        }     
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
