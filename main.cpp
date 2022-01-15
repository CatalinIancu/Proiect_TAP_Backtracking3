#include <iostream>
using namespace std;

int s[101], n, nrsol;

bool solp(int k, int m)
{
    if (s[k] - s[k - 1] > 2)
    {
        return false;
    }
    if (k == m && s[k] != n)
    {
        return false;
    }
    return true;
}

void bkt(int k, int m)
{
    int v;
    for (v = s[k - 1] + 1; v <= n; v++)
    {
        {
            s[k] = v;
            if (solp(k, m))
            {
                if (k == m)
                {
                    nrsol++;
                    for (int i = 1; i <= k; i++)
                        cout << s[i] << ", ";
                    cout << "\b\b " << endl;
                } else
                {
                    bkt(k + 1, m);
                }
            }

        }
    }
}

int main()
{
    cout << "Introduceti n: ";
    cin >> n;
    cout << endl;

    cout << "Problema va afisa treptele pe care le va urca cetateanul: ";
    cout << endl;

    for (int m = 2; m <= n; m++)
    {
        bkt(1, m);
    }
    cout << endl;

    cout << "Numar solutii: ";
    cout << nrsol;
    cout << endl;
}
