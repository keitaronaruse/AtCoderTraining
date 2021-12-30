/*
    make-test-cases.cpp
    061 - Deck（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bi
        Author: Keitaro Naruse
        Date:   2021-11-30, 2021-12-30
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
        const int Q = 2;
        std::cout << Q << std::endl;
        int t = 1, x = 1;
        std::cout << t << " " << x << std::endl;
        t = 3, x = 1;
        std::cout << t << " " << x << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int Q = 100000;
        std::cout << Q << std::endl;

        int t = 1, x = 0;
        for( int i = 0; i < Q ; i ++ ) {
            if( i % 3 == 0 ) {
                x ++;
                t = 1;
            }
            else if( i % 3 == 1 ) {
                x ++;
                t = 2;
            }
            else if( i % 3 == 2 ) {
                t = 3;
            }
            std::cout << t << " " << x << std::endl;
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 2, 100000 );
        const int Q = dist( engine );
        std::cout << Q << std::endl;
        
        dist = std::uniform_int_distribution< int >( 1, 100000000 );
        int t = 1, x = dist( engine );
        std::cout << t << " " << x << std::endl; 
        int count = 1;

        for( int i = 1; i < Q; i ++ ) {
            dist = std::uniform_int_distribution< int >( 1, 3 );
            t = dist( engine );
            if( ( t == 1 ) || ( t == 2 ) ) {
                dist = std::uniform_int_distribution< int >( 1, 100000000 );
                x = dist( engine );
                count ++;
            }
            else if( t == 3 ) {
                x = count;
            }
            std::cout << t << " " << x << std::endl; 
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
