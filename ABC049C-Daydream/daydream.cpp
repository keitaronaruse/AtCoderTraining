/*
    ABC049C - 白昼夢
        https://atcoder.jp/contests/abs/tasks/arc065_a
        Author: Keitaro Naruse
        Date:   2021-11-18, 2021-11-21
        MIT License
*/
//
//  # Programming point
//  - Distinguish dream-erase? from dreamer-* 
//  # My solution
//  - if a string matches with dream
//    - if the follwoing matches with erase -> continue
//    - else if it does with er -> dreamer
//    - else -> No
//  - else if a string matches with erase
//    - if the following matches with r -> eraser
//    - else -> erase
//  - else -> No

#include <iostream>
#include <string>
#include <algorithm>

/*
    match_strings(b, e, b2, e2)
        # return 
        - true if [b, e] matches with [b2, e2]
        - false if not
*/
bool match_strings(std::string::iterator b, std::string::iterator e, 
    std::string::iterator b2, std::string::iterator e2 )
{
    //  Check empty strings
    //  If both of the strings are empty, matched
    if( ( b == e ) && ( b2 == e2 ) ) {
        return( true );
    }

    while( true ) {
        //  Continue the loop if the characters are same
        if(*b == *b2) {
            b ++;
            b2 ++;
            //  if either of the words is ended, matched
            if( ( b == e ) || ( b2 == e2 ) ) {
                return( true );
            }
        }
        else {
            //  Not match
            return( false );
        }
    }
  
    //  If it has come to here, all match
    return( true );
}

int main()
{
    //  Initialize
    //  literals
    std::string dream("dream"), erase("erase"), er("er"), r("r"); 

    //  Read S
    std::string S;
    std::cin >> S;
    //  Debug
    std::cerr << S << std::endl;

    //  Main 
    bool isMatched = true;
    std::string::iterator b = S.begin(), e = S.end();
    while( b != e ) {
        //  Match with dream
        if( match_strings( b, e, dream.begin(), dream.end() ) ) {
            b += dream.size();
            //  If it is at the end of the sentence, matched 
            if( b == e ) {
                break;
            } 

            //  Match with erase
            if( match_strings( b, e, erase.begin(), erase.end() ) ) {
                continue;
            }
            //  Match with er
            else if( match_strings( b, e, er.begin(), er.end() ) ) {
                b += er.size();
                //  If it is at the end of the sentence, matched 
                if( b == e ) {
                    break;
                } 
            }
            //  No match
            else {
                isMatched = false;
                break;
            }
        }
        //  Match with erase
        else if( match_strings( b, e, erase.begin(), erase.end() ) ) {
            b += erase.size();
            //  If it is at the end of the sentence, matched 
            if( b == e ) {
                break;
            } 

            if( match_strings( b, e, r.begin(), r.end() ) ) {
                b += r.size();
                //  If it is at the end of the sentence, matched 
                if( b == e ) {
                    break;
                } 
            }
        }
        else {
            //  No match
            isMatched = false;
            break;
        }
    }

    //  Print result
    if( isMatched ) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }

    //  Finalize
    std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
