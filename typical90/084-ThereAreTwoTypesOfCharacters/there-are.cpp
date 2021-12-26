/*
    084 - There are two types of characters（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_cf
        Author: Keitaro Naruse
        Date:   2021-12-26
        MIT License
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//  Debug switch
const bool Debug = false;

int main()
{
    //  Read N and S
    int N = 0;
    std::string S;
    std::cin >> N >> S;
    if( Debug ) {
        std::cerr << N << std::endl << S << std::endl;
    }

    //  Preprocess
    std::vector< int > o( N, 0 ), x( N, 0 );
    if( S.at( 0 ) == 'o' ) {
        o.at( 0 ) = 1;
    } 
    else if( S.at( 0 ) == 'x' ) {
        x.at( 0 ) = 1;
    }
    for( int i = 1; i < N; i ++ ) {
        o.at( i ) = o.at( i - 1 );
        x.at( i ) = x.at( i - 1 );
        if( S.at( i ) == 'o' ) {
            o.at( i ) ++;
        } 
        else if( S.at( i ) == 'x' ) {
            x.at( i ) ++;
        }
    }

    if( Debug ) {
        for( int i = 0; i < N; i ++ ) {
            std::cerr << o.at( i ) << " ";
        }
        std::cerr << std::endl;
        for( int i = 0; i < N; i ++ ) {
            std::cerr << x.at( i ) << " ";
        }
        std::cerr << std::endl;
    }

    //  Main
    long long count = 0LL;
    //  My solution
    for( int i = 0; i < N - 1 ; i ++ ) {
        //  case of o 
        if( S.at( i ) == 'o' ) {
            //  Find the first appearing x by binary search
            //  If found, update the number of cases
            std::vector< int >::iterator it = std::upper_bound( 
                x.begin() + i + 1, x.end(), x.at( i ) 
            );
            if( it != x.end() ) {
                count += ( x.end() - it );
            }
        }
        //  case of x
        else if( S.at( i ) == 'x' ) {
            //  If found, update the number of cases
            std::vector< int >::iterator it = std::upper_bound( 
                o.begin() + i + 1, o.end(), o.at( i ) 
            );
            if( it != o.end() ) {
                count += ( o.end() - it );
            }
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
