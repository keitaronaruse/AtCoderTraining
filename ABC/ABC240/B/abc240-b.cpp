/**
* @file abc240-b.cpp
* @brief ABC240 Problem B
* @author Keitaro Naruse
* @date 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc240/tasks/abc240_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <map>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::vector< int >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read N = [ 1, 1000 ]
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N <<  std::endl;
    }
    //  Read Ai = [ 1, 10^9 ]
    std::vector< int > A( N, 0 );
    std::map< int, int > counters;
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        counters[ A.at( i ) ] ++;
    }
    if( Debug ) {
        std::cerr << A << std::endl;
    }

    //  Main
    int num = 0;
    for( auto p : counters ) {
        num ++ ;
    }
    std::cout << num << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
