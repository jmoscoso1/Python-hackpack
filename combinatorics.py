# creates factorial and inverse factorial array up from 1-N
def init(n, MOD):
    fac, inv = [1] * (n + 1), [1] * (n + 1)
    for i in range(1, n + 1):
        fac[i] = (fac[i - 1] * i) % MOD
    inv[n] = pow(fac[n], MOD - 2, MOD)
    for i in range(n, 0, -1):
        inv[i - 1] = (inv[i] * i) % MOD
    # calculates nCr in O(1)
    def nCr(n, r):
        return fac[n] * inv[r] % MOD * inv[n - r] % MOD
    return nCr

