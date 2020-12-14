#include <vector>
#include <string>
#include <sstream>
std::vector<std::string> findterms(std::string input){
    std::vector<std::string> list;
    size_t start=0;
    for(size_t i = 0; i <=input.length(); i++) {
        if(input[i] == '\0' || input[i] == ' '){
            std::string word = input.substr(start, i-start); 
            list.push_back(word);
            start=i+1;
        }
    }
    return list;
}


std::string simplederive(std::string input){
    std::cout << "i got to simple derive";
    std::size_t xpos = input.find("x");
    std::size_t xpowpos = input.find("x^");
    std::cout << "i got past the string finds";
    if(xpos == std::string::npos){
        std::cout << "no x";
        return "";
    } else if(xpowpos == std::string::npos) {
        std::cout << "no power";
        return input.erase(xpos, 1);
    }else {
        std::cout << "derive";
        std::string first = input.substr(0, xpowpos);
        std::string second = input.substr(xpowpos+2, input.length());
        int firstnum = std::stoi(first);
        int secondnum = std::stoi(second);
        firstnum = firstnum * secondnum;
        secondnum--;
        std::stringstream derived;
        derived << firstnum << "x^" << secondnum;
        return derived.str();
    }
    return "did not complete"; 
}


std::vector<std::string> derive(std::vector<std::string> input) {
    std::cout << "got to inital derive";
    std::vector<std::string> derived;
    for(std::size_t i = 0; i < input.size(); i++) {
       derived.push_back(simplederive(input[i]));
    }
    return derived;
}

