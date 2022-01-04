/*
    012 - Red Painting（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_l
        Author: Keitaro Naruse
        Date:   2021-01-04
        MIT License
*/

// # Solution
// - Union Find

#include <iostream>
#include <vector>

const bool Debug = true;
int H = 0;
int W = 0;

int id( int h, int w )
{
    return( h * W + w );
}

int main()
{
    //  Read H and W
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read Q
    int Q = 0;
    std::cin >> Q;
    if( Debug ) {
        std::cerr << Q << std::endl;
    }
    for( int i = 0; i < Q; i ++ ) {
        int t = 0;
        std::cin >> t;
        if( t == 1 ) {
            int r = 0, c = 0;
            std::cin >> r >> c;
            if( Debug ) {
                std::cerr << t << " " << r << " " << c << std::endl;;
            }
        }
        else if( t == 2 ) {
            int ra = 0, ca = 0, rb = 0, cb = 0;
            std::cin >> ra >> ca >> rb >> cb;
            if( Debug ) {
                std::cerr << t << " " << ra << " " << ca << " " << rb << " " << cb << std::endl;
            }
        }
    }
    
    //  Main
    int h = 0, w = 0;
    int k = id( h, w ); 

    //  Display result
    std::cout << std::endl; 

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
