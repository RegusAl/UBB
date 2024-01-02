module map.toysocialnetwork {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;
    requires org.kordamp.bootstrapfx.core;
    requires java.sql;

    opens map.toysocialnetwork to javafx.fxml;
    exports map.toysocialnetwork;

    opens map.toysocialnetwork.domain to javafx.base;
}