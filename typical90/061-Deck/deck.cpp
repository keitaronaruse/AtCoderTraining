/*
    061 - Deck（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bi
        Author: Keitaro Naruse
        Date:   2021-11-30
        MIT License
*/

// # Solution

#include <iostream>
#include <deque>

int main()
{
    //  Read Q
    int Q = 0;
    std::cin >> Q;
    //  Debug
    std::cerr << Q << std::endl;
    
    //  Read ti and make xi
    std::vector< int > t( Q ), x( Q );
    for( int i = 0; i != Q; i ++ ) {
        std::cin >> t.at( i ) >> x.at( i );
        //  Debug
        std::cerr << t.at( i ) << " " << x.at( i ) << std::endl;
    }
    
    //  Main
    std::deque<int> deck;

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
