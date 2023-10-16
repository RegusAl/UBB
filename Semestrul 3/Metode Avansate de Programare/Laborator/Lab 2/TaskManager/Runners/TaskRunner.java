package Runners;

import Model.Task;

public interface TaskRunner {
    void executeOneTask(); // executa un task din colectia de task-uri de executat

    void executeAll(); // executa toate task-urile din colectia de task-uri

    void addTask(Task t); // adauga un task in colectia de task-uri de executat

    boolean hasTask(); // verifica daca mai sunt task-uri de executat
}
