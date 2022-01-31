/**
* @file abc237-c.cpp
* @brief ABC237 Problem C - kasaka
* @author Keitaro Naruse
* @date 2022-01-30, 2022-01-31
* @copyright MIT License
* @details https://atcoder.jp/contests/abc237/tasks/abc237_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const bool Debug = false;

bool is_palindrome( const std::string& s )
{
    std::string::const_iterator b = s.begin(), e = s.end() - 1 ;
    while( b < e ) {
        if( *b != *e ) {
            return( false );
        }
        b ++;
        e --;
    }
    return( true );
}

std::string remove_a_from_head_tail( const std::string& s )
{

    std::string::const_iterator head = s.begin();
    std::string::const_iterator tail = s.end() - 1;
    //  Find not a from the head
    while( *head == 'a' ) {
        head ++;
    }
    //  Find not a from the head
    if( head != s.end() ) {
        while( *tail == 'a' ) {
            tail --;
        }
    }
    //  string a removed
    std::string t( head, tail + 1 );
    return( t );
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
    std::string t; 
    t = remove_a_from_head_tail( S );
    std::cerr << t << std::endl;
    is_palindromable = is_palindrome( t );
    //  Display result
    if( is_palindromable ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    
    // std::string r = S; 
    // std::reverse( r.begin(), r.end() );
    // if( Debug ) {
    //     std::cerr << s << std::endl;
    //     std::cerr << r << std::endl;
    // }

    // bool is_palindromable = false;
    // if( s == r ) {
    //     is_palindromable = true;
    // }
    // else {
    //     int a_num = 0;
    //     for( int k = 0; k < r.size(); k ++ ) {
    //         if( r.at( k ) == 'a') {
    //             a_num ++;
    //         }
    //         else {
    //             break;
    //         }
    //     }
    //     for( int k = 0; k < a_num; k ++ ) {
    //         s = "a" + s;
    //         r = r + "a";
    //         if( s == r ) {
    //             is_palindromable = true;
    //             break;
    //         }
    //     }
    // }
    // bool is_palindromable = false;
    // for( int k = 0; k < r.size(); k ++ ) {
    //     auto it = std::search( s.begin(), s.end(), r.begin() + k, r.end() );
    //     if( it != s.end() ) {
    //         // if( k == 0 ) {
    //             is_palindromable = true;
    //             break;
    //         // }
    //         // else {
    //         //     std::string extra( k, 'a' );
    //         //     std::string skipped( r.begin(), r.begin() + k );
    //         //     if( extra == skipped ) {
    //         //         is_palindromable = true;
    //         //     }
    //         //     else {
    //         //         is_palindromable = false;
    //         //     }
    //         //     if( Debug ) {
    //         //         std::cerr << "Matched at " << k << std::endl;
    //         //         std::cout << extra + s << std::endl;
    //         //     }
    //         //     break;
    //         // }
    //     }
    //     else {
    //         std::string extra( k, 'a' );
    //         std::string skipped( r.begin(), r.begin() + k );
    //         if( extra != skipped ) {
    //             is_palindromable = false;
    //             break;
    //         }
    //     }
    // }
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
