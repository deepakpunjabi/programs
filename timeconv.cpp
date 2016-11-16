#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
    string time;
    cin >> time;
    string meridian=time.substr(time.size()-2);
    //cout<< time<<endl;
    string hh=time.substr(0,2);
    const char *hh1=hh.c_str();
    int hour = atoi(hh1);
    //cout << hour<<"\n";
    string mm=time.substr(3,2);
    string ss=time.substr(6,2);
    //cout << hh<<endl<<mm <<endl<<ss;
    //cout << meridian;
    if(meridian.compare("AM")==0){
        if(hour==12){
        cout<<"00"<<":"<<mm<<":"<<ss;
        }
        else{
        cout<<hh<<":"<<mm<<":"<<ss;
        }

    }
    else{
        if(hour==12){
            cout<<"12"<<":"<<mm<<":"<<ss;
        }
        else{
        cout<<hour+12<<":"<<mm<<":"<<ss;
        }

    }
    return 0;
}

