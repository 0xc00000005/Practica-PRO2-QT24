#include "BinTree.hh"
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>
using namespace std;

// Function to create a random binary tree
BinTree<string> construir_BinTree(const vector<string>& words, int depth) {
    if (depth == 0 || words.empty()) return BinTree<string>();
    static size_t index = 0;
    static random_device rd;
    static mt19937 gen(rd());
    
    if (index >= words.size()) {
        index = 0;
        vector<string> temp = words;
        shuffle(temp.begin(), temp.end(), gen);
    }
    string value = words[index++];
    BinTree<string> left = construir_BinTree(words, depth - 1);
    BinTree<string> right = construir_BinTree(words, depth - 1);
    return BinTree<string>(value, left, right);
}

BinTree<string> construir_BinTree_desigual(const vector<string>& words, int depth) {
    if (depth == 0 || words.empty()) return BinTree<string>();
    static size_t index = 0;
    static random_device rd;
    static mt19937 gen(rd());
    
    if (index >= words.size()) {
        index = 0;
        vector<string> temp = words;
        shuffle(temp.begin(), temp.end(), gen);
    }
    string value = words[index++];
    BinTree<string> left, right;
    uniform_real_distribution<> dis(0.0, 1.0);

    if (dis(gen) < 0.7) {
        left = construir_BinTree(words, depth - 1);
    }
    if (dis(gen) < 0.7) {
        right = construir_BinTree(words, depth - 1);
    }
    return BinTree<string>(value, left, right);
}

int main() {
    vector<string> palabras;
    string palabra;
    ifstream file("./palabras.cor");
    while (file >> palabra) {
        palabras.push_back(palabra);
    }
    file.close();

    int depth;
    cout << "Profundidad: ";
    cin >> depth;

    cout << "Equilibrado (0) o desigual (1): ";
    int equilibrado;
    cin >> equilibrado;

    srand(time(0)); // Seed the random number generator


    if (equilibrado==0) BinTree<string> tree = construir_BinTree(palabras, depth);
    if (equilibrado==1) BinTree<string> tree = construir_BinTree_desigual(palabras, depth);

    

    tree.setOutputFormat(BinTree<string>::VISUALFORMAT);
    cout << tree << endl;
}