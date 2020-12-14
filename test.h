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
    std::size_t xpos = input.find("x");
    std::size_t xpowpos = input.find("x^");
    if(xpos == std::string::npos){
        return "";
    } else if(xpowpos == std::string::npos) {
        return input.erase(xpos, 1);
    }else {
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
    return "i could not derive this"; 
    
}


std::vector<std::string> derive(std::vector<std::string> input) {
    std::vector<std::string> derived;
    for(std::size_t i = 0; i < input.size(); i+=2) {
        std::string simp = simplederive(input[i]);
        derived.push_back(simp);
        try{
            derived.push_back(input[i+1]);
        } catch (...) {
            //dont even worry about it lmao teehee :D
        }
    }
    return derived;
}

