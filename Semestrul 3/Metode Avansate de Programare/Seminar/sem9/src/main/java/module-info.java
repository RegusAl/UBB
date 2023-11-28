module com.example.sem9 {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;

    opens com.example.sem9 to javafx.fxml;
    exports com.example.sem9;


    opens com.example.sem9.domain to javafx.fxml, javafx.base;
    exports com.example.sem9.domain;

    opens com.example.sem9.service to javafx.fxml, javafx.base;
    exports com.example.sem9.service;


    opens com.example.sem9.controller to javafx.fxml, javafx.base;
    exports com.example.sem9.controller;

}