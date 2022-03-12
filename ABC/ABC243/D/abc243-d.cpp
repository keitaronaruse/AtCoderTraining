/**
* @file abc243-d.cpp
* @brief ABC243 Problem Moves on Binary TreD
* @author Keitaro Naruse
* @date 2022-03-12
* @copyright MIT License
* @details https://atcoder.jp/contests/abc243/tasks/abc243_d
*/

// # Solution

#include <iostream>
#include <string>

int main()
{
    //  Read N = [ 1, 10^6 ]
    int N;
    long long X;
    std::cin >> N >> X;
    //  Read | S | = [ 1, 10^5 ]
    std::string S;
    std::cin >> S;

    //  Main
    std::string s, t = S;
    bool odd = (X % 2L == 1L);
    do {
        s = t;
        t = "";
        int i = 0;
        for( int i = 0; i < s.size(); ) {
            if( i < s.size() - 1 && s.at( i ) == 'R' && s.at( i + 1 ) == 'U' ) {
                i += 2;
            }
            else if(  i < s.size() - 1 && s.at( i ) == 'L' && s.at( i + 1 ) == 'U' ) {
                i += 2;
            }
            else if( i < s.size() - 1 && odd && s.at( i ) == 'U' && s.at( i + 1 ) == 'R' ) {
                i += 2;
            }
            else if( i < s.size() - 1 && !odd && s.at( i ) == 'U' && s.at( i + 1 ) == 'L' ) {
                i += 2;
            }
            else {
                t.push_back( s.at( i ) );
                i ++;
            }
        }
    } while( s != t );

    if( s.size() == 0 ) {
        std::cout << X << std::endl;
    }
    else {
        long long x = X;
        for( int i = 0; i < s.size(); i ++ ) {
            if( s.at( i ) == 'U' ) {
                x = x / 2L;
            }
            else if( s.at( i ) == 'L' ) {
                x = x * 2L;
            }
            else if( s.at( i ) == 'R' ) {
                x = x * 2L + 1L;
            }
        }
        std::cout << x << std::endl;
    }

    //  Finalize
    return( 0 );
}
