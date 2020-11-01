#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 3;

    // bit をつくる 
    for (int bit = 0; bit < (1<<n); ++bit)
    {
        // 1bitずつ回す
        for (int i = 0; i < n; ++i)
        {
            // そのbitが1か? 
            if (bit & (1<<i))
            {
            }
        }
    }
}