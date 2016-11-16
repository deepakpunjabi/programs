#include<iostream>
#include<map>
#define p(key) cout<<key<<endl;

using namespace std;

int main()
{
    map<char,int> map1= {{'a',1},{'b',2},{'c',3}};
    map<char,int> map2(next(map1.begin(),1),map1.end());
    map<char,int> map3(map2);
    map<char,int> map4(++map2.begin(),--map2.end());
//    int count=3;
//    while(count--)
//    {
//        p("this is map i");
//        for(auto i:map1)
//        {
//            cout<<i.first<<" : "<<i.second<<endl;
//        }
//    }

    p("this is map 1");
    for(auto i:map1)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }

    p("this is map 2");
    for(auto i:map2)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }

    p("this is map 3");
    for(auto i:map3)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }

    p("this is map 4");
    for(auto i:map4)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }
//    map1['a'].swap(map1['b']);
    swap(map1['a'],map1['b']);
    p(map1.at('a'));
    return 1;
}
