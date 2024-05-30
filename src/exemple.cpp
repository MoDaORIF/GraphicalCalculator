#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
    {
        wxPanel* panel = new wxPanel(this, wxID_ANY);

        button = new wxButton(panel, wxID_ANY, "Click Me", wxPoint(100, 50), wxDefaultSize);
        button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);
    }

    void OnButtonClick(wxCommandEvent& event)
    {
        wxMessageDialog dialog(this, "Button clicked!", "Info", wxOK | wxICON_INFORMATION);
        dialog.ShowModal();
    }

private:
    wxButton* button;
  //
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame("wxWidgets Demo");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
