#include "mediaplayer.h"

MediaPlayer::MediaPlayer() {
    currentMediaIndex = -1;
}

void MediaPlayer::addMedia(std::string title, std::string filePath, std::string fileType) {
    MediaFile media(title, filePath, fileType);
    playlist.push_back(media);
}

void MediaPlayer::play() {
    if (playlist.empty()) {
        std::cout << "No media selected." << std::endl;
        // Display media icon
        std::cout << "<i class='fas fa-file-media'></i>" << std::endl;
        return;
    }
    std::cout << "Playing: " << playlist[currentMediaIndex].getTitle() << std::endl;
    // Code to play the media file
}

void MediaPlayer::pause() {
    if (currentMediaIndex == -1) {
        std::cout << "No media selected." << std::endl;
        // Display media icon
        std::cout << "<i class='fas fa-file-media'></i>" << std::endl;
        return;
    }
    // Code to pause the media file
    std::cout << "Paused: " << playlist[currentMediaIndex].getTitle() << std::endl;
}

void MediaPlayer::stop() {
    if (currentMediaIndex == -1) {
        std::cout << "No media selected." << std::endl;
        // Display media icon
        std::cout << "<i class='fas fa-file-media'></i>" << std::endl;
        return;
    }
    // Code to stop the media file
    std::cout << "Stopped: " << playlist[currentMediaIndex].getTitle() << std::endl;
}

void MediaPlayer::next() {
    if (playlist.empty()) {
        std::cout << "No media selected." << std::endl;
        // Display media icon
        std::cout << "<i class='fas fa-file-media'></i>" << std::endl;
        return;
    }
    if (currentMediaIndex < playlist.size() - 1) {
        currentMediaIndex++;
    } else {
        currentMediaIndex = 0;
    }
    play();
}

void MediaPlayer::previous() {
    if (playlist.empty()) {
        std::cout << "No media selected." << std::endl;
        // Display media icon
        std::cout << "<i class='fas fa-file-media'></i>" << std::endl;
        return;
    }
    if (currentMediaIndex > 0) {
        currentMediaIndex--;
    } else {
        currentMediaIndex = playlist.size() - 1;
    }
    play();
}

void MediaPlayer::showPlaylist() {
    if (playlist.empty()) {
        std::cout << "No media selected." << std::endl;
        // Display media icon
        std::cout << "<i class='fas fa-file-media'></i>" << std::endl;
        return;
    }
    std::cout << "Current Playlist:" << std::endl;
    for (int i = 0; i < playlist.size(); i++) {
        std::cout << i + 1 << ". " << playlist[i].getTitle() << std::endl;
    }
}
