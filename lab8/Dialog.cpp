#include <iostream>
#include "Dialog.h"
using namespace std;
Dialog::Dialog() : Tree() { EndState = 0; }
Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event) {
    string OpInt = "+-szqm";
    string s;
    cout << "> "; cin >> s;
    char code = s[0];
    if (OpInt.find(code) != string::npos) {
        event.what = evMessage;
        switch (code) {
            case 'm': event.command = cmMake; break;
            case '+': event.command = cmAdd; break;
            case '-': event.command = cmDel; break;
            case 's': event.command = cmShow; break;
            case 'z': event.command = cmAverageAge; break;
            case 'q': event.command = cmQuit; break;
        }
    } else event.what = evNothing;
}

int Dialog::Execute() {
    TEvent event;
    do {
        EndState = 0;
        GetEvent(event);
        HandleEvent(event);
    } while (!Valid());
    return EndState;
}

int Dialog::Valid() { return (EndState == 0) ? 0 : 1; }
void Dialog::ClearEvent(TEvent& event) { event.what = evNothing; }
void Dialog::EndExec() { EndState = 1; }

void Dialog::HandleEvent(TEvent& event) {
    if (event.what == evMessage) {
        switch (event.command) {
            case cmMake:
                cout << "Enter count: "; int n; cin >> n;
                for (int i = 0; i < n; i++) Add();
                ClearEvent(event);
                break;
            case cmAdd: Add(); ClearEvent(event); break;
            case cmDel: Del(); ClearEvent(event); break;
            case cmShow: Show(); ClearEvent(event); break;
            case cmAverageAge:
                cout << "Average age: " << GetAverageAge() << endl;
                ClearEvent(event);
                break;
            case cmQuit: EndExec(); ClearEvent(event); break;
        }
    }
}