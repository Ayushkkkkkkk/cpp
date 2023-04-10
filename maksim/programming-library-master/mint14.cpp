template<int P>
struct Modular {
    using value_type = decltype(P);
    value_type value;

    Modular(ll k = 0) : value(norm(k)) {}

    Modular& operator += (const Modular& m)       { value += m.value; if (value >= P) value -= P; return *this; }
    Modular  operator +  (const Modular& m) const { Modular r = *this; return r += m; }

    Modular& operator -= (const Modular& m)       { value -= m.value; if (value <  0) value += P; return *this; }
    Modular  operator -  (const Modular& m) const { Modular r = *this; return r -= m; }
    Modular  operator -                     () const { return Modular(-value); }

    Modular& operator *= (const Modular &m)       { value = value * 1ll * m.value % P; return *this; }
    Modular  operator *  (const Modular& m) const { Modular r = *this; return r *= m; }

    Modular& operator /= (const Modular &m)       { return *this *= m.inv(); }
    Modular  operator /  (const Modular& m) const { Modular r = *this; return r /= m; }

    Modular& operator ++                    ()       { return *this += 1; }
    Modular& operator --                    ()       { return *this -= 1; }
    Modular  operator ++                 (int)       { Modular r = *this; *this += 1; return r; }
    Modular  operator --                 (int)       { Modular r = *this; *this -= 1; return r; }

    bool        operator == (const Modular& m) const { return value == m.value; }
    bool        operator != (const Modular& m) const { return value != m.value; }

    value_type norm(ll k) {
        if (!(-P <= k && k < P)) k %= P;
        if (k < 0) k += P;
        return k;
    }

    Modular inv() const {
        value_type a = value, b = P, x = 0, y = 1;
        while (a != 0) { value_type k = b / a; b -= k * a; x -= k * y; swap(a, b); swap(x, y); }
        return Modular<P>(x);
    }
};

template<int P> Modular<P> pow(Modular<P> m, ll p) {
    Modular<P> r(1);
    while (p) {
        if (p & 1) r *= m;
        m *= m;
        p >>= 1;
    }
    return r;
}

template<int P> ostream& operator << (ostream& o, const Modular<P> &m) { return o << m.value; }
template<int P> istream& operator >> (istream& i,       Modular<P> &m) { ll k; i >> k; m.value = m.norm(k); return i; }
template<int P> string   to_string(const Modular<P>& m) { return to_string(m.value); }

using Mint = Modular<1000000007>;
// using Mint = Modular<998244353>;
// using Mint = long double;
