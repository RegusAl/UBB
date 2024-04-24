var valueArray = [];
var clickedValues = [];
var tileIDs = [];			
var noTilesFlipped = 0;		


function shuffle(array)
{
	for (var i = array.length - 1; i > 0; i--) 
	{
		var j = Math.floor(Math.random() * (i + 1));
		var temp = array[j];
		array[j] = array[i];
		array[i] = temp;
	}

	return array
}

function make_cells(nr) {
	nr = parseInt(nr)
	console.log(nr)
	valueArray = [];
	let j = 0
	for(let i = 0; i < nr * nr; i ++) {
		console.log(i)
		valueArray[i] = j
		if(i % 2 == 1) {
			j += 1
		}
	}
}

function style_tiles(valueArray) {
	var board = document.getElementById('board');
	board.style.width = (Math.sqrt(valueArray.length) * 130 + 50) + 'px';
}

function startNewGame(nr)
{
	document.getElementById("hidden").style.display = "none";
	noTilesFlipped = 0;
	var output = '';
	make_cells(nr)
	valueArray = shuffle(valueArray);
	console.log(valueArray)
	style_tiles(valueArray)
    for (var i = 0; i < valueArray.length; i++) {
        output += '<div id="tile_' + i + '" onclick="flip(this,\'' + valueArray[i] + '\')"></div>';
    }
	document.getElementById('board').innerHTML = output;
}

function flipBack() {
	document.getElementById(tileIDs[0]).innerHTML = "";
	document.getElementById(tileIDs[1]).innerHTML = "";
	clickedValues = [];
	tileIDs = [];
}

function flip(tile, val)
{
	if (tile.innerHTML == "" && clickedValues.length < 2)
	{
		tile.style.background = "#222";
		tile.style.fontcolor = "black";
		tile.innerHTML = val;
		if (clickedValues.length == 0)
		{
			clickedValues.push(val);
			tileIDs.push(tile.id);
		}
		else if(clickedValues.length == 1) 
		{
			clickedValues.push(val);
			tileIDs.push(tile.id);
			if (clickedValues[0] == clickedValues[1])
			{
				noTilesFlipped += 2;
				document.getElementById(tileIDs[0]).style.backgroundColor = "green";
				document.getElementById(tileIDs[1]).style.backgroundColor = "green";
				clickedValues = [];
				tileIDs = [];
				if (noTilesFlipped == valueArray.length)
				{
					document.getElementById('board').innerHTML = "";
					document.getElementById("hidden").style.display = "block";
				}
			}
			else
			{
				setTimeout(flipBack, 500);
			}
		}
	}
}