var tip = "";

function sortare(i) {
    var table = document.getElementById("table1");
    var rows = table.rows;

    a = rows[1].getElementsByTagName("td")[i].innerHTML.toLowerCase();
    b = rows[1+1].getElementsByTagName("td")[i].innerHTML.toLowerCase();

    if(!isNaN(parseInt(a)) && !isNaN(parseInt(b))) {
        a = parseInt(a);
        b = parseInt(b);
    }

    if(a > b){
        tip = "crescator";
    }else{
        tip = "descrescator";
    }

    for(let j = 1; j < rows.length-1; j++) 
    {
        for(let k = j+1; k < rows.length; k++) 
        {
            var ok = false;

            a = rows[j].getElementsByTagName("td")[i].innerHTML.toLowerCase();
            b = rows[k].getElementsByTagName("td")[i].innerHTML.toLowerCase();

            if(!isNaN(parseInt(a)) && !isNaN(parseInt(b))) {
			    a = parseInt(a);
			    b = parseInt(b);
			}

            if(tip == "crescator"){
                if(a > b){
                    ok = true;
                }
            }
            else if(tip == "descrescator"){
                if(a < b){
                    ok = true;
                }
            }

            if(ok){
                var temp = rows[j].innerHTML;
                rows[j].innerHTML = rows[k].innerHTML;
                rows[k].innerHTML = temp;
            }
        }
    }

}

function sortareOrizontala(n){
    var tabel = document.getElementById("table2");
    var tipSort = "";
    var a, b, i, j, k;
    var rows = tabel.rows;
    var row = rows[n];

    a = row.getElementsByTagName("td")[0].innerHTML.toLowerCase();
    b = row.getElementsByTagName("td")[1].innerHTML.toLowerCase();
    if(!isNaN(parseInt(a)) && !isNaN(parseInt(b))) {
        a = parseInt(a);
        b = parseInt(b);
    }
    if(a > b){
        tipSort = "crescator"; 
    }else{
        tipSort = "descrescator";
    }

    for(i = 0; i < (row.cells.length - 2); i++){
        for(j = i+1; j < (row.cells.length-1); j++){
            var ok = false;
            a = row.getElementsByTagName("td")[i].innerHTML.toLowerCase();
            b = row.getElementsByTagName("td")[j].innerHTML.toLowerCase();

            if(!isNaN(parseInt(a)) && !isNaN(parseInt(b))) {
                a = parseInt(a);
                b = parseInt(b);
            }

            if(tipSort == "crescator"){
                if(a > b){
                    ok = true;
                }
            }
            else if(tipSort == "descrescator"){
                if(a < b){
                    ok = true;
                }
            }
            if(ok){
                for (k = 0; k < rows.length; k++) {
                    var tempCol = rows[k].getElementsByTagName("td")[i].innerHTML;
                    var tempVal = rows[k].getElementsByTagName("td")[j].innerHTML;
                    rows[k].getElementsByTagName("td")[i].innerHTML = tempVal;
                    rows[k].getElementsByTagName("td")[j].innerHTML = tempCol;
                }
            }
        }
    }
}