#include <vector>
#include <iostream>
using namespace std;

int main()
{
vector<int> ivec;
cout << "ivec: size: " << ivec.size() << " capacity: "  << ivec.capacity() << endl;

for ( int ix = 0; ix < 50; ++ix ) 
{
ivec.push_back( ix );
cout << "ivec: size: " << ivec.size() << " capacity: "  << ivec.capacity() << " Vector starting address :" << &ivec[0] <<endl;
}    

return 0;
}
