/**
 * @brief Calculate the integer square root of a number
 * @details This function returns the largest integer whose square is not greater than the given number.
 * @param n The number to compute the integer square root of
 * @return The integer square root
 */
ll isqrt(ll n){
    ll low = 0, high = n;
    while(low < high){
        ll mid = low + (high - low + 1) / 2;
        ll mid2 = mid * mid;
        if(mid2 == n){
            return mid;
        }
        if(mid * mid <= n){
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}