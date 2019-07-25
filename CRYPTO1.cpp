#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long sec = sqrt(n);
    while((sec*sec)%4000000007!=n) ++sec;
    time_t time = sec;
    cout<<(asctime(gmtime(&time)));
}
