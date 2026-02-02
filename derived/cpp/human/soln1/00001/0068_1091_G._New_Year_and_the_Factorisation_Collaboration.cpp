#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  return b == 0 ? a : gcd(b, a % b);
}
const int BIGINTBITS = 32;
const unsigned int BIGINTMASK = (1LL << BIGINTBITS) - 1;
struct BigInt {
  vector<unsigned int> d;
  BigInt() {}
  BigInt(unsigned long long x) {
    while (x != 0) d.push_back(x & BIGINTMASK), x >>= BIGINTBITS;
  }
  unsigned long long val() const {
    unsigned long long ret = 0;
    for (int i = ((int)(d).size()) - 1; i >= 0; --i)
      ret = (ret << BIGINTBITS) | d[i];
    return ret;
  }
};
void normalize(BigInt &a) {
  while (((int)(a.d).size()) > 0 && a.d[((int)(a.d).size()) - 1] == 0)
    a.d.pop_back();
}
int cmp(const BigInt &a, const BigInt &b) {
  if (((int)(a.d).size()) != ((int)(b.d).size()))
    return ((int)(a.d).size()) < ((int)(b.d).size()) ? -1 : +1;
  for (int i = ((int)(a.d).size()) - 1; i >= 0; --i)
    if (a.d[i] != b.d[i]) return a.d[i] < b.d[i] ? -1 : +1;
  return 0;
}
bool operator<(const BigInt &a, const BigInt &b) { return cmp(a, b) < 0; }
bool operator<=(const BigInt &a, const BigInt &b) { return cmp(a, b) <= 0; }
bool operator==(const BigInt &a, const BigInt &b) { return cmp(a, b) == 0; }
BigInt &operator+=(BigInt &a, const BigInt &b) {
  unsigned long long carry = 0;
  for (int i = 0; i < ((int)(b.d).size()) || carry != 0; ++i) {
    if (i < ((int)(a.d).size()))
      carry += a.d[i];
    else
      a.d.push_back(0);
    if (i < ((int)(b.d).size())) carry += b.d[i];
    a.d[i] = carry & BIGINTMASK;
    carry >>= BIGINTBITS;
  }
  return a;
}
BigInt operator+(const BigInt &a, const BigInt &b) {
  BigInt ret = a;
  ret += b;
  return ret;
}
BigInt &operator-=(BigInt &a, const BigInt &b) {
  unsigned long long carry = 0;
  for (int i = 0; i < ((int)(b.d).size()) || carry != 0; ++i) {
    if (i < ((int)(b.d).size())) carry += b.d[i];
    assert(i < ((int)(a.d).size()));
    if (carry <= a.d[i])
      a.d[i] -= carry, carry = 0;
    else
      a.d[i] += (1LL << BIGINTBITS) - carry, carry = 1;
  }
  normalize(a);
  return a;
}
BigInt operator-(const BigInt &a, const BigInt &b) {
  BigInt ret = a;
  ret -= b;
  return ret;
}
BigInt operator*(const BigInt &a, const BigInt &b) {
  BigInt ret;
  for (int j = 0; j < ((int)(b.d).size()); ++j) {
    unsigned long long carry = 0;
    for (int i = 0; i < ((int)(a.d).size()) || carry != 0; ++i) {
      if (i < ((int)(a.d).size())) carry += (unsigned long long)a.d[i] * b.d[j];
      if (i + j < ((int)(ret.d).size()))
        carry += ret.d[i + j];
      else
        ret.d.push_back(0);
      ret.d[i + j] = carry & BIGINTMASK;
      carry >>= BIGINTBITS;
    }
  }
  return ret;
}
BigInt operator*(const BigInt &a, const unsigned int &b) {
  assert(0 <= b && b <= BIGINTMASK);
  unsigned long long carry = 0;
  BigInt ret;
  if (b == 0) return ret;
  for (int i = 0; i < ((int)(a.d).size()) || carry != 0; ++i) {
    if (i < ((int)(a.d).size())) carry += (unsigned long long)a.d[i] * b;
    if (i < ((int)(ret.d).size()))
      carry += ret.d[i];
    else
      ret.d.push_back(0);
    ret.d[i] = carry & BIGINTMASK;
    carry >>= BIGINTBITS;
  }
  return ret;
}
BigInt operator<<(const BigInt &a, const int &shift) {
  assert(shift < BIGINTBITS);
  BigInt ret;
  unsigned long long carry = 0;
  for (int i = 0; i < ((int)(a.d).size()) || carry != 0; ++i) {
    if (i < ((int)(a.d).size())) carry |= ((unsigned long long)a.d[i]) << shift;
    ret.d.push_back(carry & BIGINTMASK);
    carry >>= BIGINTBITS;
  }
  return ret;
}
BigInt operator>>(const BigInt &a, const int &shift) {
  assert(shift < BIGINTBITS);
  BigInt ret;
  unsigned long long carry = 0;
  for (int i = 0; i < ((int)(a.d).size()) || carry != 0; ++i) {
    if (i < ((int)(a.d).size()))
      carry |= ((unsigned long long)a.d[i]) << (BIGINTBITS - shift);
    if (i != 0) ret.d.push_back(carry & BIGINTMASK);
    carry >>= BIGINTBITS;
  }
  return ret;
}
void dividewithremainder(const BigInt &a, const unsigned int &b, BigInt &q,
                         unsigned int &r) {
  assert(1 <= b && b <= BIGINTMASK);
  q.d.resize(((int)(a.d).size()));
  unsigned long long carry = 0;
  for (int i = ((int)(a.d).size()) - 1; i >= 0; --i) {
    carry <<= BIGINTBITS;
    carry += a.d[i];
    q.d[i] = carry / b;
    carry -= (unsigned long long)q.d[i] * b;
  }
  normalize(q);
  r = carry;
}
BigInt operator/(const BigInt &a, const unsigned int &b) {
  BigInt q;
  unsigned int r;
  dividewithremainder(a, b, q, r);
  return q;
}
unsigned int operator%(const BigInt &a, const unsigned int &b) {
  BigInt q;
  unsigned int r;
  dividewithremainder(a, b, q, r);
  return r;
}
void dividewithremainder(const BigInt &a, const BigInt &b, BigInt &q,
                         BigInt &r) {
  if (a < b) {
    q.d.clear();
    r = a;
    return;
  }
  if (((int)(b.d).size()) == 1) {
    unsigned int rr;
    dividewithremainder(a, b.d[0], q, rr);
    r = BigInt(rr);
    return;
  }
  int shift = 0;
  while (((b.d[((int)(b.d).size()) - 1] >> (BIGINTBITS - shift - 1)) & 1) == 0)
    ++shift;
  BigInt u = a << shift, v = b << shift;
  q.d.resize(((int)(u.d).size()) - ((int)(v.d).size()) + 1);
  r.d.resize(((int)(v.d).size()));
  for (int i = 0; i < ((int)(v.d).size()); ++i)
    r.d[((int)(v.d).size()) - i - 1] = u.d[((int)(u.d).size()) - i - 1];
  for (int i = ((int)(q.d).size()) - 1; i >= 0; --i) {
    unsigned long long num1 = ((int)(v.d).size()) < ((int)(r.d).size())
                                  ? r.d[((int)(v.d).size())]
                                  : 0,
                       num2 = ((int)(v.d).size()) - 1 < ((int)(r.d).size())
                                  ? r.d[((int)(v.d).size()) - 1]
                                  : 0;
    unsigned long long num = (num1 << BIGINTBITS) | num2;
    unsigned int den = v.d[((int)(v.d).size()) - 1];
    unsigned int guess = min(num / den, (unsigned long long)BIGINTMASK);
    while (r < v * guess) --guess;
    q.d[i] = guess;
    r -= v * guess;
    if (i != 0) r.d.insert(r.d.begin(), u.d[i - 1]);
  }
  normalize(q);
  r = r >> shift;
}
BigInt operator/(const BigInt &a, const BigInt &b) {
  BigInt q, r;
  dividewithremainder(a, b, q, r);
  return q;
}
BigInt operator%(const BigInt &a, const BigInt &b) {
  BigInt q, r;
  dividewithremainder(a, b, q, r);
  return r;
}
BigInt _parse(const string &s, int offset, int k, const vector<BigInt> &xs) {
  if (k == 0)
    return BigInt(0 <= offset && offset < ((int)(s).size()) ? s[offset] - '0'
                                                            : 0);
  return _parse(s, offset, k - 1, xs) * xs[k] +
         _parse(s, offset + (1 << (k - 1)), k - 1, xs);
}
BigInt parse(const string &s) {
  int k = 0;
  while ((1 << k) < ((int)(s).size())) ++k;
  vector<BigInt> xs;
  xs.push_back(BigInt(1));
  xs.push_back(BigInt(10));
  while (k >= ((int)(xs).size())) xs.push_back(xs.back() * xs.back());
  return _parse(s, ((int)(s).size()) - (1 << k), k, xs);
}
template <typename T>
constexpr T constsqr(T a) {
  return a * a;
}
template <typename T>
constexpr T constpower(T a, std::size_t n) {
  return n == 0 ? 1 : constsqr(constpower(a, n / 2)) * (n % 2 == 0 ? 1 : a);
}
const int BIGDECIMALDIGITS = 9;
const int BIGDECIMALBASE = constpower(10, BIGDECIMALDIGITS);
struct BigDecimal {
  vector<int> d;
  BigDecimal() {}
  BigDecimal(unsigned long long x) {
    while (x > 0) d.push_back(x % BIGDECIMALBASE), x /= BIGDECIMALBASE;
  }
};
BigDecimal &operator+=(BigDecimal &a, const BigDecimal &b) {
  long long carry = 0;
  for (int i = 0; i < ((int)(b.d).size()) || carry != 0; ++i) {
    if (i < ((int)(a.d).size()))
      carry += a.d[i];
    else
      a.d.push_back(0);
    if (i < ((int)(b.d).size())) carry += b.d[i];
    a.d[i] = carry % BIGDECIMALBASE;
    carry /= BIGDECIMALBASE;
  }
  return a;
}
BigDecimal operator+(const BigDecimal &a, const BigDecimal &b) {
  BigDecimal ret = a;
  ret += b;
  return ret;
}
BigDecimal operator*(const BigDecimal &a, const BigDecimal &b) {
  BigDecimal ret;
  for (int j = 0; j < ((int)(b.d).size()); ++j) {
    long long carry = 0;
    for (int i = 0; i < ((int)(a.d).size()) || carry != 0; ++i) {
      if (i < ((int)(a.d).size())) carry += (long long)a.d[i] * b.d[j];
      if (i + j < ((int)(ret.d).size()))
        carry += ret.d[i + j];
      else
        ret.d.push_back(0);
      ret.d[i + j] = carry % BIGDECIMALBASE;
      carry /= BIGDECIMALBASE;
    }
  }
  return ret;
}
BigDecimal _format(const BigInt &a, int offset, int k,
                   const vector<BigDecimal> &xs) {
  if (k == 0)
    return BigDecimal(0 <= offset && offset < ((int)(a.d).size()) ? a.d[offset]
                                                                  : 0);
  return _format(a, offset, k - 1, xs) * xs[k] +
         _format(a, offset - (1 << (k - 1)), k - 1, xs);
}
string format(const BigInt &a) {
  int k = 0;
  while ((1 << k) < ((int)(a.d).size())) ++k;
  vector<BigDecimal> xs;
  xs.push_back(BigDecimal(1));
  xs.push_back(BigDecimal(1LL << BIGINTBITS));
  while (k >= ((int)(xs).size())) xs.push_back(xs.back() * xs.back());
  BigDecimal ans = _format(a, (1 << k) - 1, k, xs);
  if (((int)(ans.d).size()) == 0) return "0";
  string ret(((int)(ans.d).size()) * BIGDECIMALDIGITS, '?');
  for (int i = (0); i < (((int)(ans.d).size())); ++i)
    sprintf(&ret[0] + i * BIGDECIMALDIGITS, "%0*d", BIGDECIMALDIGITS,
            ans.d[((int)(ans.d).size()) - i - 1]);
  int nzero = 0;
  while (nzero < ((int)(ret).size()) && ret[nzero] == '0') ++nzero;
  ret = ret.substr(nzero);
  return ret;
}
BigInt gcd(const BigInt &a, const BigInt &b) {
  return ((int)(b.d).size()) == 0 ? a : gcd(b, a % b);
}
void extractleadingbits(const BigInt &p, const BigInt &q, unsigned long long &x,
                        unsigned long long &y) {
  x = (((unsigned long long)p.d[((int)(p.d).size()) - 1]) << BIGINTBITS) |
      p.d[((int)(p.d).size()) - 2];
  y = (((unsigned long long)(((int)(q.d).size()) == ((int)(p.d).size())
                                 ? q.d[((int)(p.d).size()) - 1]
                                 : 0))
       << BIGINTBITS) |
      q.d[((int)(p.d).size()) - 2];
  if (((int)(p.d).size()) == 2) return;
  int shift = 0;
  while (((x >> (2 * BIGINTBITS - shift - 1)) & 1) == 0) ++shift;
  if (shift == 0) return;
  x = (x << shift) | (p.d[((int)(p.d).size()) - 3] >> (BIGINTBITS - shift)),
  y = (y << shift) | (q.d[((int)(p.d).size()) - 3] >> (BIGINTBITS - shift));
}
BigInt lehmergcd(BigInt p, BigInt q) {
  int cmpres = cmp(p, q);
  if (cmpres == 0) return p;
  if (cmpres < 0) swap(p, q);
  unsigned long long x, y, z, num1, den1, w1, num2, den2, w2, e, f, xn, yn, t;
  unsigned int a, b, c, d, w;
  bool needlongdiv;
  int parity;
  int nlong = 0, nlehmer = 0, clehmer, nit = 0;
  while (true) {
    if (((int)(q.d).size()) == 0)
      return p;
    else if (((int)(p.d).size()) <= 2)
      break;
    else
      needlongdiv = false;
    if (((int)(p.d).size()) - ((int)(q.d).size()) >= 2) needlongdiv = true;
    if (!needlongdiv) {
      extractleadingbits(p, q, x, y);
      if (y <= BIGINTMASK || x == y) needlongdiv = true;
      if (x == ((((unsigned long long)BIGINTMASK) << BIGINTBITS) | BIGINTMASK))
        x >>= 1, y >>= 1;
    }
    if (!needlongdiv) {
      num1 = x, den1 = y + 1, num2 = x + 1, den2 = y, w1 = num1 / den1,
      w2 = num2 / den2;
      if (w1 != w2 || w1 > BIGINTMASK)
        needlongdiv = true;
      else
        w = w1;
    }
    if (!needlongdiv) {
      a = 0, b = 1, c = 1, d = w, z = x - w * y, x = y, y = z, parity = 0,
      clehmer = 1;
      while (true) {
        if (parity == 0) {
          if (y == d) break;
          num1 = x - a, den1 = y + c, num2 = x + b, den2 = y - d;
        }
        if (parity == 1) {
          if (y == c) break;
          num1 = x - b, den1 = y + d, num2 = x + a, den2 = y - c;
        }
        w1 = num1 / den1, w2 = num2 / den2;
        if (w1 != w2 || w1 > BIGINTMASK)
          break;
        else
          w = w1;
        e = a + w * c, f = b + w * d, z = x - w * y;
        if (e > BIGINTMASK || f > BIGINTMASK)
          break;
        else
          a = c, c = e, b = d, d = f, x = y, y = z, parity = 1 - parity,
          ++clehmer;
      }
    }
    if (!needlongdiv && b != 0) {
      x = 0, y = 0, xn = 0, yn = 0, nlehmer += clehmer, ++nit;
      while (((int)(q.d).size()) < ((int)(p.d).size())) q.d.push_back(0);
      for (int i = 0; i < ((int)(p.d).size()); ++i) {
        unsigned long long cp = p.d[i], cq = q.d[i];
        if (parity == 0)
          x += cq * b, xn += cp * a, y += cp * c, yn += cq * d;
        else
          x += cp * a, xn += cq * b, y += cq * d, yn += cp * c;
        t = min(x, xn), x -= t, xn -= t, t = min(y, yn), y -= t, yn -= t;
        if (xn == 0)
          p.d[i] = x & BIGINTMASK, x >>= BIGINTBITS;
        else if ((xn & BIGINTMASK) == 0)
          p.d[i] = 0, xn >>= BIGINTBITS;
        else
          p.d[i] = BIGINTMASK - (xn & BIGINTMASK) + 1, xn >>= BIGINTBITS, ++xn;
        if (yn == 0)
          q.d[i] = y & BIGINTMASK, y >>= BIGINTBITS;
        else if ((yn & BIGINTMASK) == 0)
          q.d[i] = 0, yn >>= BIGINTBITS;
        else
          q.d[i] = BIGINTMASK - (yn & BIGINTMASK) + 1, yn >>= BIGINTBITS, ++yn;
      }
      assert(x == 0 && y == 0 && xn == 0 && yn == 0);
      normalize(p);
      normalize(q);
    } else {
      BigInt r = p % q;
      p = q, q = r;
      ++nlong, ++nit;
    }
  }
  x = (((unsigned long long)(((int)(p.d).size()) == 2 ? p.d[1] : 0))
       << BIGINTBITS) |
      p.d[0];
  y = (((unsigned long long)(((int)(q.d).size()) == 2 ? q.d[1] : 0))
       << BIGINTBITS) |
      q.d[0];
  while (y != 0) {
    z = x % y, x = y, y = z;
  }
  return BigInt(x);
}
int bitcnt(const BigInt &x) {
  if (((int)(x.d).size()) == 0) return 0;
  int r = 0;
  while (x.d[((int)(x.d).size()) - 1] >= (1ULL << r)) ++r;
  return (((int)(x.d).size()) - 1) * BIGINTBITS + r;
}
BigInt randbits(int nbits, mt19937 &rnd) {
  BigInt ret;
  int ndigs = (nbits + BIGINTBITS - 1) / BIGINTBITS;
  for (int i = (0); i < (ndigs - 1); ++i) ret.d.push_back(rnd());
  ret.d.push_back(rnd() % (1ULL << (nbits - (ndigs - 1) * BIGINTBITS)));
  normalize(ret);
  return ret;
}
BigInt pw(BigInt x, BigInt n, BigInt mod) {
  BigInt ret(1);
  for (int i = (0); i < (((int)(n.d).size()) * BIGINTBITS); ++i) {
    if ((n.d[i / BIGINTBITS] & (1ULL << (i % BIGINTBITS))) != 0)
      ret = ret * x % mod;
    x = x * x % mod;
  }
  return ret;
}
bool isprobableprime(const BigInt &n, mt19937 &rnd) {
  if (((int)(n.d).size()) == 1 && (n.d[0] == 2 || n.d[0] == 3)) return true;
  if (((int)(n.d).size()) == 0 || ((int)(n.d).size()) == 1 && n.d[0] == 1 ||
      (n.d[0] & 1) == 0)
    return false;
  BigInt d = n - 1;
  int r = 0;
  while (d.d[0] == 0) r += BIGINTBITS, d.d.erase(d.d.begin());
  int rr = 0;
  while ((d.d[0] & (1 << rr)) == 0) ++rr;
  r += rr;
  d = d >> rr;
  BigInt alo = 2, ahi = n - 2;
  int ahibits = bitcnt(ahi);
  BigInt xlo = 1, xhi = n - 1;
  for (int k = (0); k < (40); ++k) {
    BigInt a;
    while (true) {
      a = randbits(ahibits, rnd);
      if (alo <= a && a <= ahi) break;
    }
    BigInt x = pw(a, d, n);
    if (x == xlo || x == xhi) continue;
    bool ok = false;
    for (int i = (0); i < (r - 1); ++i) {
      x = x * x % n;
      if (x == xhi) {
        ok = true;
        break;
      }
    }
    if (ok) continue;
    return false;
  }
  return true;
}
bool local = false;
vector<BigInt> ploc;
BigInt nloc;
mt19937 locrnd;
BigInt egcd(BigInt a, BigInt b, BigInt &x, bool &xneg, BigInt &y, bool &yneg) {
  if (b == 0) {
    x = 1, xneg = false, y = 0, yneg = false;
    return a;
  }
  BigInt g = egcd(b, a % b, y, yneg, x, xneg);
  BigInt z = x * (a / b);
  if (xneg != yneg)
    y += z;
  else if (z <= y)
    y -= z;
  else
    y = z - y, yneg = !yneg;
  return g;
}
pair<BigInt, BigInt> invcrt(BigInt a1, BigInt mod1, BigInt a2, BigInt mod2) {
  if (a2 < a1) swap(a1, a2), swap(mod1, mod2);
  bool c1neg, c2neg;
  BigInt c1, c2, g = egcd(mod1, mod2, c1, c1neg, c2, c2neg);
  assert((a2 - a1) % g == 0);
  BigInt t = (a2 - a1) / g, lcm = mod1 / g * mod2;
  if (c1neg) c1 = mod2 - c1;
  BigInt x = (a1 + c1 * t % (mod2 / g) * mod1) % lcm;
  return make_pair(x, lcm);
}
pair<BigInt, BigInt> invcrt(vector<BigInt> a, vector<BigInt> mod) {
  pair<BigInt, BigInt> ret = make_pair(a[0], mod[0]);
  for (int i = (1); i < (((int)(a).size())); ++i)
    ret = invcrt(ret.first, ret.second, a[i], mod[i]);
  return ret;
}
BigInt query(BigInt x) {
  if (!local) {
    printf("sqrt %s\n", format(x).c_str());
    fflush(stdout);
    string s;
    cin >> s;
    assert(s != "-1");
    return parse(s);
  } else {
    vector<BigInt> a;
    for (int i = (0); i < (((int)(ploc).size())); ++i) {
      BigInt cx = x % ploc[i];
      BigInt cy = pw(cx, (ploc[i] + 1) / 4, ploc[i]);
      if (locrnd() % 2 == 1) cy = ploc[i] - cy;
      BigInt A = cy * cy % ploc[i], B = cx;
      assert(cy * cy % ploc[i] == cx);
      a.push_back(cy);
    }
    BigInt ret = invcrt(a, ploc).first;
    assert(ret * ret % nloc == x);
    return ret;
  }
}
vector<BigInt> ans;
void solve(const string &s) {
  std::mt19937 rnd(
      (int)std::chrono::steady_clock::now().time_since_epoch().count());
  BigInt n = parse(s);
  ans.clear();
  ans.push_back(n);
  while (true) {
    BigInt x;
    while (true) {
      x.d.clear();
      for (int i = (0); i < (((int)(n.d).size()) - 1); ++i)
        x.d.push_back(rnd());
      int mxbit = 0;
      while (n.d[((int)(n.d).size()) - 1] >= (2ULL << mxbit)) ++mxbit;
      x.d.push_back(rnd() % (2ULL << mxbit));
      normalize(x);
      if (x < n) break;
    }
    BigInt y = x * x % n;
    BigInt z = query(y);
    if (z == x || z == n - x) continue;
    BigInt d = (x + z) % n;
    vector<BigInt> nans;
    for (int i = (0); i < (((int)(ans).size())); ++i) {
      BigInt g = lehmergcd(ans[i], d);
      if (g == 1 || g == ans[i])
        nans.push_back(ans[i]);
      else
        nans.push_back(g), nans.push_back(ans[i] / g);
    }
    bool change = ((int)(nans).size()) != ((int)(ans).size());
    ans = nans;
    if (change) {
      bool allprime = true;
      for (int i = (0); i < (((int)(ans).size())); ++i)
        if (!isprobableprime(ans[i], rnd)) {
          allprime = false;
          break;
        }
      if (allprime) break;
    }
  }
  sort(ans.begin(), ans.end());
}
void run() {
  string s;
  cin >> s;
  solve(s);
  printf("! %d", ((int)(ans).size()));
  for (int i = (0); i < (((int)(ans).size())); ++i)
    printf(" %s", format(ans[i]).c_str());
  fflush(stdout);
}
void stressdivsmall() {
  printf("\nstressdivsmall\n");
  for (int rep = (0); rep < (1000000); ++rep) {
    int ydig = rand() % 32 + 1;
    unsigned long long y = 0;
    for (int i = (0); i < (ydig); ++i) y = (y << 1) + rand() % 2;
    if (y == 0) continue;
    int xdig = rand() % (2 * ydig) + 1;
    unsigned long long x = 0;
    for (int i = (0); i < (xdig); ++i) x = (x << 1) + rand() % 2;
    BigInt a(x), b(y), c = a / b;
    unsigned long long have = c.val(), want = x / y;
    if (have == want) {
      if (rep % 1000 == 999) printf(".");
      continue;
    }
    printf("rep%d: %llu/%llu -> have=%llu want=%llu\n", rep, x, y, have, want);
    break;
  }
}
void stressdivlarge() {
  printf("\nstressdivlarge\n");
  for (int rep = (0); rep < (1000); ++rep) {
    BigInt a;
    a.d.resize((1000 + BIGINTBITS - 1) / BIGINTBITS);
    for (int i = (0); i < (((int)(a.d).size())); ++i)
      for (int j = (0); j < (BIGINTBITS); ++j) a.d[i] |= (rand() % 2) << j;
    normalize(a);
    BigInt b;
    b.d.resize((((int)(a.d).size()) + 1) / 2);
    for (int i = (0); i < (((int)(b.d).size())); ++i)
      for (int j = (0); j < (BIGINTBITS); ++j) b.d[i] |= (rand() % 2) << j;
    normalize(b);
    if (((int)(b.d).size()) == 0) continue;
    BigInt c = a / b;
    BigInt d = a - b * c;
    if (d < b) {
      printf(".");
      continue;
    }
    printf("err\n");
  }
}
void stressparse() {
  printf("\nverifying small\n");
  for (int rep = (0); rep < (100); ++rep) {
    int len = rand() % 18 + 1;
    string s(len, '?');
    for (int i = (0); i < (len); ++i) s[i] = '0' + rand() % 10;
    while (((int)(s).size()) > 1 && s[0] == '0') s = s.substr(1);
    BigInt a = parse(s);
    unsigned long long havenum = a.val(), wantnum;
    sscanf(s.c_str(), "%llu", &wantnum);
    if (havenum != wantnum) {
      printf("err %s => havenum=%llu wantnum=%llu\n", s.c_str(), havenum,
             wantnum);
      return;
    }
    string havestr = format(a), wantstr = s;
    if (havestr != wantstr) {
      printf("err %s => havestr=%s wantstr=%s\n", s.c_str(), havestr.c_str(),
             wantstr.c_str());
      return;
    }
    printf(".");
  }
  printf("\ntesting large\n");
  for (int rep = (0); rep < (100); ++rep) {
    int len = 10000;
    string s(len, '?');
    for (int i = (0); i < (len); ++i) s[i] = '0' + rand() % 10;
    while (((int)(s).size()) > 1 && s[0] == '0') s = s.substr(1);
    BigInt a = parse(s);
    string have = format(a);
    if (have == s) {
      printf(".");
      continue;
    }
    printf("err\n");
    break;
  }
}
void stressgcd() {
  printf("\nstressgcdsmall\n");
  printf("\nstressgcdlarge lehmer\n");
  for (int rep = (0); rep < (100000); ++rep) {
    BigInt a;
    a.d = vector<unsigned int>(300, 0);
    for (int i = (0); i < (((int)(a.d).size())); ++i)
      for (int j = (0); j < (BIGINTBITS); ++j) a.d[i] |= (rand() % 2) << j;
    normalize(a);
    BigInt b;
    b.d = vector<unsigned int>(300, 0);
    for (int i = (0); i < (((int)(b.d).size())); ++i)
      for (int j = (0); j < (BIGINTBITS); ++j) b.d[i] |= (rand() % 2) << j;
    normalize(b);
    BigInt c = lehmergcd(a, b);
    BigInt d = gcd(a, b);
    if (format(c) != format(d)) {
      printf("err\n");
    }
    if (rep % 1000 == 999) printf(".");
  }
}
void stressmillerrabin() {
  std::mt19937 rnd(123);
  for (int rep = (0); rep < (1000); ++rep) {
    BigInt n = rnd() % 1000;
    int nbits = rnd() % 200;
    for (int i = (0); i < (nbits); ++i) n = n << 1;
    n = n + 1;
    if (isprobableprime(n, rnd)) printf("%s is prime\n", format(n).c_str());
  }
}
void stress() {
  local = true;
  int targetbits = 1024;
  locrnd = mt19937(21312);
  for (int rep = (0); rep < (1000); ++rep) {
    nloc = BigInt(1);
    ploc.clear();
    int nprime = locrnd() % (10 - 2 + 1) + 2;
    for (int i = (0); i < (nprime); ++i) {
      int mxpbits = targetbits / (i + 1);
      BigInt p;
      while (true) {
        BigInt x = randbits(locrnd() % (mxpbits - 2) + 1, locrnd);
        p = 4 * x + 3;
        bool have = false;
        for (int j = (0); j < (((int)(ploc).size())); ++j)
          if (ploc[j] == p) have = true;
        if (have) continue;
        if (isprobableprime(p, locrnd)) break;
      }
      nloc = nloc * p;
      ploc.push_back(p);
    }
    sort(ploc.begin(), ploc.end());
    printf("n=%s\n", format(nloc).c_str());
    solve(format(nloc));
    assert(ploc == ans);
  }
}
int main() {
  run();
  return 0;
}