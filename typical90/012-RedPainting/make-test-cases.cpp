/*
    make-test-cases.cpp
    012 - Red Painting（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_l
        Author: Keitaro Naruse
        Date:   2021-01-04, 2022-01-05
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
        const int H = 1;
        const int W = 1;
        std::cout << H << " " << W << std::endl;
        
        const int Q = 1;
        std::cout << Q << std::endl;
        const int t = 1, r = 1, c = 1;
        std::cout << t << " " << r << " " << c << std::endl;
    }
    //  Maximum case
    else if( argv[1][0] == '2' ) {
        const int H = 2000;
        const int W = 2000;
        std::cout << H << " " << W << std::endl;
        
        const int Q = 100000;
        std::cout << Q << std::endl;
        for( int i = 0; i < Q; i ++ ) {
            const int t = i % 2 + 1, ra = 1, ca = 1, rb = H, cb = W;
            if( t == 1 ) {
                std::cout << t << " " << ra << " " << ca << std::endl;
            }
            else if( t == 2 ) {
                std::cout << t << " " << ra << " " << ca << " " << rb << " " << cb << std::endl;
            }
        }
    }
    //  Random case
    else if( argv[1][0] == '3' ) {
        std::random_device seed_gen;
        std::default_random_engine engine( seed_gen() );

        std::uniform_int_distribution< int > dist; 
        dist = std::uniform_int_distribution< int >( 1, 2000 );
        const int H = dist( engine );
        const int W = dist( engine );
        std::cout << H << " " << W << std::endl;
        
        dist = std::uniform_int_distribution< int >( 1, 100000 );
        const int Q = dist( engine );
        std::cout << Q << std::endl;

        for( int i = 0; i < Q; i ++ ) {
            const int t = i % 2 + 1;
            dist = std::uniform_int_distribution< int >( 1, H );
            const int ra = dist( engine ), rb = dist( engine );
            dist = std::uniform_int_distribution< int >( 1, W );
            const int ca = dist( engine ), cb = dist( engine );
            if( t == 1 ) {
                std::cout << t << " " << ra << " " << ca << std::endl;
            }
            else if( t == 2 ) {
                std::cout << t << " " << std::min( ra, rb ) << " " << std::min( ca, cb ) << " " 
                << std::max( ra, rb ) << " " << std::max( ca, cb ) << std::endl;
            }
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
