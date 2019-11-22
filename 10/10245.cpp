#include <bits/stdc++.h>
using namespace std;

struct Point_t {
    double x, y;
};

bool cmpx(Point_t a, Point_t b) {
    return a.x < b.x;
}

bool cmpy(Point_t a, Point_t b) {
    return a.y < b.y;
}

double sqr(double n) {
    return n*n;
}

double disPw2(Point_t a, Point_t b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

double bruteForce(vector<Point_t> p, int n) {
    double minDist = disPw2(p[0], p[1]);
    if(n == 2) return minDist;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n && sqr(p[j].x - p[i].x) < minDist; j++)
            minDist = min(minDist, disPw2(p[i], p[j]));
    return minDist;
}

double findClosestStrip(vector<Point_t> strip, double d) {
    int n = strip.size();
    double minDist = d;
    sort(strip.begin(), strip.end(), cmpy);
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n && sqr(strip[j].y - strip[i].y) < minDist; j++)
            minDist = min(minDist, disPw2(strip[i], strip[j]));
    return minDist;
}

double findClosest(vector<Point_t> pX, int n) {
    //base case
    if(n <= 3) return bruteForce(pX, n);

    int mid = n / 2;
    Point_t midPoint = *(pX.begin() + mid);

    vector<Point_t> pxL(pX.begin(), pX.begin()+mid);
    vector<Point_t> pxR(pX.begin()+mid, pX.end());
    double dL = findClosest(pxL, mid);
    double dR = findClosest(pxR, n-mid);
    
    double d = min(dL, dR);
    
    vector<Point_t> strip;
    for(int i = 0; i < n; i++)
        if (fabs(pX[i].x - midPoint.x) < d)
            strip.push_back(pX[i]);
    return findClosestStrip(strip, d);
}

int main () {
    vector<Point_t> pX;
    int n;
    scanf("%d", &n);
    while(n) {
        pX.clear();
        Point_t tmp;
        for(int i = 0; i < n; i++) {
            scanf("%lf %lf", &tmp.x, &tmp.y);
            pX.push_back(tmp);
        }
        if(n == 1) {
            printf("INFINITY\n");
            scanf("%d", &n);
            continue;
        }
        sort(pX.begin(), pX.end(), cmpx);
        double res = sqrt(findClosest(pX, n));
        if (res >= 10000.0) printf("INFINITY\n");
        else printf("%.4lf\n", res);
        scanf("%d", &n);
    }
    return 0;
}