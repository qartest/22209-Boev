#include "OutputTuple.hpp"
#include "DataError.hpp"

template <typename... Args>
class CSVParser 
{
private:
    class Iterator
    {
    private:
        CSVParser* parser_;
        int currentLine_;
    public:
        Iterator(CSVParser<Args...> &parser, int line) : parser_(&parser) , currentLine_(line){};
        Iterator(): parser_(nullptr), currentLine_(-1) {}
        bool operator!=(Iterator const& ot);
        std::tuple<Args...> operator*() const;
        Iterator& operator++();
    };

    std::fstream *file_;
    std::tuple<Args...> tuple_;
    std::string line_;

    char deleteOfColone_;
    char deleteOfLine_;
    char shieldChar_;

    int currentColone_ = 0;
    int currentLine_ = 0;

    void GetLine();
    std::string GetCell(std::istringstream& stringStream);

    template <typename T>
    T StrToType(std::istringstream& string);
    template <size_t...Is>
    void LineToTuple(std::index_sequence<Is...>);

public:
    CSVParser() = default;
    CSVParser(std::fstream& file, int count, char deleteOfColone, char deleteOfLine, char shieldChar);

    Iterator begin();
    Iterator end();
};

template <typename... Args>
CSVParser<Args...>::CSVParser(std::fstream& file, int count, char deleteOfColone, char deleteOfLine, char shieldChar){
    file_ = &file;
    deleteOfColone_= deleteOfColone;
    deleteOfLine_ = deleteOfLine;
    shieldChar_ = shieldChar;


    for(size_t i = 0; i < count; ++i){
        GetLine();
    }
}

template <typename... Args>
typename CSVParser<Args...>::Iterator CSVParser<Args...>::begin(){
    GetLine();
    return Iterator(*this, currentLine_);
}

template <typename... Args>
typename CSVParser<Args...>::Iterator CSVParser<Args...>::end(){
    return Iterator();
}

template <typename... Args>
void CSVParser<Args...> :: GetLine(){
    line_.clear();
    bool isShield = false;

    char letter;
    while(file_ -> get(letter)){
        if(letter == deleteOfLine_ && !isShield){
            break;
        }
        else{
            line_.append(1, letter);
            if(letter == shieldChar_){
                isShield = !isShield;
            }
        }
    }
    currentLine_;
}

template <typename... Args>
std::string CSVParser<Args...> :: GetCell(std::istringstream& stringStream){
    std::string answer;

    bool isShield = false;
    char letter;
    while(stringStream.get(letter)){
        if(letter == deleteOfColone_ && !isShield){
            break;
        }
        else if(letter == shieldChar_){
            isShield = !isShield;
        }
        else{
            answer.append(1, letter);
        }
    }
    return answer;
}


template <typename... Args>
bool CSVParser<Args...>::Iterator::operator!=(Iterator const& other){
    return (parser_ != other.parser_) || (currentLine_ != other.currentLine_);
}

template <typename...Args>
std::tuple<Args...> CSVParser<Args...> :: Iterator::operator*() const{
    parser_->LineToTuple(std::index_sequence_for<Args...>{});
    return parser_->tuple_;
}

template <typename...Args>
typename CSVParser<Args...>::Iterator& CSVParser<Args...>::Iterator::operator++(){
    if(!parser_->file_->eof()){
        parser_->GetLine();
        currentLine_ = parser_->currentLine_;
    }
    else{
        parser_ = nullptr;
        currentLine_ = -1;
    }
    return *this;
}

template <typename...Args>
template<typename T>
T CSVParser<Args...>::StrToType(std::istringstream& stringStream){
    std::string stringValue = GetCell(stringStream);
    ++currentColone_;

    std::stringstream ss(stringValue);

    T answer;

    ss >> answer;
    if(ss.fail()){
        throw DataError(currentColone_, currentLine_);
    }

    return answer;
}

template <typename... Args>
template <size_t... Is>
void CSVParser<Args...>::LineToTuple(std::index_sequence<Is...>){
    std::istringstream stringStream(line_);

    ((std::get<Is>(tuple_) = StrToType<std::tuple_element_t<Is, decltype(tuple_)>>(stringStream)), ...);
    currentColone_ = 0;
}