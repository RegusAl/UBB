$(document).ready(function () {
  $("#birth").on("change", updateAge);
});

function showMessage(message) {
  if (message == "") alert("Everything GOOD!");
  else alert(message);
}

function calculateAge(birthdate) {
  const today = new Date();
  const birthDate = new Date(birthdate);
  let age = today.getFullYear() - birthDate.getFullYear();
  const monthDiff = today.getMonth() - birthDate.getMonth();
  if (
    monthDiff < 0 ||
    (monthDiff === 0 && today.getDate() < birthDate.getDate())
  ) {
    age--;
  }
  return age;
}

function updateAge() {
  const birthdate = $(this).val();
  const age = birthdate ? calculateAge(birthdate) : "mm";
  $("#age").val(age);
}

function style_inputs(input_id, color) {
  $("#" + input_id).css({
    "border-color": color,
    "border-radius": "5px",
  });
}

function validation() {
  var message = "";
  var name = $("#name").val();
  var birth = $("#birth").val();
  var age = $("#age").val();
  var email = $("#email").val();

  var message_name = name_validation(name);
  message += message_name == "" ? "" : message_name + "\n";
  style_inputs("name", message_name == "" ? "green" : "red");

  var message_birth = birth_validation(birth);
  message += message_birth == "" ? "" : message_birth + "\n";
  style_inputs("birth", message_birth == "" ? "green" : "red");

  var message_age = age_validation(age, birth);
  message += message_age == "" ? "" : message_age + "\n";
  style_inputs("age", message_age == "" ? "green" : "red");

  var message_email = email_validation(email);
  message += message_email == "" ? "" : message_email + "\n";
  style_inputs("email", message_email == "" ? "green" : "red");

  showMessage(message);
}

function name_validation(name) {
  if (name.length == 0) {
    return "Invalid Name";
  }
  for (let char of name) {
    if (!/[a-zA-Z]/.test(char)) return "Invalid Name";
  }
  return "";
}

function birth_validation(birthdate) {
  var today = new Date();
  var date = new Date(birthdate);
  if (birthdate == null) {
    return "Invalid Birthdate";
  }
  if (today < date) {
    return "Invalid Birthdate";
  }
  return "";
}

function age_validation(age, birthdate) {
  if (age <= 0) {
    return "Invalid Age";
  } else if (age != calculateAge(birthdate)) {
    return "Invalid Age";
  }
  return "";
}

function email_validation(email) {
  if (email.length == 0) {
    return "Invalid Email";
  }
  var at = 0; // @
  var dot = 0; // .
  for (let i = 1; i < email.length - 1; i++) {
    if (dot > at) {
      return "Invalid Email";
    } else if (email[i] == "@") {
      at += 1;
    } else if (email[i] == ".") {
      dot += 1;
    }
  }
  if (dot != 1 || at != 1) {
    return "Invalid Email";
  }
  return "";
}
