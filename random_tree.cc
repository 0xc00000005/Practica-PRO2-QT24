#include "BinTree.hh"
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

BinTree<string> construir_BinTree(vector<string>& words, int depth, vector<string>& used_words, mt19937& gen) {
    if (depth == 0 || words.empty()) return BinTree<string>();

    static bool is_shuffled = false;
    if (!is_shuffled) {
        shuffle(words.begin(), words.end(), gen);
        is_shuffled = true;
    }

    uniform_int_distribution<size_t> dist(0, words.size() - 1);
    size_t index = dist(gen);
    string value = words[index];
    words.erase(words.begin() + index);
    used_words.push_back(value);

    BinTree<string> left = construir_BinTree(words, depth - 1, used_words, gen);
    BinTree<string> right = construir_BinTree(words, depth - 1, used_words, gen);

    return BinTree<string>(value, left, right);
}

BinTree<string> construir_BinTree_desigual(vector<string>& words, int depth, vector<string>& used_words, mt19937& gen) {
    if (depth == 0 || words.empty()) return BinTree<string>();

    static bool is_shuffled = false;
    if (!is_shuffled) {
        shuffle(words.begin(), words.end(), gen);
        is_shuffled = true;
    }

    uniform_int_distribution<size_t> dist(0, words.size() - 1);
    size_t index = dist(gen);
    string value = words[index];
    words.erase(words.begin() + index);
    used_words.push_back(value);

    uniform_real_distribution<> dis(0.0, 1.0);

    BinTree<string> left, right;
    if (dis(gen) < 0.7) {
        left = construir_BinTree_desigual(words, depth - 1, used_words, gen);
    }
    if (dis(gen) < 0.7) {
        right = construir_BinTree_desigual(words, depth - 1, used_words, gen);
    }

    return BinTree<string>(value, left, right);
}

void write_test_case(ofstream& output_file, vector<string>& used_words, mt19937& gen, int client_id) {
    output_file << "nuevo_cliente" << endl;
    if (used_words.size() < 3) {
        for (size_t i = 0; i < used_words.size(); ++i) {
            output_file << used_words[i];
            if (i < used_words.size() - 1) {
                output_file << " ";
            }
        }
        output_file << " #" << endl;
    } else {
        shuffle(used_words.begin(), used_words.end(), gen);
        output_file << used_words[0] << " " << used_words[1] << " " << used_words[2] << " #" << endl;
    }
    output_file << endl;
    output_file << "salas_a_visitar " << client_id << endl;
    output_file << endl;
    output_file << "quiere_comprar " << client_id << endl;
    output_file << endl;
}

int main() {
    vector<string> palabras;
    string palabra;
    ifstream file("./palabras2.cor");
    while (file >> palabra) {
        palabras.push_back(palabra);
    }
    file.close();

    int depth;
    cout << "Depth: ";
    cin >> depth;

    cout << "Even (0) o Uneven (1): ";
    int equilibrado;
    cin >> equilibrado;

    random_device rd;
    mt19937 gen(rd());
    vector<string> palabras_copy = palabras;


    BinTree<string> tree;
    vector<string> used_words;
    if (equilibrado == 0)
        tree = construir_BinTree(palabras, depth, used_words, gen);
    else
        tree = construir_BinTree_desigual(palabras, depth, used_words, gen);

    tree.setOutputFormat(BinTree<string>::VISUALFORMAT);

    int im;
    cout << "Print (0) or not (1): ";
    cin >> im;
    if (im == 0) cout << tree << endl;
    int i;
    cout << "Iterations: ";
    cin >> i;
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm* local_time = localtime(&now_time);
    char filename[100];
    strftime(filename, sizeof(filename), "%H%M%S.cor", local_time);
    ofstream output_file(filename);
    cout << "FILENAME: " << filename << endl;
    output_file << tree << endl;
    output_file << 3 << endl;
    output_file << endl;

    for (int j = 0; j < i; ++j) {
        write_test_case(output_file, used_words, gen, j + 1);
    }
    output_file << "fin" << endl;
    output_file.close();
}