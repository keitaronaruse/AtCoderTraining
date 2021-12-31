/*
    nrs::binary_search
        returns the absolute value of the arugument, implmented by template
        Author: Keitaro Naruse
        Date:   2021-12-31
        MIT License
*/

#include <iostream>
#include <vector>

namespace nrs {
    template < class T >
    T abs( T a )
    {
        return( ( a > 0 )? a : -a );
    }
}

namespace nrs {
    int binary_search( int ok, int ng, bool pred( int ) )
    {
        while( nrs::abs( ok - ng ) > 1 ) {
            int mid = ( ok + ng ) / 2;
            if( pred( mid ) ) {
                ok = mid;
            }
            else {
                ng = mid;
            }
        }

        return( ok );
    }
}

//  Test driver
bool is_okay( int idx )
{
    // const std::vector< int > a = { 2, 4, 6 };
    bool ret = false;

    if( idx > 2 ) {
        ret = true;
    }

    return( ret );
}

int main()
{    
    int ok = 3, ng = -1;

    ok = nrs::binary_search( ok, ng, is_okay );
    std::cout << ok << std::endl;

    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
