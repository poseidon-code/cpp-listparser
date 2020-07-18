#include<iostream>
#include<string>
#include<sstream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<int> arr;
    int x;
    while(ss>>x) {
        arr.push_back(x);
        if(ss.peek() == ' ')
            ss.ignore();
    }
    int i = 0;
    for (int val : arr) {
        cout<<val<<" ";
        i++;
    }

    cout<<"\n"<<(arr[1]+arr[2]);
    cout<<"Size:"<<i;

    return 0;
}