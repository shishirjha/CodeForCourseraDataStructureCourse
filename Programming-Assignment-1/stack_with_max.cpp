#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cassert>
#include <algorithm>
using std::stack;
using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    vector<int> main_stack;
    stack<int> aux_stack;
    int maxi;

  public:
  
    StackWithMax():maxi(0)
    {
        aux_stack.push(0);
    }

    void Push(int value) {
        main_stack.push_back(value);
        if(value>=aux_stack.top())
             aux_stack.push(value);
    }

    void Pop() {
        assert(main_stack.size());// asserts that stop the program if stack.size()=0 that is stop it if stack is empty. a way to debug the program.
        if(*(main_stack.rbegin())==aux_stack.top())
           aux_stack.pop();
        main_stack.pop_back();
        
    }

    int Max() const {
        assert(main_stack.size());
        return aux_stack.top();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack_max;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack_max.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack_max.Pop();
        }
        else if (query == "max") {
            cout << stack_max.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}


