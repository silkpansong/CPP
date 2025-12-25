// Always go for first true in 
// false , false, false , *true* , true , true

ll l = low, r = high; // answer is in [l, r]
while (l < r) {
    ll mid = l + (r - l) / 2;
    if (check(mid)) {
        r = mid;      // mid might be the answer
    } else {
        l = mid + 1;  // mid is definitely bad
    }
}
return l; // first true
