package ro.ubbcluj.cs.map.socialnetwork.domain;


import java.time.LocalDateTime;
import java.util.List;

public class Message extends Entity<Long>{
    private User from;
    private List<User> to;
    private LocalDateTime date;
    private String message;
    private Message replyTo;

    public Message(User from, List<User> to, String message) {
        this.from = from;
        this.to = to;
        this.date = LocalDateTime.now();
        this.message = message;
        this.replyTo = null;
    }

    public Message(Long id, User from, List<User> to, LocalDateTime date, String message, Message replyTo) {
        this.id = id;
        this.from = from;
        this.to = to;
        this.date = date;
        this.message = message;
        this.replyTo = replyTo;
    }

    public Message(Long id, User from, List<User> to, LocalDateTime date, String message) {
        this.id = id;
        this.from = from;
        this.to = to;
        this.date = date;
        this.message = message;
    }

    public Message(User from, List<User> to, String message, Message replyTo) {
        this.from = from;
        this.to = to;
        this.message = message;
        this.replyTo = replyTo;
        this.date = LocalDateTime.now();
    }

    public Message(Long id, User from, String message, LocalDateTime date) {
        setId(id);
        this.from = from;
        this.date = date;
        this.message = message;
    }

    public User getFrom() {
        return from;
    }

    public void setFrom(User from) {
        this.from = from;
    }

    public List<User> getTo() {
        return to;
    }

    public void setTo(List<User> to) {
        this.to = to;
    }

    public LocalDateTime getDate() {
        return date;
    }

    public void setDate(LocalDateTime date) {
        this.date = date;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public Message getReplyTo() {
        return replyTo;
    }

    public void setReplyTo(Message replyTo) {
        this.replyTo = replyTo;
    }

    @Override
    public String toString() {
        if (replyTo == null) {
            return from.getFirstName() +
                    ": " + message + "\nDATE:" +
                    date;
        } else {
            return "REPLY TO: "  + replyTo.getFrom().getFirstName() + ": " + truncateString(getReplyTo().getMessage(), 25) + "\n" +
                    from.getFirstName() + ": " +
                    message +
                    "\nDATE:" + date;
        }
    }

    private static String truncateString(String input, int maxLength) {
        if (input.length() <= maxLength) {
            return input; // If the string is already within the limit, return it unchanged
        } else {
            return input.substring(0, maxLength) + "..."; // Truncate and add "..."
        }
    }
}
