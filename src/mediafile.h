#ifndef MEDIAFILE_H
#define MEDIAFILE_H

#include <iostream>
#include <string>

class MediaFile {
private:
    std::string title;
    std::string filePath;
    std::string fileType;

public:
    MediaFile(std::string t, std::string fp, std::string ft);
    std::string getTitle();
    std::string getFilePath();
    std::string getFileType();
};

#endif // MEDIAFILE_H
