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


// If you want instead 
// true, true, true, false, false, false

ll l = low, r = high;
while(l<r){
    ll mid = l + (r-l+1)/2 // bias right
    if(check(mid)){
        l=mid;
    } else{
        r = mid-1;
    }
}
