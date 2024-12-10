#include "BinTree.hh"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to create a random binary tree
BinTree<string> construir_BinTree(const vector<string>& words, int depth) {
    if (depth == 0 || words.empty()) return BinTree<string>();
    string value = words[rand() % words.size()];
    BinTree<string> left, right;
    left = construir_BinTree(words, depth - 1);
    right = construir_BinTree(words, depth - 1);
    return BinTree<string>(value, left, right);
}

int main() {
    vector<string> palabras;
    string palabra;
    while (cin >> palabra && palabra != "FIN") {
        palabras.push_back(palabra);
    }

    srand(time(0)); // Seed the random number generator

    int depth=5;

    BinTree<string> tree = construir_BinTree(palabras, depth);

    tree.setOutputFormat(BinTree<string>::VISUALFORMAT);
    cout << tree << endl;
}