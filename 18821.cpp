#include <iostream>

using namespace std;

int main()
{
    int T, N, result;
    int i, j;
    cin >> T;

    for(i=0;i<T;i++)
    {
        cin>>N;
        result = N & 1;
        if(result)
        {
            cout<<'E'<<endl;
        }
        else
        {
            cout<<'O'<<endl;
        }
    }

    return 0;
}