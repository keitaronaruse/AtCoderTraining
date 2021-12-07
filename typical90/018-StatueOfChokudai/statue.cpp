/*
    018 - Statue of Chokudai（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_r
        Author: Keitaro Naruse
        Date:   2021-12-08
        MIT License
*/

// # Solution
// - 

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read T, L, X, Y
    int T = 0, L = 0, X = 0, Y = 0;
    std::cin >> T >> L >> X >> Y;
    //  Debug
    std::cerr << T << std::endl << L << " " << X << " " << Y << std::endl;
    //  Read Q and Ei
    int Q = 0;
    std::cin >> Q;
    //  Debug
    std::cerr << Q << std::endl;
    std::vector< int > E( Q );
    for( int i = 0; i < Q; i ++ ) {
        std::cin >> E.at( i );
        //  Debug
        std::cerr << E.at( i ) << std::endl;
    }
    
    //  Finalize
    //  Debug
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
