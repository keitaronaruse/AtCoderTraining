/**
* @file abc243-d.cpp
* @brief ABC243 Problem D - Moves on Binary Tree
* @author Keitaro Naruse
* @date 2022-03-12, 2022-03-13
* @copyright MIT License
* @details https://atcoder.jp/contests/abc243/tasks/abc243_d
*/

// # Solution

#include <iostream>
#include <string>
#include <deque>

int main()
{
    //  Read N = [ 1, 10^6 ], X = [ 1, 10^18 ]
    int N;
    long long X;
    std::cin >> N >> X;
    //  Read | S | = [ 1, 10^6 ]
    std::string S;
    std::cin >> S;

    //  Main
    std::deque< char > s_stack;
    for( int i = 0; i < N; i ++ ) {
        if( s_stack.empty() ) {
            s_stack.push_back( S.at( i ) );
        }
        else {
            char c = s_stack.back();
            if( ( c == 'R' || c == 'L' ) && S.at( i ) == 'U' ) {
                //  (R, U) and (L, U) are canceled
                s_stack.pop_back();
            }
            else {
                s_stack.push_back( S.at( i ) );
            }
        }
    }

    long long x = X;
    for( int i = 0; i < ( int ) s_stack.size(); i ++ ) {
        switch( s_stack.at( i ) ) {
            case 'U': x = x / 2L; break;
            case 'L': x = x * 2L; break;
            case 'R': x = x * 2L + 1L; break;
            default: break;
        }
    }
    std::cout << x << std::endl;
    
    //  Finalize
    return( 0 );
}
