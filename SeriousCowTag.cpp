/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


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
