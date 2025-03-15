#include "ladder.h"

int main() {
    set<string> word_list;
    string file_name = "words.txt";
    load_words(word_list, file_name);

    string start_word, end_word;
    cout << "Enter the start word: ";
    cin >> start_word;
    cout << "Enter the end word: ";
    cin >> end_word;

    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);
    print_word_ladder(ladder);

    return 0;
}