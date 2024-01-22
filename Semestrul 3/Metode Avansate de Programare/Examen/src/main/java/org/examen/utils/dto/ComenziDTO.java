package org.examen.utils.dto;

import com.example.model.domain.Persoana;

import java.util.List;

public class ComenziDTO{
    Long idPersoana;
    String nume;
    String locatie;

    public ComenziDTO(Long idPersoana, String nume, String locatie) {
        this.idPersoana = idPersoana;
        this.nume = nume;
        this.locatie = locatie;
    }

    public Long getIdPersoana() {
        return idPersoana;
    }

    public void setIdPersoana(Long idPersoana) {
        this.idPersoana = idPersoana;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public String getLocatie() {
        return locatie;
    }

    public void setLocatie(String locatie) {
        this.locatie = locatie;
    }
}
