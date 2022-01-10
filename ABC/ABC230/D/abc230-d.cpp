/*
    ABC230 Problem D - Destroyer Takahashi
        https://atcoder.jp/contests/abc230/tasks/abc230_d
        Author: Keitaro Naruse
        Date:   2022-01-10
        MIT License
*/

// # Solution
// - Suppose a punch is made at x 
// - ( Li, Ri ) if Ri < x, the wall is broken 
// - ( Lj, Rj ) if Lj < x + D, the wall is broken
// - ( Lj, Rj ) if Lj >= x + D, the wall is not broken
// - Make a new punch at Rj

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const bool Debug = false;

int main()
{
    //  Read N and K
    int N = 0, D = 0;
    std::cin >> N >> D;
    if( Debug ) {
        std::cerr << N << " " << D << std::endl;
    }
    //  Read Li and Ri
    std::vector< int > L( N, 0 ), R( N, 0 );
    std::vector< std::pair< int, int > > LR( N, std::make_pair( 0, 0 ) );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> L.at( i ) >> R.at( i );
        L.at( i ) --;
        R.at( i ) --;
        if( Debug ) {
            std::cerr << L.at( i ) << " " << R.at( i ) << std::endl;
        }
        LR.at( i ) = std::make_pair( L.at( i ), R.at( i ) );
    }

    //  Preprocess
    //  Sort LR by L in the ascending order
    std::sort( LR.begin(), LR.end(), 
        []( std::pair< int, int >& a, std::pair< int, int >& b ) { return( a.second < b.second ); }
    );
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << "( " << LR.at( i ).first << ", " << LR.at( i ).second << " )" <<std::endl;
        }
    }
    //  Main
    int count = 1;
    //  Ri
    int i = 0;
    int punch = LR.at( i ).second;
    while( i < N ) {
        //  Li
        if( Debug ) {
            std::cerr 
            << "Punch at: " << punch << " "
            << "to : " << punch + D - 1 << " "
            << "i: " << i << " " 
            << "L: " << LR.at( i ).first << std::endl;
        }
        if( LR.at( i ).first < punch + D ) {
            // A wall has been already broken
            i ++;
        }
        else {
            //  A wall has not been broken
            //  A new punch should be made 
            punch = LR.at( i ).second;
            count ++;
        }
    }

    //  Display result
    std::cout << count << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
