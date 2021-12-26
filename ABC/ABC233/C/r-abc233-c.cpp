/*
    ABC233 Problem C - Product
        https://atcoder.jp/contests/abc233/tasks/abc233_c
        Author: Keitaro Naruse
        Date:   2021-12-25
        MIT License
*/

// # Solution
// - Greedy, try all combinations

#include <iostream>
#include <vector>

namespace nrs {
    bool list_comb( std::vector< int >& comb, const std::vector< int >& len ) 
    {
        int n = comb.size();
        bool next_exist = true;
        
        for( int i = n - 1; i >= 0; i -- ) {
            comb.at( i ) ++;
            if( comb.at( i ) < len.at( i ) ) {
                break;
            }
            else {
                comb.at( i ) = 0;
                if( i == 0) {
                    next_exist = false;
                }
            } 
        }
        return( next_exist );
    }
}

int main()
{
    //  Read N and X
    int N = 0;
    long long X = 0LL;
    std::cin >> N >> X;

    //  Read Li and Aij
    std::vector< std::vector< int > > A( N );
    std::vector< int > L( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> L.at( i );
        A.at( i ) = std::vector< int >( L.at( i ) );
        for( int j = 0; j < L.at( i ); j ++ ) {
            std::cin >> A.at( i ).at( j );
        }
    }

    //  Main
    long long count = 0LL;
    std::vector< int > comb( N, 0 );    
    do {
        //  Debug
        // for( int i = 0; i < comb.size(); i ++ ) {
        //     std::cout << comb.at( i ) << " ";
        // }
        // std::cout << std::endl;

        //  Find product
        bool valid = true; 
        long long prod = 1LL;
        for( int i = 0; i < N; i ++ ) {
            prod *= ( (long long) A.at( i ).at( comb.at( i ) ) );
            if( prod > X ) {
                valid = false;
                break;
            }
        } 
        if( ( prod == X ) && valid ) {
            count ++;
        }
    } while( nrs::list_comb( comb, L ) );

    //  Display result
    std::cout << count << std::endl;
    
    return( 0 );
}
