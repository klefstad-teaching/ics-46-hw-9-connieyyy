#include "ladder.h"
#include <iostream>
#include <fstream>
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

using namespace std;

void error(string word1, string word2, string msg) {
    cout << "Word 1: " << word1 << endl;
    cout << "Word 2: " << word2 << endl;
    cout << msg;
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream file(filename);
    int nodeNum = 0;
    
    file >> nodeNum;
    while (file >> word) {
        word_list.insert(word);
    }
    file.close();
}

void print_word_ladder(const vector<string>& ladder) {
    for (int i = 0; i < ladder.size(); ++i) {
        cout << ladder[i] << endl;
    }
}  

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}
