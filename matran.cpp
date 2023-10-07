#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;
#define M_ROW 100 // Max row
#define M_COL 100 // Max column
void PrintArray(int m[M_ROW][M_COL], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << "\t" << m[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "n: ";
    cin >> n;
    int d[n];
    int m[M_ROW][M_COL];
    int g[M_ROW][M_COL];
    for (int i = 0; i < n; i++)
    {
        m[i][i] = 0;
        cout << "d" << i << ": ";
        cin >> d[i];
    }
    for (int s = 1; s < n - 1; s++)
    {
        cout << "Duong cheo s = " << s << endl;
        for (int i = 1; i < n - s; i++)
        {
            int j = i + s;
            m[i][j] = 100000000;
            cout << "m[" << i << "," << j << "]\t= min(m[" << i << ",k] + m[k+1," << j << "] + d0d1d2), voi " << i << "<=k<"
                 << j << endl;
            string s1 = "";
            string s2 = "";
            for (int k = i; k < j; k++)
            {
                if (k != i)
                {
                    s1 += "\t";
                    s2 += "\t";
                }

                s1 += "\tM[" + to_string(i) + "][" + to_string(k) + "] " + "+ M[" + to_string(k + 1) + "][" + to_string(j) + "] " + "+ d" + to_string(i - 1) + "d" + to_string(k) + "d" + to_string(j);
                s2 += "\t" + to_string(m[i][k]) + " + " + to_string(m[k + 1][j]) + " + " + to_string(d[i - 1] * d[k] * d[j]);
                int r = m[i][k] + m[k + 1][j] + d[i - 1] * d[k] * d[j];
                if (k != j - 1)
                {
                    s1 += ",\n";
                    s2 += ",\n";
                }

                if (r < m[i][j])
                {
                    m[i][j] = r;
                    g[i][j] = k;
                }
            }
            cout << "\t= min(" << s1 << ")" << endl;
            cout << "\t= min(" << s2 << ")" << endl;
            cout << "\t= " << m[i][j] << endl;
            cout << "g[" << i << "]"
                 << "[" << j << "] = k = " << g[i][j] << endl;
        }
    }
    cout << "Ma tran m:" << endl;
    PrintArray(m, n);
    cout << endl;
    cout << "Ma tran g:" << endl;
    PrintArray(g, n);
    cout << endl;
    return 0;
}