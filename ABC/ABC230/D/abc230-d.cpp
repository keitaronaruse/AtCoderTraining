/*
    ABC230 Problem D - Destroyer Takahashi
        https://atcoder.jp/contests/abc230/tasks/abc230_d
        Author: Keitaro Naruse
        Date:   2022-01-10
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const bool Debug = true;

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
    int head = 0;
    int count = 1;
    //  Ri
    int punch = LR.at( head ).second;
    while( head < N ) {
        //  Li
        if( LR.at( head ).first <= punch + D ) {
            std::cerr << "Head: " << head << std::endl;
            // Broken walls
            head ++;
        }
        else {
            std::cerr << "Punch" << std::endl;
            punch = LR.at( head ).second;
            count ++;
        }
    }
    //  if LR.at( head ) > punch
    //  or head == N

    //  Display result
    std::cout << count << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
