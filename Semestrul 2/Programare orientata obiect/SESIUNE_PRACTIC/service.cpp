#pragma once

#include <cstring>
#include "service.h"
#include "string"
#include "string.h"

void Service::adaugare(int id, string descriere, string prog, string stare) {
    int ok = 1;
    string p;
    vector<string> programatori;
    if(prog.empty() || descriere.empty())
        throw exception();
    if(stare!="open" && stare!="closed" && stare!="inprogress") {
        throw exception();
    }
    for(auto &i : getAll()) {
        if(i.get_id() == id) {
            throw exception();
        }
    }
    cout<<prog;
    for(auto &c : prog) {
        if(c == ' ')
            ok = 0;
        else
            p += c;
        if(ok == 0) {
            programatori.push_back(p);
            ok = 1;
            p = "";
        }
    }
    programatori.push_back(p);
    if(programatori.size() > 4) {
        cout<<programatori.size();
        throw exception();
    }
    repository.adaugare(Task(id, descriere, programatori, stare));
}

vector<Task> Service::filtrare(string s) {
    vector<Task> listaFiltrata;
    for(auto &el : repository.getAll()) {
        int ok = 0;
        for(auto &prog : el.get_programatori()) {
//            if(strcmp(s.c_str(), prog.c_str()) >= 0) {
//                ok = 1;
//            }
//              if(strstr(s.c_str(), prog.c_str()))
              int i = 0;
              for(auto& c : prog) {
                  if(c == s[i]) {
                      ok = 1;
                      i++;
                  } else {
                      ok = 0;
                      i = 0;
                  }
              }
            cout<<prog<<" ";
        }

        if(ok == 1) {
            for(auto &e : el.get_programatori()) {
                cout<<e<<" ";
            }
            listaFiltrata.push_back(el);
//            ok = 0;
        }

    }
    return (listaFiltrata);
}
