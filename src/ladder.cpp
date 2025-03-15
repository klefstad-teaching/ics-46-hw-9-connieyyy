#include "ladder.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    if (abs((int)str1.length() - (int)str2.length()) > d) {
        return false;
    }

    int i = 0, j = 0;
    int differences = 0;

    while (i < str1.length() && j < str2.length()) {
        if (str1[i] != str2[j]) {
            return false; // testing to prevent time out
            differences++;
            if (differences > d) {
                return false;  // Exit early if difference > d
            }
        }
        i++;
        j++;
    }

    // Add remaining characters from the longer string
    differences += abs((int)str1.length() - (int)str2.length());

    return differences <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
    int word1length = word1.length();
    int word2length = word2.length();

    if (abs(word1length - word2length) > 1) {
        return false;
    }

    int difference = 0;
    int i = 0;
    int j = 0;

    while (i < word1length && j < word2length) {
        if (word1[i] != word2[j]) {
            if (++difference > 1) {
                return false;
            }

            if (word1length > word2length) {
                i++;
            } else if (word1length < word2length) {
                j++;
            } else {
                i++;
                j++;
            }
        } else {
            i++;
            j++;
        }
    }
    return true;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        return {begin_word};
    }
    // create queue of vector of strings
    queue<vector<string>> ladder_queue; 
    set<string> visited;

    ladder_queue.push({begin_word});
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (string word: word_list) {
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()) {
                if (visited.find(word) == visited.end()) {

                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);

                    if (word == end_word) {
                        return new_ladder;
                    }

                    ladder_queue.push(new_ladder);
                    visited.insert(word);
                }
            }
        }   

    }
    return {};
}

void error(string word1, string word2, string msg) {
    cout << "Word 1: " << word1 << endl;
    cout << "Word 2: " << word2 << endl;
    cout << msg;
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream file(file_name);    

    string word;
    while (file >> word) {
        word_list.insert(word);
    }
    file.close();
}

void print_word_ladder(const vector<string>& ladder) {
    for (size_t i = 0; i < ladder.size(); ++i) {
        cout << ladder[i] << " " << endl;
    }
}  