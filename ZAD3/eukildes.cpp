#include <iostream>

using namespace std;

int euclidGcd(int m, int n) 
{
    while (m != n) 
    {
        if (m > n) 
            m = m - n; 
        else 
            n = n - m;
    }
    
    return m;
}

int euclidGcdmodulo(int m, int n) {
    if (m < n) {
        std::swap(m, n);
    }

    while (n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }

    return m;
}

int extendedeuclidGcd(int m, int n) {
    int x = 1;
    int y = 0;
    int r = 0;
    int s = 1;

    while (n != 0) {

        int c = m % n;
        int q = m / n;
        m = n;
        n = c;

        int r_temp = r;
        int s_temp = s;
        r = x - q * r;
        s = y - q * s;
        x = r_temp;
        y = s_temp;
    }
    return m; 
}


int main(int argc, char const *argv[])
{
    int a[4] = {174, 48, 60, 84};
    int b[4] = {18, 18, 24, 36};
    for(int i = 0; i < 4; ++i)
    {
        cout << "(" << a[i] << ", " << b[i] << ") = " << euclidGcd(a[i], b[i]) << endl;
        cout << "(" << a[i] << ", " << b[i] << ") = " << euclidGcdmodulo(a[i], b[i]) << endl;
        cout << "(" << a[i] << ", " << b[i] << ") = " << extendedeuclidGcd(a[i], b[i]) << endl;
    }
    system("pause");

    
    return 0;
}
