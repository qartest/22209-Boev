#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <list>


using namespace std;
template<typename Iterator>
using IteratorPair = map <string, unsigned long> :: iterator;

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
 
    list <WordCount> listok;
    
    map <string, unsigned long> book;


    void AppendWord(unsigned long start, unsigned long end, string s){
        if (end != start){
            string now = s.substr(start, end - start);

            bool CF = book.insert(make_pair(now, 1)).second;
            map <string, unsigned long> :: iterator Check = book.insert(make_pair(now, 1)).first;
            if(!CF){
                (Check -> second)++;
            }
            all_worlds++;
        }
    }

public:
    int OpenFile(string input){

        std::ifstream file_in(input);
        if (!file_in.is_open()){
            cout << "Input file did not find";
            return 0;
        }

        string s;

        while(getline(file_in, s, '\n')){   
            unsigned long start = 0;
            for (unsigned long i = 0; (i < s.size()); ++i){
                if (!(((s[i] >= '0') && (s[i] <= '9')) || ((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z')))){
                    AppendWord(start, i, s);
                    start = i+1;
                }
            }
            if (start < s.size()- 1){
                AppendWord(start, s.size(), s);
            }

        }
        
        file_in.close();
        return 1;
    }

    void CountWords(){

        WordCount word_argument;
        map <string, unsigned long> :: iterator it_book = book.begin();

        for(; it_book != book.end(); ++it_book){
            word_argument.world = it_book -> first;
            word_argument.value = it_book -> second;
            listok.push_back(word_argument);
        }

        listok.sort();
    }

    int WriteAnswers(string output){

        std::fstream file_out(output);

        if (!file_out.is_open()){
            cout << "Out file did not find";
            return 0;
        }

        list <WordCount> :: iterator list_it = listok.begin();

        for(; list_it != listok.end(); ++ list_it){
            file_out << list_it -> world << ", " << list_it -> value << ", " << (float)((list_it -> value) * 100 / (float)all_worlds) << "%" << endl;
        }
        file_out.close();
        return 1;
    }
};

int main(int argc, char* argv[]){
    
    // if (argc != 3){
    //     std::cout << "Bad input";
    //     return 1;
    // }
    string c = "C:\\Projects\\First\\build\\input.txt";
    string v = "C:\\Projects\\First\\build\\output.csv";
    WordCounter WC;
    if (WC.OpenFile(c) == 0){
        return 1;
    }
    WC.CountWords();
    if (WC.WriteAnswers(v) == 0){
        return 1;
    }

}
