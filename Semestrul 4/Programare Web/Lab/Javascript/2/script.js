

function showMessage(message) {
    if (message == "")
        alert("Everything GOOD!")
    else alert(message)
}

function calculateAge(birthdate) {
    const today = new Date();
    const birthDate = new Date(birthdate);
    let age = today.getFullYear() - birthDate.getFullYear();
    const monthDiff = today.getMonth() - birthDate.getMonth();
    if (monthDiff < 0 || (monthDiff === 0 && today.getDate() < birthDate.getDate())) {
        age--;
    }
    return age;
}

// Function to update age input field
function updateAge() {
    const birthdateInput = document.getElementById('birth');
    const ageInput = document.getElementById('age');
    const birthdate = birthdateInput.value;
    if (birthdate) {
        const age = calculateAge(birthdate);
        ageInput.value = age;
    } else {
        ageInput.value = 'mm';
    }
}

function style_inputs(input_id, color) {
    var element = document.getElementById(input_id);
    element.style.borderColor = color;
    element.style.borderRadius = "5px";
}


function validation() {

    var message = ""

    var name = document.getElementById("name");
    var birth = document.getElementById("birth");
    var age = document.getElementById("age");
    var email = document.getElementById("email");

    var message_name = name_validation(name.value);
    if(message_name == "") 
        style_inputs("name", "green");
    else 
        style_inputs("name", "red")

    var message_birth = birth_validation(birth.value);
    if(message_birth == "") 
        style_inputs("birth", "green");
    else 
        style_inputs("birth", "red")

    var message_age = age_validation(age.value, birth.value);
    if(message_age == "") 
        style_inputs("age", "green");
    else 
        style_inputs("age", "red")

    var message_email = email_validation(email.value);
    if(message_email == "") 
        style_inputs("email", "green");
    else 
        style_inputs("email", "red")

    showMessage(message_name + message_birth + message_age + message_email);

}

function name_validation(name) {
    if(name.length == 0) {
        return "Invalid Name \n";
    }
    for(let char of name) {
        if(/[a-zA-Z]/.test(char) == false)
            return "Invalid Name \n";
    }
    return "";
}

function birth_validation(birthdate) {
    var today = new Date();
    var date = new Date(birthdate.toString());
    if(birthdate == null) {
        return "Invalid Birthdate \n";
    } 
    if(today < date) {
        return "invalid Birthdate \n";
    }
    return "";
}

function age_validation(age, birthdate) {
    if(age <= 0) {
        return "Invalid Age\n";
    } else if(age != calculateAge(birthdate)) {
        return "Invalid Age\n";
    }
    return "";
}

function email_validation(email) {
    if(email.length == 0) {
        return "Invalid Email\n";
    } 
    at = 0; // @
    dot = 0; // .
    for(let i = 1; i < email.length -1; i++) {
        if(dot > at) {
            return "Invalid email\n";
        } else if(email[i] == '@') {
            at += 1;
        } else if (email[i] == '.') {
            dot += 1;
        }
    }
    if(dot != 1 || at != 1) {
        return "Invalid email\n";
    }
    return "";
}



