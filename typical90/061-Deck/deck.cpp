/*
    061 - Deck（★2）
        https://atcoder.jp/contests/typical90/tasks/typical90_bi
        Author: Keitaro Naruse
        Date:   2021-11-30, 2021-12-01
        MIT License
*/

// # Solution
// - Implement deck by deque

#include <iostream>
#include <deque>

int main()
{
    //  Read Q
    int Q = 0;
    std::cin >> Q;
    //  Debug
    // std::cerr << Q << std::endl;
    
    //  Main Read ti and make xi
    //  Deck as duque
    std::deque<int> deck;
    for( int i = 0; i != Q; i ++ ) {
        int t = 0, x = 0;
        std::cin >> t >> x;
        //  Debug
        // std::cerr << t << " " << x << std::endl;

        if( t == 1 ) {
            deck.push_front( x );
        }
        else if( t == 2 ) {
            deck.push_back( x );
        }
        else if( t == 3 ) {
            std::cout << deck.at( x - 1 ) << std::endl;
        }
        else {
            //  Debug
            std::cerr << "Never happens." << std::endl;
        }
    }

    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
