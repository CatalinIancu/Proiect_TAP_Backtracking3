#include <iostream>
using namespace std;

/* In vectorul s imi voi stoca submultimile generate.
 * In variabila nrsol imi stochez numarul de solutii corecte generate.
*/
int s[101], n, nrsol;

/* Aici ma asigur ca :
 -> Nu exista o diferenta mai mare de 2 intre 2 termeni consecutivi.
 -> Ultimul termen, adica s[m] va fi de fiecare data egal cu n.
*/
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

/* Aici imi generez aranjamentele. Functia va fi recursiva si va primi 2 parametrii :
 * int k care reprezinta indicele solutiei anterioare
 * int m care reprezinta dimensiunea submultimii pe care vreau sa o generez
*/
void bkt(int k, int m)
{
    int v;
    for (v = s[k - 1] + 1; v <= n; v++) // Din moment ce vreau ca elementele submultimii sa fie strict crescatoare, voi porni de la v = s[k-1] + 1
    {
        {
            s[k] = v;
            if (solp(k, m)) // Aici are loc validarea solutiei partiale
            {
                if (k == m) // Aici imi dau seama daca solutia este completa sau partiala. Daca este partiala, voi chema din nou functia bkt(k,m) cu un k incrementat cu 1
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

    //Aici apelez functia bkt care va genera toate submultimile de dimensiune m (eliminand submultimile care nu indeplinesc cele 3 conditii din enunt)
    for (int m = 1; m <= n; m++)
    {
        bkt(1, m);
    }
    cout << endl;

    cout << "Numar solutii: ";
    cout << nrsol;
    cout << endl;
}