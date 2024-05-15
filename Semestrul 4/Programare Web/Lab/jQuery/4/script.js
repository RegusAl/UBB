var tip = "";

function sortare(i) {
  var $table = $("#table1");
  var $rows = $table.find("tr");

  var a = $rows.eq(1).find("td").eq(i).html().toLowerCase();
  var b = $rows.eq(2).find("td").eq(i).html().toLowerCase();

  if (!isNaN(parseInt(a)) && !isNaN(parseInt(b))) {
    a = parseInt(a);
    b = parseInt(b);
  }

  tip = a > b ? "crescator" : "descrescator";

  for (let j = 1; j < $rows.length - 1; j++) {
    for (let k = j + 1; k < $rows.length; k++) {
      var ok = false;

      a = $rows.eq(j).find("td").eq(i).html().toLowerCase();
      b = $rows.eq(k).find("td").eq(i).html().toLowerCase();

      if (!isNaN(parseInt(a)) && !isNaN(parseInt(b))) {
        a = parseInt(a);
        b = parseInt(b);
      }

      if ((tip == "crescator" && a > b) || (tip == "descrescator" && a < b)) {
        ok = true;
      }

      if (ok) {
        var temp = $rows.eq(j).html();
        $rows.eq(j).html($rows.eq(k).html());
        $rows.eq(k).html(temp);
      }
    }
  }
}


function sortareOrizontala(n) {
  var tabel = document.getElementById("table2");
  var tipSort = "";
  var a, b, i, j, k;
  var rows = tabel.rows;

  a = rows[n].getElementsByTagName("td")[0].innerHTML.toLowerCase();
  b = rows[n].getElementsByTagName("td")[1].innerHTML.toLowerCase();
  if (!isNaN(parseInt(a)) && !isNaN(parseInt(b))) {
    a = parseInt(a);
    b = parseInt(b);
  }
  if (a > b) {
    tipSort = "crescator";
  } else {
    tipSort = "descrescator";
  }

  for (i = 0; i < rows[n].cells.length - 2; i++) {
    for (j = i + 1; j < rows[n].cells.length - 1; j++) {
      var ok = false;
      a = rows[n].getElementsByTagName("td")[i].innerHTML.toLowerCase();
      b = rows[n].getElementsByTagName("td")[j].innerHTML.toLowerCase();

      if (!isNaN(parseInt(a)) && !isNaN(parseInt(b))) {
        a = parseInt(a);
        b = parseInt(b);
      }

      if (tipSort == "crescator") {
        if (a > b) {
          ok = true;
        }
      } else if (tipSort == "descrescator") {
        if (a < b) {
          ok = true;
        }
      }
      if (ok) {
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
