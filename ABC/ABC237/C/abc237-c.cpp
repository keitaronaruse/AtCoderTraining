/**
* @file abc237-c.cpp
* @brief ABC237 Problem C - kasaka
* @author Keitaro Naruse
* @date 2022-01-30, 2022-02-01
* @copyright MIT License
* @details https://atcoder.jp/contests/abc237/tasks/abc237_c
*/

// # Solution
// - Count p, the number of a's in the head end
// - Count q, the one in the tail end
// - If p <= q, remove a's from the head and tail
//   - If the rest string is palindrome, output Yes
//   - else output No
// - All a's

#include <iostream>
#include <string>
#include <algorithm>

const bool Debug = false;

bool is_palindrome( const std::string& s )
{
    std::string::const_iterator b = s.begin(), e = s.end() - 1;
    while( b < e ) {
        if( *b != *e ) {
            return( false );
        }
        b ++;
        e --;
    }
    return( true );
}

int count_head_a( const std::string& s )
{
    int num = 0;
    std::string::const_iterator it = s.begin();
    //  Count the number of a's from the head
    while( it != s.end() ) {
        if( *it == 'a' ) {
            num ++;
            it ++;
        }
        else {
            break;
        }
    }
    return( num );
}

int count_tail_a( const std::string& s )
{
    int num = 0;
    std::string::const_iterator it = s.end() - 1;
    //  Count the number of a's from the tail
    while( it != s.begin() ) {
        if( *it == 'a' ) {
            num ++;
            it --;
        }
        else {
            break;
        }
    }
    if( *it == 'a' ) {
        num ++;
    }
    return( num );
}

int main()
{
    //  Read S
    std::string S = "";
    std::cin >> S;
    if( Debug ) {
        std::cerr << S << std::endl;
    }

    //  Main
    bool is_palindromable = false;
    int p = count_head_a( S );
    int q = count_tail_a( S );
    if( p <= q ) {
        std::string t = "";
        if( p != S.size() ) {
            t = std::string( S.begin() + p, S.end() - q );
            if( Debug ) {
                std::cerr << t << std::endl;
            } 
        }
        is_palindromable = is_palindrome( t );
    }

    if( is_palindromable ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
