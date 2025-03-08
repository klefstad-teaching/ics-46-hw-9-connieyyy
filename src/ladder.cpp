#include "ladder.h"
#include <iostream>
#include <fstream>
using namespace std;

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int i = 0, j = 0;
    while (i < str1.length() && j < str2.length()) {
        if (str1[i] != str2[j]) {
            if (i != j) {
                return false;  
            }
            ++j;
        } else {
            ++i;
            ++j;
        }
    }
}

bool is_adjacent(const string& word1, const string& word2) {
    // case 1: lengths are same & letter differs by 1
    if (word1.length() == word2.length()) {
        int different_letters = 0;
        for (int i = 0; i < word1.length(); ++i) {
            if (word1[i] != word2[i]) {
                different_letters += 1;
            }
        }
        return different_letters == 1;
    } else if (abs(word1.length() - word2.length()) == 1) {
        // case 2: lengths vary by 1 & all letters are same otherwise
        if (word1.length() > word2.length()) {
            return is_adjacent(word2, word1);  
        }
        return edit_distance_within(word1, word2, 1);
    }
    return false;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        return {begin_word};
    }
    // create queue of vector of strings
    queue<vector<string>> ladder_queue; 
    ladder_queue.push(begin_word);
    set<string> visited;
    visited.insert(begin_word);

    while (ladder_queue) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();

        for (string word: word_list) {
            if (is_adjacent(last_word, word)) {
                if (!visited.contains(word)) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    if (word == end_word) {
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }   

    }
    return {};
}