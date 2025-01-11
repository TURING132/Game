/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */



class Solution {
public:
    int guess (int num){
        return true;
    }
    int guessNumber(int n) {
        int l = 1, r = n, mid;
        while(l < r){
            mid = l + (r - l)/2 ;
            if(guess(mid) != 1) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};