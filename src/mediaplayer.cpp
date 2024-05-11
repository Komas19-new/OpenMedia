#include "mediaplayer.h"

MediaPlayer::MediaPlayer() : currentMediaIndex(0), player(nullptr), playlistView(nullptr) {}

void MediaPlayer::addMedia(std::string title, std::string filePath, std::string fileType) {
    MediaFile mediaFile(title, filePath, fileType);
    playlist.push_back(mediaFile);
    if (playlistView) {
        playlistView->Append(wxString(title));
    }
}

void MediaPlayer::play() {
    if (player && player->GetState() != wxMEDIASTATE_PLAYING) {
        player->Play();
    }
}

void MediaPlayer::pause() {
    if (player && player->GetState() == wxMEDIASTATE_PLAYING) {
        player->Pause();
    }
}

void MediaPlayer::stop() {
    if (player && player->GetState() != wxMEDIASTATE_STOPPED) {
        player->Stop();
    }
}

void MediaPlayer::next() {
    if (currentMediaIndex < playlist.size() - 1) {
        currentMediaIndex++;
        if (player) {
            player->Stop();
            player->Load(playlist[currentMediaIndex].getFilePath());
            player->Play();
        }
    }
}

void MediaPlayer::previous() {
    if (currentMediaIndex > 0) {
        currentMediaIndex--;
        if (player) {
            player->Stop();
            player->Load(playlist[currentMediaIndex].getFilePath());
            player->Play();
        }
    }
}

void MediaPlayer::showPlaylist(wxFrame *parent) {
    wxDialog dialog(parent, wxID_ANY, "Playlist", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    playlistView = new wxListBox(&dialog, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SINGLE | wxLB_HSCROLL | wxLB_NEEDED_SB);
    for (const auto& media : playlist) {
        playlistView->Append(wxString(media.getTitle()));
    }
    sizer->Add(playlistView, 1, wxEXPAND | wxALL, 5);

    wxBoxSizer *btnSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton *playBtn = new wxButton(&dialog, wxID_ANY, "Play");
    playBtn->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) { this->play(); });
    wxButton *pauseBtn = new wxButton(&dialog, wxID_ANY, "Pause");
    pauseBtn->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) { this->pause(); });
    wxButton *stopBtn = new wxButton(&dialog, wxID_ANY, "Stop");
    stopBtn->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) { this->stop(); });
    wxButton *nextBtn = new wxButton(&dialog, wxID_ANY, "Next");
    nextBtn->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) { this->next(); });
    wxButton *prevBtn = new wxButton(&dialog, wxID_ANY, "Previous");
    prevBtn->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) { this->previous(); });
    btnSizer->Add(playBtn, 0, wxALL, 5);
    btnSizer->Add(pauseBtn, 0, wxALL, 5);
    btnSizer->Add(stopBtn, 0, wxALL, 5);
    btnSizer->Add(nextBtn, 0, wxALL, 5);
    btnSizer->Add(prevBtn, 0, wxALL, 5);

    sizer->Add(btnSizer, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    dialog.SetSizerAndFit(sizer);
    dialog.ShowModal();
}
