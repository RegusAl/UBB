package ro.ubb.map.demogui.services;


import ro.ubb.map.demogui.domain.MessageTask;
import ro.ubb.map.demogui.repository.paging.Page;
import ro.ubb.map.demogui.repository.paging.Pageable;
import ro.ubb.map.demogui.repository.paging.PageableImplementation;
import ro.ubb.map.demogui.repository.paging.PagingRepository;
import ro.ubb.map.demogui.utils.events.ChangeEventType;
import ro.ubb.map.demogui.utils.events.MessageTaskChangeEvent;
import ro.ubb.map.demogui.utils.observer.Observable;
import ro.ubb.map.demogui.utils.observer.Observer;


import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class MessageTaskService implements Observable<MessageTaskChangeEvent> {
    private PagingRepository<String, MessageTask> repo;

    public MessageTaskService(PagingRepository<String, MessageTask> repo) {
        this.repo = repo;
    }

    private <T> Iterable <T> filter(Iterable <T> list, Predicate<T> cond)
    {
        List<T> rez=new ArrayList<>();
        list.forEach((T x)->{if (cond.test(x)) rez.add(x);});
        return rez;
    }

    public Iterable<MessageTask> bySubject(String subject) {
        return filter(repo.findAll(), messageTask -> messageTask.getDescription().contains(subject));
    }



    public MessageTask addMessageTaskTask(MessageTask messageTask) {
        MessageTask task = repo.save(messageTask);
        if(task == null) {
            notifyObservers(new MessageTaskChangeEvent(ChangeEventType.ADD,task));
        }
        return task;
    }

    public MessageTask deleteMessageTask(MessageTask t){
        MessageTask task=repo.delete(t.getId());
        if(task!=null) {
            notifyObservers(new MessageTaskChangeEvent(ChangeEventType.DELETE, task));
        }
        return task;
    }

    public MessageTask updateMessageTask(MessageTask newTask) {
        MessageTask oldTask=repo.findOne(newTask.getId());
        if(oldTask!=null) {
            MessageTask res=repo.update(newTask);
            notifyObservers(new MessageTaskChangeEvent(ChangeEventType.UPDATE, newTask, oldTask));
            return res;
        }
        return oldTask;
    }

    public Iterable<MessageTask> getAll(){
        return repo.findAll();
    }

    private List<Observer<MessageTaskChangeEvent>> observers=new ArrayList<>();

    @Override
    public void addObserver(Observer<MessageTaskChangeEvent> e) {
        observers.add(e);

    }

    @Override
    public void removeObserver(Observer<MessageTaskChangeEvent> e) {
        //observers.remove(e);
    }

    @Override
    public void notifyObservers(MessageTaskChangeEvent t) {
        observers.stream().forEach(x->x.update(t));
    }

    private int page = 0;
    private int size = 1;

    private Pageable pageable;

    public void setPageSize(int size) {
        this.size = size;
    }

//    public void setPageable(Pageable pageable) {
//        this.pageable = pageable;
//    }

    public Set<MessageTask> getNextMessages() {
//        Pageable pageable = new PageableImplementation(this.page, this.size);
//        Page<MessageTask> studentPage = repo.findAll(pageable);
//        this.page++;
//        return studentPage.getContent().collect(Collectors.toSet());
        this.page++;
        return getMessagesOnPage(this.page);
    }

    public Set<MessageTask> getMessagesOnPage(int page) {
        this.page=page;
        Pageable pageable = new PageableImplementation(page, this.size);
        Page<MessageTask> studentPage = repo.findAll(pageable);
        return studentPage.getContent().collect(Collectors.toSet());
    }
}
