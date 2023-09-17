#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

class WordCount{

public:
    unsigned long value;
    string world;
    bool operator < (const WordCount& counter) const
    {
        if (value == counter.value){
            return world < counter.world;
        }
        return value > counter.value;
    } 
};


class WordCounter{

private:
    unsigned long all_worlds = 0;

    std::string start_line;   
    list <WordCount> listok;
    

public:
    void OpenFile(string input){

        std::ifstream file_in(input);
        if (!file_in.is_open()){
            cout << "Input file did not find";
            exit(1);
        }
        string s;
        while(getline(file_in, s, '\n')){           
            start_line.append(s);
            start_line.append(" ");
        }
        file_in.close();
    }

    void CountWords(){

        map <string, unsigned long> book;
        map <string, unsigned long> :: iterator it_book;
        string now;
        unsigned long start = 0;

        for (unsigned long i = 0; (i < start_line.size()) && (start_line[i] != '\0'); ++i){
            if (!(((start_line[i] >= '0') && (start_line[i] <= '9')) || ((start_line[i] >= 'a') && (start_line[i] <= 'z')) || ((start_line[i] >= 'A') && (start_line[i] <= 'Z')))){
                if (i != start){
                    now = start_line.substr(start, i - start);
                    it_book = book.find(now);
                    if (it_book == book.end()){
                        book.insert(make_pair(now, 1));
                    }
                    else {
                        book[now]++;
                    }
                    all_worlds++;
                }
                start = i+1;
            }
            
        }

        WordCount word_argument;
        it_book = book.begin();

        for(; it_book != book.end(); ++it_book){
            word_argument.world = it_book -> first;
            word_argument.value = it_book -> second;
            listok.push_back(word_argument);
        }

        listok.sort();
    }

    void WriteAnswers(string output){

        std::fstream file_out(output);

        if (!file_out.is_open()){
            cout << "Out file did not find";
            exit(1);
        }

        list <WordCount> :: iterator list_it = listok.begin();

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
