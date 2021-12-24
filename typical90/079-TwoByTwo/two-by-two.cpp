/*
    079 - Two by Two（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_ca
        Author: Keitaro Naruse
        Date:   2021-12-24
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>

//  Debug switch
const bool Debug = true;

int main()
{
    //  Constant

    //  Read H and W
    int H = 0, W = 0; 
    std::cin >> H >> W;

    //  Read Aij
    std::vector< std::vector< int > > A( H, std::vector< int >( W, 0 ) );
    for( int i = 0; i < H; i ++ ) {
        for( int j = 0; j < W; j ++ ) {
            std::cin >> A.at( i ).at( j );
            if( Debug ) {
                std::cerr << A.at( i ).at( j ) << " ";
            }
        }
        if( Debug ) {
            std::cerr << std::endl;
        }
    }

    //  Read Bi
    std::vector< std::vector< int > > B( H, std::vector< int >( W, 0 ) );
    for( int i = 0; i < H; i ++ ) {
        for( int j = 0; j < W; j ++ ) {
            std::cin >> B.at( i ).at( j );
            if( Debug ) {
                std::cerr << B.at( i ).at( j ) << " ";
            }
        }
        if( Debug ) {
            std::cerr << std::endl;
        }
    }

    //  Main
    bool isYes = false;
    //  Make Dij, the difference between Aij and Bij
    std::vector< std::vector< int > > D( H, std::vector< int >( W, 0 ) );
    for( int i = 0; i < H; i ++ ) {
        for( int j = 0; j < W; j ++ ) {
            D.at( i ).at( j ) = A.at( i ).at( j ) - B.at( i ).at( j );
            if( Debug ) {
                std::cerr << D.at( i ).at( j ) << " ";
            }
        }
        if( Debug ) {
            std::cerr << std::endl;
        }
    }
    
    //  Display result
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
