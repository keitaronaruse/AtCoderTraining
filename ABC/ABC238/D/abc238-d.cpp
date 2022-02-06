/**
* @file abc237-d.cpp
* @brief ABC237 Problem D - cdc LR insertion
* @author Keitaro Naruse
* @date 2022-02-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc238/tasks/abc238_d
*/

// # Solution

#include <iostream>
#include <list>
#include <string>
#include <list>

const bool Debug = false;

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
    std::list< int > A = { 0 };
    std::list< int >::iterator it = A.begin();
    for( int i = 0; i < N; i ++ ) {
        if( S.at( i ) == 'R' ) {
            it ++;
        }
        it = A.insert( it, i + 1 );
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
