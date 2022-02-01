/**
* @file abc237-d.cpp
* @brief ABC237 Problem D - LR insertion
* @author Keitaro Naruse
* @date 2022-01-30, 2022-02-01
* @copyright MIT License
* @details https://atcoder.jp/contests/abc237/tasks/abc237_d
*/

// # Solution

#include <iostream>
#include <string>
#include <list>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, std::list< int >& l )
{
    for( auto i : l ) {
        os << i << " ";
    }
    return( os );
}


int main()
{
    //  Read N = [ 1, 5 * 10^5 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    //  Read S
    std::string S = "";
    std::cin >> S;
    if( Debug ) {
        std::cerr << S << std::endl;
    }

    //  Main
    std::list< int > A = {};
    std::list< int >::iterator it = A.insert( A.begin(), 0 );
    for( int i = 0; i < N; i ++ ) {
        if( S.at( i ) == 'L' ) {
            it = A.insert( it , i + 1);
        }
        else {
            it ++;
            it = A.insert( it , i + 1);
        }
    }
    std::cout << A << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
