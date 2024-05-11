#include "mediafile.h"

MediaFile::MediaFile(std::string t, std::string fp, std::string ft) : title(t), filePath(fp), fileType(ft) {}

std::string MediaFile::getTitle() {
    return title;
}

std::string MediaFile::getFilePath() {
    return filePath;
}

std::string MediaFile::getFileType() {
    return fileType;
}
