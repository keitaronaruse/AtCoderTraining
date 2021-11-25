/*
    ABC086C - Traveling
        https://atcoder.jp/contests/abs/tasks/arc089_a
        Author: Keitaro Naruse
        Date:   2021-11-23, 2021-11-25
        MIT License
*/

//  Solution
//  Manhattan distance: D = L1(xj, yj, yi, yi)
//  if tj-ti = D + 2k, k = 0, 1, ... -> Yes

#include <iostream>
#include <vector>

/*
    L1()
        returns L1 norm
*/
int L1(int xj, int yj, int xi, int yi)
{
    int dx = ( xj > xi )? xj - xi : xi - xj; 
    int dy = ( yj > yi )? yj - yi : yi - yj;

    return( dx + dy ); 
}

/*
    is_possible_move()
        determines if the distance of dL can be transited in time steps of dT
*/
bool is_possible_move( int dT, int dL )
{
    int k = 0;
    
    while( true ) {
        int h = dT - dL - k; 
        if( h == 0 ) {
            return( true );
        }
        else if( h > 0 ) {
            k += 2;
        }
        else {
            break;
        }
    }

    return( false );
}

int main()
{
    //  Read N
    int N( 0 );
    std::cin >> N;
    //  Debug
    std::cerr << N << std::endl;

    //  Read (ti, xi, ni)
    std::vector< int > t( N + 1, 0 );
    std::vector< int > x( N + 1, 0 );
    std::vector< int > y( N + 1, 0 );
    for( int i = 0; i != N; i++ ) {
        std::cin >> t.at( i + 1 ) >> x.at( i + 1 ) >> y.at( i + 1);
    }
    //  Debug
    for( int i = 0; i != N + 1; i++ ) {
        std::cerr << t.at( i ) << " " << x.at( i ) << " " << y.at( i ) << std::endl;
    }

    //  Main
    bool is_all_possible = true;
    for( int i = 0; i != N; i++ ) {
        //  See if the transition from i to i + 1 is possible
        int dT = t.at( i + 1 ) - t.at( i );
        int dL = L1( x.at( i + 1 ), y.at( i + 1 ), x.at( i ), y.at( i ) );
        std::cerr << dT << " " <<  dL << std::endl;
        
        if( !is_possible_move( dT, dL ) ) {
            is_all_possible = false;
            break;
        }
    }

    //  Show a result
    if( is_all_possible ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
