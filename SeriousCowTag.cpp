//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <cmath>

using namespace std;
int n, pox[1500], poy[1500];
int cowleft[1500];
bool ch=false;

void tag(int cow)
{
    int i, c;
    long double small=100000;
    for(i=0;i<n;i++){
        if(i==cow || cowleft[i]==1){
            continue;
        }
        if(small>sqrt((pox[i]-pox[cow])*(pox[i]-pox[cow])+(poy[i]-poy[cow])*(poy[i]-poy[cow]))){
            small=sqrt((pox[i]-pox[cow])*(pox[i]-pox[cow])+(poy[i]-poy[cow])*(poy[i]-poy[cow]));
            c=i;
        }
    }
    cowleft[c]=1;
    return;
}

int check()
{
    int i,c=0, po;
    for(i=0;i<n;i++){
        if(!cowleft[i]){
            c++, po=i;
        }
    }
    if(c==1){
        if(!ch)
            cout << po+1 << endl;
        return 1;
    }
    return 0;
}

int main()
{
    int i;
    
    cin >> n;
    for(i=0;i<n;i++){
        cin >> pox[i] >> poy[i];
        pox[i]+=7500, poy[i]+=7500;
    }
    
    while(!check()){
        for(i=0;i<n;i++){
            if(check()){
                ch=true;
                break;
            }
            if(cowleft[i]==1){
                continue;
            }
            tag(i);
        }
    }
    
    return 0;
}
