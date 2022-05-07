#include <iostream>
#include <algorithm>

using namespace std;

class Mang
{
    int a[100];
    int n;

public:
    void input();
    void display();
    int getsize();
    int LayPhanTu(int k);
    void GanGiaTri(int k, int b);
    bool TimPhanTu(int x);
    void SapXepTang();
    void SapXepGiam();
    void ganMang(Mang p);
};

int main()
{
    int x, n;
    cin >> x;
    Mang m, p;
    m.input();
    n = m.getsize();
    cout << n << endl;
    if (m.TimPhanTu(x))
    {
        cout << "TRUE" << endl;
    }
    else
        cout << "FALSE" << endl;

    p.ganMang(m);
    p.SapXepTang();
    p.display();
    m.GanGiaTri(0, m.LayPhanTu(0) + 1);
    m.SapXepGiam();
    m.display();
    return 0;
}

void Mang::input()
{
    n = 0;
    while (cin >> a[n])
    {
        n++;
    }
}
void Mang::display()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i < n - 1)
        {
            cout << " ";
        }
        else
        {
            cout << endl;
        }
    }
}
int Mang::getsize()
{
    return n;
}
int Mang::LayPhanTu(int k)
{
    return a[k];
}
void Mang::GanGiaTri(int k, int b)
{
    a[k] = b;
}
bool Mang::TimPhanTu(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return true;
        }
    }
    return false;
}
void Mang::SapXepTang()
{
    for (int i = 0; i < n - 1; i++)
    {
       for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

void Mang::SapXepGiam()
{
    for (int i = 0; i < n - 1; i++)
    {
        /* code */ for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
void Mang::ganMang(Mang p)
{
    n = p.n;
    for (int i = 0; i < n; i++)
    {
        a[i] = p.a[i];
    }
}   