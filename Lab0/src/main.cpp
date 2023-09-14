#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

struct TMy{ 
    unsigned long value;
    string world;
    
};

bool compareInterval(TMy first, TMy second){
    if (first.value == second.value){
        return (first.world > second.world);
    }
    return (first.value > second.value);
}

class WordCounter{

private:
    unsigned long all_worlds = 0;

    std::string start_line;   
    char* line_with_spaces;

    map <string, int> book;
    map <string, int> :: iterator it_book;

    list <TMy> listok;
    list <TMy> :: iterator list_it;

public:
    void OpenFile(string input){

        std::ifstream file_in(input);
        if (!file_in.is_open()){
            cout << "Input file did not find";
            exit(0);
        }

        getline(file_in, start_line, '\0');
        file_in.close();
    }

    void CountWords(){

        for (unsigned int i = 0; (i < start_line.size()) && (start_line[i] != '\0'); ++i){
            if (!isalnum(start_line[i])){
                start_line[i] = ' ';
            }
        }

        line_with_spaces = strtok(const_cast<char*>(start_line.c_str()), " ");

        while (line_with_spaces != NULL){
            all_worlds++;
            it_book = book.find(line_with_spaces);
            if (it_book == book.end()){
                    book.insert(make_pair(line_with_spaces, 1));
            }
            else {
                book[line_with_spaces]++;
            }
            line_with_spaces = strtok(NULL, " ");
        }

        TMy word_argument;
        it_book = book.begin();

        for(; it_book != book.end(); ++it_book){
            word_argument.world = it_book -> first;
            word_argument.value = it_book -> second;
            listok.push_back(word_argument);
        }

        listok.sort(compareInterval);
    }

    void WriteAnswers(string output){

        std::fstream file_out(output);

        if (!file_out.is_open()){
            cout << "Out file did not find";
            exit(0);
        }

        list_it = listok.begin();

        for(; list_it != listok.end(); ++ list_it){
            file_out << list_it -> world << ", " << list_it -> value << ", " << (float)((list_it -> value) * 100 / (float)all_worlds) << "%" << endl;
        }
        file_out.close();

    }
};

int main(int argc, char* argv[]){

    WordCounter WC;
    WC.OpenFile(string(argv[1]));
    WC.CountWords();
    WC.WriteAnswers(string(argv[2]));

}
