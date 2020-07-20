# **C++ Single Line Array Parser**

This is a C++ program that can parse space-seperated input elements entered during runtime, into an array in C++, without requiring the size of the array during compilation.

> **IMPORTANT :** Always include the code of `ListParser` class and it's required `header files` before your `main()`. To do so [clone](https://github.com/poseidon-code/cpp-listparser.git) / [copy](https://github.com/poseidon-code/cpp-listparser/blob/master/listparser.cpp) / [download](https://github.com/poseidon-code/cpp-listparser/archive/master.zip) the code and create your desired `main()`.
___

# Concept

The concept is taken from `python`'s dynamically-typed approach with variables, that can easily determine whether the input is a `list` (`array` in C++) type or some other type during runtime.

This `C++` program will yeild same results as that of `python`'s code for :
```python
a = input()     # takes input >> makes a 'list'
size = len(a)   # gets the size of 'list'
print(a)        # displays the 'list'
```
and `C++` code will be :
```c++
/* *0* with 70 lines of 'ListParser' class code included *0* */

int main() {
    string str;
    getline(cin, str);              // takes input
    
    ListParser<int> object(str);    // makes an 'array'
    int size = object.get_size();   // gets the size of 'array'
    object.show_list();             // displays the 'array'

    return 0;
}
```
___


## Usage

*   Create a `string` inside `int main()` type variable and take input during the runtime using      `getline()`.

    Your code will look like this :
    ```c++
    int main() {
        string str;
        getline(cin, str);

        return 0;
    }
    ```

*   Create a `ListParser` object inside `int main()`, and pass the string variable to the `ListParser` object.

    Your code will look like this _(notice `<int>`)_ :
    ```c++
    int main() {
        string str;
        getline(cin, str);
        
        ListParser<int> object(str);    // parse the inputed string as an 'array' of <int> type elements

        return 0;
    }
    ```
    >   You need to add the **data type** of the object _(as the program uses **C++ Templates**)_ using `< >` _(angled brackets)_. This data type will determine the type of array that will be generated.

    >   You can use any C++ premitive datatypes _**i.e.** `int`, `float`, `char`, `string` and `double`_.

*   During runtime, enter elements seperated by `space`, then press `ENTER` on keyboard and the string will be parsed into an array. It would look like this :
    ```cmd
    C:\ListParser> ./a.exe
    1 2 3 4 5 6 7 8 9 0
    ```



## Displaying the List

A `show_list()` is provided with the `ListParser` class that will display all the elements inside the list _(formatting based on type)_.

Your code will look like this :
```c++
int main() {
    string str;
    getline(cin, str);
    
    ListParser<int> object(str);

    object.show_list();

    return 0;
}
```
On executing this program :
```cmd
C:\ListParser> ./a.exe
1 2 3 4 5 6 7 8 9 0
{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}
```



## Getting the List

To retreive/store the array into another variable, one can use `get_list()` provided with the `ListParser` class.

Your code will look like this _(notice `vector<int> list_variable`)_ :
```c++
int main() {
    string str;
    getline(cin, str);
    
    ListParser<int> object(str);

    vector<int> list_variable = object.get_list();
    // now 'list_variable' is an array of <int> type elements

    return 0;
}
```
>   `vector` type is used to store the array (**compulsary**). The data type inside `< >` _(angled brackets)_ must be same as that of the `ListParser` class.

**Now, every `array[]` operations can be performed on this variable** _(`list_variable` in this case)_



## Getting Size of the List

To retreive/store the size of the array into another variable, one can use `get_size()` provided with the `ListParser` class.

Your code will look like this _(notice `int list_size`)_ : 
```c++
int main() {
    string str;
    getline(cin, str);
    
    ListParser<int> object(str);

    int list_size = object.get_size();

    return 0;
}
```
>   **Size** should always be saved inside an `int` type variable.



## Complete Example / Traversing the List

All the functionalities of the program can be used subsequently. Here is a simple example that would accomplish the usage of all the _functions_ provided by `ListParser` class :

This program will >> _takes **words** as user inputs_ > _displays the entered list_ > _traverse the entire list_ :
```c++
int main() {
    string str;
    getline(cin, str);
    
    ListParser<string> object(str);     // notice type <string>

    vector<string> list_varable = object.get_list();    // here also <string>
    int list_size = object.get_size();

    cout<<"Inputed List : "<<object.show_list()<<"\n";

    cout<<"Traversed List : ";
    for(int i=0; i<size; i++) {
        cout<<list_variable[i]<<" --> ";
    }
    cout<<"END";

    return 0;
}
```

The **Output** on running this program :
```cmd
C:\ListParser> ./a.exe
dog cat parrot fish lion tiger eagle
Inputed List : {"dog", "cat", "parrot", "fish", "lion", "tiger", "eagle"}
Traversed List : dog --> cat --> parrot --> fish --> lion --> tiger --> eagle --> END
```
___

### Good Luck CODING 😊