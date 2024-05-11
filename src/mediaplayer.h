#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "mediafile.h"

class MediaPlayer {
private:
    std::vector<MediaFile> playlist;
    int currentMediaIndex;

public:
    MediaPlayer();
    void addMedia(std::string title, std::string filePath, std::string fileType);
    void play();
    void pause();
    void stop();
    void next();
    void previous();
    void showPlaylist();
};

#endif // MEDIAPLAYER_H
