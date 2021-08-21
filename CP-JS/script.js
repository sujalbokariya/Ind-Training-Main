//Challenge 1
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

//Challenge 3
function rpsGame(yourChoice) {
    //console.log(yourChoice);
    var humanChoice, botChoice;
    humanChoice = yourChoice.id;
    console.log("Human Choice "+humanChoice)
    
    botChoice = botChoiceInWords(botChoiceInNo());
    console.log("Bot Choice "+botChoice);

    var result3 = rpsCal(humanChoice, botChoice);
    console.log(result3);

    var answer = rpsResultCal(result3);
    console.log(answer);
}

function botChoiceInNo() {
    return Math.floor(Math.random() * 3);
}

function botChoiceInWords(number1) {
    return ['rock','paper','scissors'][number1];
}

function rpsCal(yourChoice, computerChoice) {
    var rpsData ={
        'rock': {'scissors': 1, 'rock': 0.5, 'paper': 0},
        'paper': {'scissors':0, 'rock':1, 'paper':0.5},
        'scissors' : {'scissors':0.5, 'rock':0, 'paper':1}
    };
    var yourScore = rpsData [yourChoice][computerChoice];
    var botScore = rpsData [computerChoice][yourChoice];
    return [yourScore, botScore];
}

function rpsResultCal( [yourScore, botScore] ) {
    if (yourScore === 0) {
        return {'message': 'You Lost!', 'color': 'red'};
    } else if (yourScore === 1) {
        return {'message': 'You Won!', 'color': 'green'};
    } else {
        return {'message': 'You Tied!', 'color': 'yellow'};
    }
}
