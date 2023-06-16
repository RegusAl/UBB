#pragma once

#include <sstream>
#include "repository.h"
#include "fstream"

void Repository::loadFromFile() {
    ifstream fin(fileName);
    string line;
    while(getline(fin, line)) {
        int id;
        string descriere, stare;
        vector<string> programatori;
        string curent;
        stringstream linestream(line);
        int nr = 0;
        while(getline(linestream, curent, ',')) {
            if(nr == 0) {
                id = stoi(curent);
            }
            if(nr == 1) {
                descriere = curent;
            }
            if(nr == 2) {
                stringstream linestream2(curent);
                string programator;
                while(getline(linestream2, programator, ' ')) {
                    programatori.push_back(programator);
                }
            }
            if(nr == 3) {
                stare = curent;
            }
            nr++;
        }
        Task task(id, descriere, programatori, stare);
        all.push_back(task);
    }
    fin.close();
}

void Repository::saveToFile(vector<Task> taskuri) {
    ofstream fout(fileName);
    for(auto &el : taskuri) {
        string programatori;
        for(auto &p : el.get_programatori()) {
            programatori += p;
            programatori+= " ";
        }
        fout<<el.get_id()<<","<<el.get_descriere()<<","<<programatori<<","<<el.get_stare()<<endl;
    }
    fout.close();
}

void Repository::adaugare(Task t) {
    all.push_back(t);
    saveToFile(all);
}
