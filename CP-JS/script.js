function clickme() {
    var year = prompt("In Which Year you were bron");
    var month = prompt("In Which month you were bron from 1 to 12");
    var day = prompt("On Which Day you were bron");
    var age, totaldays;
    switch (month)
    {
        case '1': totaldays = 31-day;
        age = ((2021-year)*365 )+ totaldays + (365-31);
        break;
        case '2': totaldays = 28-day;
        age = (2021-year)*365 + totaldays + (365-59);
        break;
        case '3': totaldays = 31-day;
        age = (2021-year)*365 + totaldays + (365-90);
        break;
        case '4': totaldays = 30-day;
        age = (2021-year)*365 + totaldays + (365-120);
        break;
        case '5': totaldays = 31-day;
        age = (2021-year)*365 + totaldays + (365-151);
        break;
        case '6': totaldays = 30-day;
        age = (2021-year)*365 + totaldays + (365-181);
        break;
        case '7': totaldays = 31-day;
        age = (2021-year)*365 + totaldays + (365-212);
        break;
        case '8': totaldays = 31-day;
        age = (2021-year)*365 + totaldays + (365-243);
        break;
        case '9': totaldays = 30-day;
        age = (2021-year)*365 + totaldays + (365-273);
        break;
        case '10':totaldays = 31-day;
        age = (2021-year)*365 + totaldays + (365-304);
        break;
        case '11': totaldays = 30-day;
        age = (2021-year)*365 + totaldays + (365-334);
        break;
        case '12': totaldays = 31-day;
        age = (2021-year)*365 + totaldays;
        break;
        default : age = 0;
    }
    var result = document.createElement('h2');
    var textA = document.createTextNode('You are '+ age +' days old');
    result.setAttribute('id','ageInDays');
    result.appendChild(textA);
    document.getElementById('flex-box-result').appendChild(result);
}

function reset (){
    document.getElementById('ageInDays').remove();
}

// Challenge 2
function catGenerator() {
    var image = document.createElement('img');
    var div1 = document.getElementById('flex-box-result-2');
    image.src ="https://ichef.bbci.co.uk/news/976/cpsprodpb/12A9B/production/_111434467_gettyimages-1143489763.jpg";
    div1.appendChild(image);
}