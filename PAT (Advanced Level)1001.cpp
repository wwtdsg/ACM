#include <iostream>
#include <complex>
#include <iomanip>

using namespace std;

int main()
{
  int a, b, y, sum;
  cin>>a>>b;
  sum = a + b;
  if (abs(sum) > 999999)
  {
    cout<<sum/1000000<<',';
    sum = abs(sum) % 1000000;
    cout<<setfill('0')<<setw(3)<<sum/1000<<','<<setfill('0')<<setw(3)<<sum%1000<<endl;
  }
  else if (abs(sum) > 999)
  {
    cout<<sum/1000;
    sum = abs(sum);
    cout<<','<<setfill('0')<<setw(3)<<sum%1000<<endl;
  }
  else
  {
    cout<<sum<<endl;
  }
}
