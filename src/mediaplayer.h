#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "mediafile.h"
#include <wx/wx.h>
#include <wx/mediactrl.h>

class MediaPlayer {
private:
    std::vector<MediaFile> playlist;
    int currentMediaIndex;
    wxMediaCtrl *player;
    wxListBox *playlistView;

public:
    MediaPlayer();
    void addMedia(std::string title, std::string filePath, std::string fileType);
    void play();
    void pause();
    void stop();
    void next();
    void previous();
    void showPlaylist(wxFrame *parent);
};

#endif // MEDIAPLAYER_H
