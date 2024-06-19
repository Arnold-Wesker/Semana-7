// En mi implementación original, estaba usando un std::vector para implementar una Queue. Pero me di cuenta de que esta no era la mejor
// forma de hacerlo. Cuando realizaba la operación Dequeue, todos los demás elementos en el std::vector tenían que moverse, lo que  
// llevaba a una complejidad de tiempo de O(n). Para arreglarlo, implemente la Queue usando una lista enlazada. En esta implementación,
// cada Nodo de la lista enlazada contiene un data y un puntero next al siguiente Nodo. Ademas, mantengo el front y el final de la Queue 
// como punteros, permitiendome realizar las operaciones Enqueue y Dequeue mas eficientemente.
#include <iostream>
#include <string>

class Nodo {
public:
    int data;
    Nodo* next;

    Nodo(int data) : data(data), next(nullptr) {}
};

class Queue {
private:
    Nodo* front;
    Nodo* final;

public:
    Queue() : front(nullptr), final(nullptr) {}

    void Enqueue(int x) {
        Nodo* temp = new Nodo(x);
        if (front == nullptr) {
            front = final = temp;
            return;
        }
        final->next = temp;
        final = temp;
    }

    void Dequeue() {
        if (front == nullptr) {
            return;
        }
        Nodo* temp = front;
        front = front->next;
        if (front == nullptr) {
            final = nullptr;
        }
        delete temp;
    }

    int Front() {
        if (front != nullptr) {
            return front->data;
        }
        return -1;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T, x;
    std::string type;
    Queue q;
    std::cin >> T;
    std::cin.ignore();
    for (int i = 0; i < T; i++) {
        std::getline(std::cin, type);
        if (type[0] == '1') {
            x = std::stoi(type.substr(2));
            q.Enqueue(x);
        } else if (type[0] == '2') {
            q.Dequeue();
        } else if (type[0] == '3') {
            int val = q.Front();
            if (val != -1) {
                std::cout << val << '\n';
            } else {
                std::cout << "Empty!" << '\n';
            }
        }
    }
    return 0;
}
