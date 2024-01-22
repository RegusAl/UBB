package org.examen.utils.dto;

public class OferteDTO {
    Long idSofer;
    String indicativMasina;
    String timpAsteptare;

    public OferteDTO(Long idSofer, String indicativMasina, String timpAsteptare) {
        this.idSofer = idSofer;
        this.indicativMasina = indicativMasina;
        this.timpAsteptare = timpAsteptare;
    }

    public Long getIdSofer() {
        return idSofer;
    }

    public void setIdSofer(Long idSofer) {
        this.idSofer = idSofer;
    }

    public String getIndicativMasina() {
        return indicativMasina;
    }

    public void setIndicativMasina(String indicativMasina) {
        this.indicativMasina = indicativMasina;
    }

    public String getTimpAsteptare() {
        return timpAsteptare;
    }

    public void setTimpAsteptare(String timpAsteptare) {
        this.timpAsteptare = timpAsteptare;
    }
}
