/*
    079 - Two by Two（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_ca
        Author: Keitaro Naruse
        Date:   2021-12-24, 2022-01-03
        MIT License
*/

// # Solution
// - Make Dij the difference bwtween Aij and Bij
// - Apply operation to (i,j) to be Dij = 0
// - Judge if all Dij = 0

#include <iostream>
#include <vector>

namespace nrs {
    template < class T >
    T abs( T a )
    {
        return( ( a > 0 )? a : -a );
    }
}

//  Debug switch
const bool Debug = false;

int main()
{
    //  Read H and W
    int H = 0, W = 0; 
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }

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

    if( Debug ) {
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                std::cerr << D.at( i ).at( j ) << " ";
            }
            std::cerr << std::endl;
        }
    }

    //  Apply the operations to (i,j) to be Dij = 0
    long long count = 0;
    for( int i = 0; i < H - 1; i ++ ) {
        for( int j = 0; j < W - 1; j ++ ) {
            int diff = D.at( i ).at( j );
            //  Apply the operations to two by two neigbors
            for( int h = 0; h < 2; h ++ ) {
                for( int w = 0; w < 2; w ++ ) {
                    D.at( i + h ).at( j + w ) -= diff;
                }
            }
            count += ( long long ) nrs::abs( diff );
        }
    }
    if( Debug ) {
        for( int i = 0; i < H; i ++ ) {
            for( int j = 0; j < W; j ++ ) {
                std::cerr << D.at( i ).at( j ) << " ";
            }
            std::cerr << std::endl;
        }
    }

    //  Check if Dij are all zero
    bool isYes = true;
    for( int i = 0; i < H; i ++ ) {
        if( D.at( i ).at( W - 1 ) != 0 ) {
            isYes = false;
            std::cout << "No" << std::endl;
            return( 0 );
        }
    }
    for( int j = 0; j < W; j ++ ) {
        if( D.at( H - 1 ).at( j ) != 0 ) {
            isYes = false;
            std::cout << "No" << std::endl;
            return( 0 );
        }
    }

    //  Display result
    if( isYes ) {
        std::cout << "Yes" << std::endl;
        std::cout << count << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
