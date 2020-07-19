#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

class ListParseInt {
    private:    string str;             //input String
                int size;               // LIST size
                vector <int> list;      // LIST array
    
    public:     ListParseInt(string s) {
                    str = s;
                    size = 0;
                    list = create_list();
                }
                
                // GENERATES list of <int> type elements
                vector <int> create_list() {
                    stringstream ss(str);
                    vector <int> temp_list;
                    int x;
                    while(ss>>x) {
                        temp_list.push_back(x);
                        if(ss.peek() == ' ')
                            ss.ignore();
                    }
                    for(int i : temp_list) size++;
                    return temp_list;
                }

                // RETURNS Generated List
                vector <int> get_list() {
                    return list;
                }

                // RETURNS Generated List's Size
                int get_size() {
                    return size;
                }

                // DISPLAY Generated List
                void show_list() {
                    cout<<"[";
                    for (int i=0; i<size; i++) {
                        cout<<list[i];
                        if(i==size-1) break;
                        else cout<<", ";
                    }
                    cout<<"]";
                }
};


int main() {
    string str; getline(cin, str);      // gets the INPUT STRING from the user
    ListParseInt ob(str);               // Parse the STRING into ARRAY of <int> type data

    // avaialble functions :
    vector <int> list = ob.get_list();      // gets the PARS'ED' LIST
    int size = ob.get_size();               // gets the PARS'ED' LIST's SIZE
    ob.show_list();                         // displays the PARS'ED' LIST

    // simple LIST traversing
    for (int i=0; i<size; i++) {
        cout<<list[i]<<" ";
    }

    return 0;
}