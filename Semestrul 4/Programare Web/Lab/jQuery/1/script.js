function mutare(id_element, id_list) {
  var $option_element = $("#" + id_element);
  console.log($option_element);

  var $list1 = $("#list1");
  var $list2 = $("#list2");
  console.log($list1, $list2);

  var $selected_list = $("#" + id_list);

  if ($list1.is($selected_list)) {
    console.log("1");
    $list1.find($option_element).remove();
    $option_element.on("dblclick", function () {
      mutare(this.id, "list2");
    });
    $list2.append($option_element);
  } else {
    console.log("2");
    $list2.find($option_element).remove();
    $option_element.on("dblclick", function () {
      mutare(this.id, "list1");
    });
    $list1.append($option_element);
  }
}
