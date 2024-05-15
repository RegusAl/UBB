var valueArray = [];
var clickedValues = [];
var tileIDs = [];
var noTilesFlipped = 0;

function shuffle(array) {
  for (var i = array.length - 1; i > 0; i--) {
    var j = Math.floor(Math.random() * (i + 1));
    var temp = array[j];
    array[j] = array[i];
    array[i] = temp;
  }
  return array;
}

function make_cells(nr) {
  nr = parseInt(nr);
  console.log(nr);
  valueArray = [];
  let j = 1;
  for (let i = 0; i < nr * nr; i++) {
    console.log(i);
    valueArray[i] = j;
    if (i % 2 == 1) {
      j += 1;
    }
  }
}

function style_tiles(valueArray) {
  var board = $("#board");
  board.css("width", Math.sqrt(valueArray.length) * 130 + 50 + "px");
}

function startNewGame(nr) {
  $("#hidden").hide();
  noTilesFlipped = 0;
  var output = "";
  make_cells(nr);
  valueArray = shuffle(valueArray);
  console.log(valueArray);
  style_tiles(valueArray);
  for (var i = 0; i < valueArray.length; i++) {
    output +=
      '<div id="tile_' +
      i +
      '" onclick="flip(this,\'' +
      valueArray[i] +
      "')\"></div>";
  }
  $("#board").html(output);
}

function flipBack() {
  $("#" + tileIDs[0])
    .html("")
    .css("background", "#222");
  $("#" + tileIDs[1])
    .html("")
    .css("background", "#222");
  clickedValues = [];
  tileIDs = [];
}

function flip(tile, val) {
  if ($(tile).html() == "" && clickedValues.length < 2) {
    $(tile).css("background", "url(images/" + val + ".jpg) no-repeat");
    // $(tile).css('color', 'black');
    // $(tile).html(val);
    if (clickedValues.length == 0) {
      clickedValues.push(val);
      tileIDs.push($(tile).attr("id"));
    } else if (clickedValues.length == 1) {
      clickedValues.push(val);
      tileIDs.push($(tile).attr("id"));
      if (clickedValues[0] == clickedValues[1]) {
        noTilesFlipped += 2;
        clickedValues = [];
        $("#" + tileIDs[0]).css("background-color", "green");
        $("#" + tileIDs[1]).css("background-color", "green");
        tileIDs = [];
        if (noTilesFlipped == valueArray.length) {
          $("#board").html("");
          $("#hidden").show();
        }
      } else {
        setTimeout(flipBack, 500);
      }
    }
  }
}
