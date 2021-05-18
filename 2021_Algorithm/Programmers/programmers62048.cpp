using namespace std;

long long gcd(long long w, long long h) {
    if (h == 0) return w;
    else return gcd(h, w % h);
}

long long solution(int w, int h) {
    return (long long)w * h - (w + h - gcd(w, h));
}