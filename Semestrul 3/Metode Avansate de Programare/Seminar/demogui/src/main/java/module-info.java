module ro.ubb.map.demogui {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;
    requires org.kordamp.bootstrapfx.core;

    opens ro.ubb.map.demogui to javafx.fxml;
    opens ro.ubb.map.demogui.controller to javafx.fxml;
    exports ro.ubb.map.demogui;

    opens ro.ubb.map.demogui.domain to javafx.base;
    exports ro.ubb.map.demogui.controller;

}