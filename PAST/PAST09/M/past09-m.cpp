/**
* @file past09-m.cpp
* @brief PAST 9 Problem M - 名前の変更
  @author Keitaro Naruse
* @date 2022-03-22
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_m
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <utility>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>

template < class T >
using BBST = __gnu_pbds::tree< T, 
    __gnu_pbds::null_type, std::less< T >, 
    __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) 
{
    for( auto k : v ) {
        os << k << " ";
    }
    os << std::endl;
    return( os );
}

int main()
{
    //  Read N, Q = [ 1, 10^5 ]
    int N, Q;
    std::cin >> N >> Q;

    //  Read S( N )
    std::vector< std::string > S( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> S.at( i );
    }

    //  Read X( Q ), T( Q )
    std::vector< int > X( Q );
    std::vector< std::string > T( Q );
    for( int j = 0; j < Q; j ++ ) {
        std::cin >> X.at( j ) >> T.at( j );
    }

    //  Preprocess
    //  Master name list M( N + Q )
    std::vector< std::string > M( N + Q );
    //  Copy S to M
    std::copy( S.begin(), S.end(), std::back_inserter( M ) );
    //  Copy T to M
    std::copy( T.begin(), T.end(), std::back_inserter( M ) );
    //  Sort and erase duplicates
    std::sort( M.begin(), M.end() );
    M.erase( std::unique( M.begin(), M.end() ), M.end() );

    //  Make a table of S -> id in M
    std::vector< int > s_id( N );
    for( int i = 0; i < N; i ++ ) {
        s_id.at( i ) = std::lower_bound( M.begin(), M.end(), S.at( i ) ) - M.begin();
    }

    //  Make a table of T -> id in M
    std::vector< int > t_id( Q );
    for( int j = 0; j < Q; j ++ ) {
        t_id.at( j ) = std::lower_bound( M.begin(), M.end(), T.at( j ) ) - M.begin();
    }

    //  Main
    using nid_i = std::pair< int, int >;
    std::set< nid_i > nid_i_s;

    BBST< nid_i> set;
    //  Put (Si, i) as ( s_id, i )
    for( int i = 0; i < N; i ++ ) {
        // nid_i_s.insert( std::make_pair( s_id.at( i ), i ) );
        set.insert( std::make_pair( s_id.at( i ), i ) );
    }

    //  Query
    for( int j = 0; j < Q; j ++ ) {
        // auto it = nid_i_s.begin(); 
        // for( int i = 0; i < X.at( j ) - 1; i ++ ) {
        //     it ++;
        // }
        // int k = it -> second; 
        // s_id.at( k ) = t_id.at( j );
        // nid_i_s.erase( it ); 
        // nid_i_s.insert( std::make_pair( s_id.at( k ), k ) );

        auto itr = set.find_by_order( X.at( j ) - 1 );
        int k = itr -> second;
        s_id.at( k ) = t_id.at( j );
        set.erase( itr );
        set.insert( std::make_pair( s_id.at( k ), k ) );
    }

    //  Output
    for( int i = 0; i < N; i ++ ) {
        std::cout << M.at( s_id.at( i ) ) << " ";
    }
    std::cout << std::endl;
    
    return( 0 );
}
