#include <iostream>
#include <fstream>
#include <string>

std::string getVersion() {
    std::ifstream versionFile("VERSION");
    if (versionFile.is_open()) {
        std::string version;
        getline(versionFile, version);
        versionFile.close();
        return version;
    } else {
        return "Unknown";
    }
}

int main() {
    std::cout << "<link rel='stylesheet' href='css/fontawesome-6.5.2.css'>" << std::endl;
    std::cout << "OpenMedia Version: " << getVersion() << std::endl;
    return 0;
}