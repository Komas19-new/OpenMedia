#include <wx/wx.h>
#include "mediaplayer.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    wxButton *openButton;
    wxButton *playButton;
    wxButton *pauseButton;
    wxButton *stopButton;
    wxButton *nextButton;
    wxButton *prevButton;
    wxButton *playlistButton;
    wxTextCtrl *text;
    wxListBox *playlist;

    void OnOpen(wxCommandEvent& event);
    void OnPlay(wxCommandEvent& event);
    void OnPause(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void OnNext(wxCommandEvent& event);
    void OnPrevious(wxCommandEvent& event);
    void OnShowPlaylist(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(wxID_OPEN, MyFrame::OnOpen)
    EVT_BUTTON(wxID_PLAY, MyFrame::OnPlay)
    EVT_BUTTON(wxID_PAUSE, MyFrame::OnPause)
    EVT_BUTTON(wxID_STOP, MyFrame::OnStop)
    EVT_BUTTON(wxID_FORWARD, MyFrame::OnNext)
    EVT_BUTTON(wxID_BACKWARD, MyFrame::OnPrevious)
    EVT_BUTTON(wxID_ABOUT, MyFrame::OnShowPlaylist)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("OpenMedia", wxPoint(50, 50), wxSize(800, 600));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    openButton = new wxButton(panel, wxID_OPEN, "Open File", wxPoint(20, 20));
    playButton = new wxButton(panel, wxID_PLAY, "Play", wxPoint(20, 50));
    pauseButton = new wxButton(panel, wxID_PAUSE, "Pause", wxPoint(20, 80));
    stopButton = new wxButton(panel, wxID_STOP, "Stop", wxPoint(20, 110));
    nextButton = new wxButton(panel, wxID_FORWARD, "Next", wxPoint(20, 140));
    prevButton = new wxButton(panel, wxID_BACKWARD, "Previous", wxPoint(20, 170));
    playlistButton = new wxButton(panel, wxID_ABOUT, "Show Playlist", wxPoint(20, 200));

    text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(150, 20), wxSize(200, 30), wxTE_READONLY);
    playlist = new wxListBox(panel, wxID_ANY, wxPoint(150, 60), wxSize(200, 200));
}

void MyFrame::OnOpen(wxCommandEvent& event) {
    wxString fileName = wxFileSelector("Choose a file to open");
    if (!fileName.IsEmpty()) {
        playlist->Append(fileName);
    }
}

void MyFrame::OnPlay(wxCommandEvent& event) {
    text->SetValue("Play clicked!");
}

void MyFrame::OnPause(wxCommandEvent& event) {
    text->SetValue("Pause clicked!");
}

void MyFrame::OnStop(wxCommandEvent& event) {
    text->SetValue("Stop clicked!");
}

void MyFrame::OnNext(wxCommandEvent& event) {
    text->SetValue("Next clicked!");
}

void MyFrame::OnPrevious(wxCommandEvent& event) {
    text->SetValue("Previous clicked!");
}

void MyFrame::OnShowPlaylist(wxCommandEvent& event) {
    wxMessageDialog dialog(this, "Playlist", "Playlist", wxOK | wxICON_INFORMATION);
    dialog.ShowModal();
}
