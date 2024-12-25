long long xor1n(long long n){
    long long mod = n % 4;
    if(mod == 0){
        return n;
    }
    if(mod == 1){
        return 1;
    }
    if(mod == 2){
        return n + 1;
    }
    return 0;
}

long long xorlr(long long l, long long r){
    return xor1n(l - 1) ^ xor1n(r);
}