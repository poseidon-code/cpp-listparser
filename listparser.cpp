#include<bits/stdc++.h>

using namespace std;

/*  *****
Go through the README.md on how to use this program !
https://github.com/poseidon-code/Cpp-singleline-array-input
    *****   */


template <typename T>
class ListParser {
    private:    string str;                 // input String
                int size;                   // LIST size
                vector <T> list;            // LIST array
    
    public:     ListParser(string s) {
                    str = s;
                    size = 0;
                    list = create_list();
                }

                vector <T> create_list();   // GENERATES list of <T> type elements               
                vector <T> get_list();      // RETURNS Generated List                
                int get_size();             // RETURNS Generated List's Size
                void show_list();           // DISPLAY Generated List
};


// GENERATES list of <T> type elements 
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


// RETURNS Generated List
template <typename T>
vector<T> ListParser<T> :: get_list() {
    return list;
}


// RETURNS Generated List's Size
template <typename T>
int ListParser<T> :: get_size() {
    return size;
}


// DISPLAY Generated List
template <typename T>
void ListParser<T> :: show_list() {
    cout<<"{";
    for (int i=0; i<size; i++) {
        if(is_same<T, string>::value) 
            cout<<"\""<<list[i]<<"\"";
        else if(is_same<T, char>::value) 
            cout<<"\'"<<list[i]<<"\'";
        else cout<<list[i];
        if(i==size-1) break;
        cout<<", ";
    }
    cout<<"}";
}


// driver code <EDIT THIS>
int main() {
    string str; getline(cin, str);          // gets the INPUT STRING from the user
    ListParser<int> ob(str);                // Parse the STRING into ARRAY of <T> type data // here <int>

    // avaialble functions :
    vector<int> list = ob.get_list();       // gets the PARS'ED' LIST
    int size = ob.get_size();               // gets the PARS'ED' LIST's SIZE
    ob.show_list();                         // displays the PARS'ED' LIST

    return 0;
}
