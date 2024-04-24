function mutare(id_element, id_list) {
    var option_element =  document.getElementById(id_element)
    console.log(option_element)

    var list1 = document.getElementById('list1')
    var list2 = document.getElementById('list2')
    console.log(list1, list2)

    var selected_list = document.getElementById(id_list)

    if(list1 == selected_list) {
        console.log("1")
        list1.removeChild(option_element)
        option_element.ondblclick = function() {mutare(this.id, 'list2')}        
        list2.appendChild(option_element)
    }
    else {
        console.log("2")
        list2.removeChild(option_element)
        option_element.ondblclick = function() {mutare(this.id, 'list1')}
        list1.appendChild(option_element)
    }
}