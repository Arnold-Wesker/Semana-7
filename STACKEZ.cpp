// Primeramente, diseñé la clase Stack con las operaciones básicas de una pila: push, pop y top. Use un vector para implementar la pila 
// debido a su eficiencia y facilidad de uso. Luego, en la función main, tome las entradas del usuario y las procesé usando un switch. 
// Para cada entrada, realicé la operación correspondiente en la pila. Si la pila estaba vacía al intentar pop o top, manejé estos 
// casos para evitar errores. Finalmente, use ios_base::sync_with_stdio(false); y cin.tie(NULL); para acelerar las operaciones de 
// entrada/salida.
#include<iostream>
#include<vector>
using namespace std;

class Stack {
    vector<int> stack;
public:
    void push(int n);
    void pop();
    int top();
};

void Stack::push(int n) {
    stack.push_back(n);
}

void Stack::pop() {
    if (!stack.empty()) {
        stack.pop_back();
    }
}

int Stack::top() {
    if (stack.empty()) {
        return -1;
    } else {
        return stack.back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, query, n;
    cin >> T;
    Stack myStack;
    for (int i = 0; i < T; i++) {
        cin >> query;
        switch (query) {
        case 1:
            cin >> n;
            myStack.push(n);
            break;
        case 2:
            myStack.pop();
            break;
        case 3:
            n = myStack.top();
            if (n == -1) {
                cout << "Empty!" << "\n";
            } else {
                cout << n << "\n";
            }
            break;
        default:
            break;
        }
    }
    return 0;
}

