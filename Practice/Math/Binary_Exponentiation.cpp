long long binExp(long long a, long long b) {
  if (b == 0)
    return 1;

  long long res = binExp(a, b / 2) % MOD;
  if (b & 1) {
    return (a * ((res * res) % MOD)) % MOD;
  } else
    return (res * res) % MOD;
}

long long binExp(long long a, long long b, long long mod) {
  if (b == 0)
    return 1;

  long long res = binExp(a, b / 2) % mod;
  if (b & 1) {
    return (a * ((res * res) % mod)) % mod;
  } else
    return (res * res) % mod;
}