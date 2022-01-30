/**
* @file arc134-a.cpp
* @brief ARC134 Problem A
* @author Keitaro Naruse
* @date 2022-01-29, 2022-01-30
* @copyright MIT License
* @details https://atcoder.jp/contests/arc134/tasks/arc134_a
*/

// # Solution
// - State: a head pointer
// - For each of the existing sheets
//   - Find the length between the head pointer and the head of the next sheet 
//   - If the legth is greater than 0, update the number of sheets
//   - Update: the head pointer += W

#include <iostream>
#include <vector>

const bool Debug = false;

long long num_covers( long long interval, long long width )
{
    long long num = ( interval + width - 1LL ) / width;
    // if( interval % width == 0 ) {
    //     num = interval / width;
    // }
    // else {
    //     num = interval / width + 1;
    // }
    return( num );
}

int main()
{
    //  Read N = [ 1, 10^5 ]
    //  Read W, L = [ 1, 10^18 ]
    int N = 0;
    long long W = 0LL, L = 0LL;
    std::cin >> N >> L >> W;
    if( Debug ) {
        std::cerr << N << " " << L << " " << W << std::endl;
    }
    //  Read ai = [ 0, L-W ]
    std::vector< long long > a( N + 1, 0LL );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> a.at( i );
    }
    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << a.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    //  Preprocess
    a.at( N ) = L;

    //  Result
    long long num_sheets = 0LL, head = 0LL;
    
    //  from the last tail to the next head
    for( int i = 0; i <= N; i ++ ) {
        if( head < a.at( i ) ) {
            num_sheets += num_covers( a.at( i ) - head, W );
            if( Debug ) {
                std::cerr << head << " ";
            }
        }
        head = a.at( i ) + W;
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    //  Display the result
    std::cout << num_sheets << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
