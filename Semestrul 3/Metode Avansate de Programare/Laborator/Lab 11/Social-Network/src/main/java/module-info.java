module ro.ubbcluj.cs.map.socialnetwork {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;
    requires de.jensd.fx.glyphs.fontawesome;


    opens ro.ubbcluj.cs.map.socialnetwork to javafx.fxml;
    exports ro.ubbcluj.cs.map.socialnetwork;
    exports ro.ubbcluj.cs.map.socialnetwork.controller;
    opens ro.ubbcluj.cs.map.socialnetwork.controller to javafx.fxml;
}