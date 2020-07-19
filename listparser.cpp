#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<type_traits>

using namespace std;

/*
Go through the README.md on how to use this :  
*/


template <typename T>
class ListParser {
    private:    string str;             //input String
                int size;               // LIST size
                vector <T> list;        // LIST array
    
    public:     ListParser(string s) {
                    str = s;
                    size = 0;
                    list = create_list();
                }

                // GENERATES list of <int> type elements
                vector <T> create_list();

                // RETURNS Generated List
                vector <T> get_list();

                // RETURNS Generated List's Size
                int get_size();

                // DISPLAY Generated List
                void show_list();
};


template <typename T>
vector<T> ListParser<T> :: create_list() {
    stringstream ss(str);
    vector <T> temp_list;
    T temp_element;
    while(ss>>temp_element) {
        temp_list.push_back(temp_element);
        if(ss.peek() == ' ') ss.ignore();
    }
    for(T i : temp_list) size++;
    return temp_list;
}


template <typename T>
vector<T> ListParser<T> :: get_list() {
    return list;
}

template <typename T>
int ListParser<T> :: get_size() {
    return size;
}

template <typename T>
void ListParser<T> :: show_list() {
    cout<<"[";
    for (int i=0; i<size; i++) {
        if(is_same<T, string>::value) 
            cout<<"\""<<list[i]<<"\"";
        else if(is_same<T, char>::value) 
            cout<<"\'"<<list[i]<<"\'";
        else cout<<list[i];
        if(i==size-1) break;
        cout<<", ";
    }
    cout<<"]";
}



int main() {
    string str; getline(cin, str);      // gets the INPUT STRING from the user
    ListParser<int> ob(str);          // Parse the STRING into ARRAY of <int> type data

    // avaialble functions :
    vector<int> list = ob.get_list();   // gets the PARS'ED' LIST
    int size = ob.get_size();              // gets the PARS'ED' LIST's SIZE
    ob.show_list();                        // displays the PARS'ED' LIST

    return 0;
}