function loadContent() {
	setCurrent(0);
  		setInterval(function() {
	    var currentIndex=getCurrentIndex();
	    var elems = document.querySelectorAll("#lista li");
		var nr = elems.length;
		currentIndex++
		if(currentIndex === nr){
			currentIndex=0;
		}
		setCurrent(currentIndex);
    }, 1000);
}

function nextImage(n){ 
	var elems = document.querySelectorAll("#lista li");
 	var nr = elems.length;
  	var currentIndex=getCurrentIndex(); 
	if(n === 1){ 
		 currentIndex++
		 if(currentIndex === nr){
		 	currentIndex=0;
		 }
	}
	else if(n === -1)
	{
		currentIndex--
	  	if(currentIndex === -1){ 
	  		currentIndex=nr-1
	  	}
	}	
	setCurrent(currentIndex);
}

function setCurrent(index){ 
  var valDiv = document.getElementById("imgCurenta");
  valDiv.innerHTML = ''; 
  var element = document.querySelectorAll("#lista li")[index];
  var imagine = element.firstElementChild.cloneNode(true);
  var link = document.createElement("a");
  link.href = element.lastElementChild.href;
  link.appendChild(imagine);
  valDiv.appendChild(link);
}

function getCurrentIndex(){ 
	var elems = document.querySelectorAll("#lista li");
  	var valDiv = document.getElementById("imgCurenta");

 	var nr = elems.length;
  	var currentIndex = 0;

  	for(let i = 0; i < nr; i++){
  	 	if(valDiv.querySelector("img").src === elems[i].querySelector("img").src)
  	 	{
  	 		if(valDiv.querySelector("a").ahref === elems[i].querySelector("a").ahref)
  	 			currentIndex = i;
  	 	}
  	}
  	return currentIndex;
}