#include <iostream>

using namespace std;

/*
 -> In vectorul s imi voi stoca submultimile generate.
 -> In variabila nrsol imi stochez numarul de solutii corecte generate.
*/
int s[101], n, nrsol;

/*
 Aici ma asigur ca :
 -> Nu exista o diferenta mai mare de 2 intre 2 termeni consecutivi.
 -> Ultimul termen, adica s[m] va fi de fiecare data egal cu n.
*/
bool SolutiePartiala(int k, int m)
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

void Afisare(int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << s[i] << ", ";
    }
    cout << "\b\b " << endl;
}

/*
 Aici imi generez aranjamentele. Functia va fi recursiva si va primi 2 parametrii :
 -> int k care reprezinta indicele solutiei anterioare
 -> int m care reprezinta dimensiunea submultimii pe care vreau sa o generez
*/
void Backtracking(int k, int m)
{
    int v;
/*
 -> Voi porni de la v = s[k-1] pentru a ma asigura ca elementele generate sunt crescatoare.
 -> De asemenea imi voi reduce din timpul de executie pornind generarea noului element de la valoarea elementului anterior + 1
*/
    for (v = s[k - 1] + 1; v <= n; v++)
    {
        {
            s[k] = v;
            if (SolutiePartiala(k, m)) // Validez daca solutia partiala este valida
            {
                if (k == m) // Validez daca solutia este finala
                {
                    nrsol++; // Incrementez counterul de solutii (cerinta problemei)
                    Afisare(k); // Afisez solutia finala
                } else
                {
                    Backtracking(k + 1, m);
                }
            }
        }
    }
}

//Aici apelez functia Backtracking care va genera toate submultimile de dimensiune m
void Rezolvare(int n)
{
    for (int m = 1; m <= n; m++)
    {
        Backtracking(1, m);
    }
    cout << endl;
}

int main()
{
    cout << "Introduceti n: ";
    cin >> n;
    cout << endl;

    cout << "Cetateanul turmentat are urmatoarele optiuni: ";
    cout << endl;

    Rezolvare(n);

    cout << "Numar solutii: ";
    cout << nrsol;
    cout << endl;
}