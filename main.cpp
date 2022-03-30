#include <iostream>
#include <string>
#include <vector>
#include "BinaryTree.h"

int main() {
    BinaryTree<std::string, std::string> tree("item", "key");
    std::string command;
    while (command != "exit") {
        std::vector<std::string> parsed_command = {};
        std::getline(std::cin, command);
        size_t pos;
        std::string token;
        while ((pos = command.find(' ')) != std::string::npos) {
            token = command.substr(0, pos);
            if (!token.empty())
                parsed_command.push_back(token);
            command.erase(0, pos+1);
        }
        token = command.substr(0, pos);
        if (!token.empty())
            parsed_command.push_back(token);

        if (parsed_command[0] == "insert") {
            for (size_t i = 1; i < parsed_command.size(); i+=2) {
                tree.insert(parsed_command[i], parsed_command[i+1]);
            }
        } else if (parsed_command[1] == "search") {
            for (size_t i = 1; i < parsed_command.size(); ++i) {
                std::string item = tree.search(parsed_command[i]);
                if (!item.empty()) {
                    std::cout << "FOUND key " << parsed_command[i] << " with item " << item << "\n";
                } else {
                    std::cout << "NO item with key " << parsed_command[i] << " was found\n";
                }
            }
        }
    }
    return 0;
}
