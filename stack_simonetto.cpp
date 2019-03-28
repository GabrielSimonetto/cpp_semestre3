/*

    b. C++: Ler a documentação dos métodos push_back, pop_back, back de std::vector.

2. Utilizar a Stack (em C++, um std::vector) para,
     a partir de uma string, 
     verificar o balanceamento de três tipos de parênteses: (), {} e [].
    Parênteses estão balanceados quando:
      a. Da esquerda pra direita, todo fechamento é precedido por uma abertura:
       todo ) tem um ( anterior correspondente.
      b. Todo parênteses aberto é fechado: () está balanceado, (() não.
      c. Todo fechamento de parênteses fecha o tipo correspondente à última abertura: 
      ([]) é ok, ([)] não.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reduceClosures(stack<char> s){

}



int main() {
    stack<char> stackA;
    stack<char> stackB;

    string aux;

    cin >> aux;

    int size = string.size();
    for (int i=0; i<size; i++){
        stackA.push(string[size-1-i])
    }



    myStack.push(5);
    myStack.push(3);
    myStack.push(2);

    // cout << "pop once " << myStack.pop() << endl;
    cout << "top once " << myStack.top() << endl;
    // cout << "pop once " << myStack.pop() << endl;
}



