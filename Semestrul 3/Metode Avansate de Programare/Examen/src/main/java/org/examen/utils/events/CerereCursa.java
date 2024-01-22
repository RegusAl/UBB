package org.examen.utils.events;

public class CerereCursa implements Event{

    Long idPersoana;
    Long idSofer;
    String locatie;
    String timp;

    Status status;

    public CerereCursa(Long idPersoana, Long idSofer, String locatie, String timp, Status status) {
        this.idPersoana = idPersoana;
        this.idSofer = idSofer;
        this.locatie = locatie;
        this.timp = timp;
        this.status=status;
    }

    public Long getIdPersoana() {
        return idPersoana;
    }

    public void setIdPersoana(Long idPersoana) {
        this.idPersoana = idPersoana;
    }

    public Long getIdSofer() {
        return idSofer;
    }

    public void setIdSofer(Long idSofer) {
        this.idSofer = idSofer;
    }

    public String getLocatie() {
        return locatie;
    }

    public void setLocatie(String locatie) {
        this.locatie = locatie;
    }

    public String getTimp() {
        return timp;
    }

    public void setTimp(String timp) {
        this.timp = timp;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }
}
