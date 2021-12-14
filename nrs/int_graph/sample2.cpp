/*
 * AtCoder Beginner Contest 231 | D - Neighbors
 * @url https://atcoder.jp/contests/abc231/tasks/abc231_d
 * @author TwoSquirrels
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>

int main()
{
    unsigned int n, m;
    std::cin >> n >> m;
    std::vector< std::set< unsigned int> > partners( n );
    bool possible = true;
    
    // input and check three neighbors
    for( unsigned int i = 0; i < m; ++ i ) {
        unsigned int a, b;
        std::cin >> a >> b;
        if (!possible) continue;
        --a; --b;
        partners[a].insert(b);
        partners[b].insert(a);
        if (partners[a].size() > 2) possible = false;
        if (partners[b].size() > 2) possible = false;
    }

    // check loop
    if( possible ) {
        std::vector< bool > passed( n, false );
        while( possible ) {
            // find a person whose two neighbors are designated
            const unsigned int start = [&] {
                for ( unsigned int i = 0; i < n; i ++ ) {
                    if (!passed[i] && partners[i].size() == 2) {
                        return( i );
                    }
                }
                return( n );
            } ();

            if( start == n ) {
                break;
            }

            // crawl (2 direction)
            unsigned int now = start;
            bool is_sec_dir = false;
            while( possible ) {
                passed[ now ] = true;
                // if it's on the tip, move to start
                if( partners[ now ].size() == 1 ) {
                    if( is_sec_dir ) break;
                    now = start;
                    is_sec_dir = true;
                }
                // move
                possible = false;
                for(auto p_ite = partners[now].begin(); p_ite != partners[now].end(); p_ite++) {
                    if( !passed[*p_ite] ) {
                        now = *p_ite;
                        possible = true;
                        break;
                    }
                }
            }
        }
    }

    // output result
    std::cout << (possible ? "Yes" : "No") << std::endl;
    return( 0 );
}
