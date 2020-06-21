#include "../../utils.h"

/**
 * This function will check whether a string has unique chars.
 * In this version we make use the set data structure
 */
bool hasUniqueChars_ver1(const string& str){
    unordered_set<char> chars;
    for (auto c : str){
        if(chars.find(c) == chars.end()){
            chars.insert(c);
        }
        else{
            return false;
        }
    }
    return true;
}

/**
 * this version doesn't make use of another data structture
 */
bool hasUniqueChars(const string& str){
    int check = 0;

    for(auto c : str){
        int cVal = c - 'a'; // here we assume that characters are from a-z which lets use a singe int
        if (check & (1 << cVal)){
            return false;
        }
        check |= (1 << cVal);
    }
    return true;
}

int main(){
    string str = "abcdefgjkl872MN";
    std::cout << "String " << str << " has unique chars: " << hasUniqueChars_ver1(str) << endl;
    std::cout << "String " << str << " has unique chars: " << hasUniqueChars(str) << endl;
    cout << std::numeric_limits<uint64_t>::max() << " vs " << (1<<25) << " vs " << (1<<100) << endl;
    return 0;
}