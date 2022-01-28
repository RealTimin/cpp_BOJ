#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    double A, B;
    cin >> A >> B;
    if (A == B)
        cout << "==";
    else if (A > B)
        cout << ">";
    else
        cout << "<";
    return 0;
}