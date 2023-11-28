package com.example.sem9.controller;

import com.example.sem9.domain.Nota;
import com.example.sem9.domain.NotaDto;
import com.example.sem9.service.ServiceManager;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;


import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class NotaController {

    ObservableList<NotaDto> modelGrade = FXCollections.observableArrayList();
    List<String> modelTema;
    private ServiceManager service;


    @FXML
    TableColumn<NotaDto, String> tableColumnName;
    @FXML
    TableColumn<NotaDto, String> tableColumnTema;
    @FXML
    TableColumn<NotaDto, Double> tableColumnNota;
    @FXML
    TableView<NotaDto> tableViewNote;
    //----------------------end TableView fx:id----------------

    @FXML
    TextField textFieldName;
    @FXML
    TextField textFieldTema;
    @FXML
    TextField textFieldNota;

//    @FXML
//    ComboBox<String> comboBoxTeme;

    @FXML
    public void initialize() {
        tableColumnName.setCellValueFactory(new PropertyValueFactory<NotaDto, String>("studentName"));
        tableColumnTema.setCellValueFactory(new PropertyValueFactory<NotaDto, String>("temaId"));
        tableColumnNota.setCellValueFactory(new PropertyValueFactory<NotaDto, Double>("nota"));

        tableViewNote.setItems(modelGrade);

        textFieldName.textProperty().addListener(o -> handleFilter());
        textFieldTema.textProperty().addListener(o -> handleFilter());
        textFieldNota.textProperty().addListener(o -> handleFilter());

//        comboBoxTeme.getSelectionModel().selectedItemProperty().addListener(
//                (x, y, z) -> handleFilter()
//        );

    }

    private List<NotaDto> getNotaDTOList() {
        return service.findAllGrades()
                .stream()
                .map(n -> new NotaDto(n.getStudent().getName(), n.getTema().getId(), n.getValue(), n.getProfesor()))
                .collect(Collectors.toList());
    }

    private void handleFilter() {

//        String selection = comboBoxTeme.getSelectionModel().getSelectedItem();
//        List<NotaDto> all = getNotaDTOList()
//                .stream()
//                .filter(tema -> tema.getTemaId().equals(selection))
//                .toList();
//        modelGrade.setAll(all);

        String name = textFieldName.getText();
        String tema = textFieldTema.getText();
        String nota = textFieldNota.getText();

        Predicate<NotaDto> verifyName = o -> o.getStudentName().startsWith(name);
        Predicate<NotaDto> verifyTema = o -> o.getTemaId().startsWith(tema);
        Predicate<NotaDto> verifyNota = o -> {
            if (!Objects.equals(nota, "")) {
                return o.getNota() > Double.parseDouble(nota);
            } else return true;
        };

        List<NotaDto> multipleFilter = getNotaDTOList()
                .stream()
                .filter(verifyName.and(verifyTema).and(verifyNota))
                .toList();
//
//        multipleFilter = multipleFilter
//                .stream()
//                .filter(o -> o.getStudentName().startsWith(name))
//                .toList();
//
//        multipleFilter = multipleFilter
//                .stream()
//                .filter(o -> o.getTemaId().startsWith(tema))
//                .toList();
//
//
//        if (!Objects.equals(nota, "")) {
//            multipleFilter = multipleFilter
//                    .stream()
//                    .filter(o -> o.getNota() > Double.parseDouble(nota))
//                    .toList();
//        }

        modelGrade.setAll(multipleFilter);

    }


    public void setService(ServiceManager service) {
        this.service = service;
        modelGrade.setAll(getNotaDTOList());
        modelTema = service.findAllHomeWorks()
                .stream()
                .map(x -> x.getId())
                .collect(Collectors.toList());
//        comboBoxTeme.getItems().setAll(modelTema);
//        comboBoxTeme.getSelectionModel().selectFirst();
    }
}
