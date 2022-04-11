/**
* @file abc221-d.cpp
* @brief ABC221 Problem D - Online games
* @author Keitaro Naruse
* @date 2022-04-09, 2022-04-11
* @copyright MIT License
* @details https://atcoder.jp/contests/abc221/tasks/abc221_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

template< class K, class V >
std::ostream& operator<<( std::ostream& os, const std::map< K, V >& m )
{
    for( const auto& p : m ) {
        os << "( " << p.first << ", " << p.second << " ) ";
    }
    return( os );
}


int main()
{
    //  Read N = [ 2, 2 * 10^5 ]
    int N;
    std::cin >> N;
    //  Read Ai, Bi = [ 1, 10^9 ]
    std::vector< int > A( N ), B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i ) >> B.at( i );
    }

    //  Main
    //  Preprocess
    std::map< int, int > delta_person;
    for( int i = 0; i < N; i ++ ) {
        delta_person[ A.at( i ) ] ++;
        if( delta_person.at( A.at( i ) ) == 0 ) {
            delta_person.erase( delta_person.find( A.at( i ) ) );
        }

        delta_person[ A.at( i ) + B.at( i ) ] --;
        if( delta_person.at( A.at( i ) + B.at( i ) ) == 0 ) {
            delta_person.erase( delta_person.find( A.at( i ) + B.at( i ) ) );
        }
    }

    //  Find solution
    std::map< int, int > person_day;
    auto it = delta_person.begin();
    int prev_day = it -> first;
    int num_persons = it -> second;
    it ++;
    for( ; it != delta_person.end(); it ++ ) {
        person_day[ num_persons ] += it -> first - prev_day;
        //  Update
        prev_day = it -> first;
        num_persons += it -> second;
    }
    for( int i = 1; i <= N; i ++ ) {
        std::cout << person_day[ i ] << " ";
    }
    std::cout << std::endl;

    //  Finalize
    return( 0 );
}
