//  N = 2, H = 1    [ 0 ]
//  N = 4, H = 2    [ 0 ][ 1-3 ]   
//  N = 6, H = 3    [ 0 ][ 1-4 ][ 2-5 ]   
//  N = 8, H = 4    [ 0 ][ 1-5 ][ 2-6 ][ 3-7 ]
//  N = 16, H = 8   [ 0 ][ 1-9 ][ 2-10 ][ 3-11 ][ 4-12 ][ 5-13 ][ 6-14 ][ 7-15 ]

class division {
    public:
        int n, h;
        std::vector< int > first, second;
        std::vector< int > min_value, max_value;
    public:
        division( int n_ ) : n( n_ ), h( n_ / 2 ) {
            first  = std::vector< int >( h, 0 );
            second = std::vector< int >( h, 0 );
            min_value = std::vector< int >( h, 0 );
            max_value = std::vector< int >( h, 0 );
            min_value.at( 0 ) = 0;
            max_value.at( 0 ) = 0;
            for( int i = 1; i < h; i ++ ) {
                min_value.at( i ) = i;
                max_value.at( i ) = i + h;
            }
            for( int i = 0; i < h; i ++ ) {
                first.at( i ) = min_value.at( i );
                second.at( i ) = first.at( i ) + h;
            }
        }
        bool next_division()
        {
            bool is_available = false;
            for( int i = h - 1; i > 0; i -- ) {
                first.at( i ) ++;
                if( first.at( i ) > max_value.at( i ) ) {
                    first.at( i ) = min_value.at( i );
                }
                else {
                    is_available = true;
                    break;
                }
            }
            for( int i = 1; i < h; i ++ ) {
                if( first.at( i ) == min_value.at( i ) ) {
                    first.at( i ) = first.at( i - 1 ) + 1;
                }
            }
            int k = 0;
            for( int i = 1; i < n; i ++ ) {
                if( first.end() == std::find( first.begin(), first.end(), i ) ) {
                    second.at( k ) = i;
                    k ++;
                }
            }
            return( is_available );
        }
};

