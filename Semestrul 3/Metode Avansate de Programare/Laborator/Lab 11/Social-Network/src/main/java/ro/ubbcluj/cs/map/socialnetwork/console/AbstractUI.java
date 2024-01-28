package ro.ubbcluj.cs.map.socialnetwork.console;


import ro.ubbcluj.cs.map.socialnetwork.service.ServiceI;

public abstract class AbstractUI implements UI {
    ServiceI srv;

    public AbstractUI(ServiceI srv) {
        this.srv = srv;
    }
}