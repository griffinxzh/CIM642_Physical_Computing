var buttonArray = [];
var musicalScale = ["Do", "Re", "Mi", "Fa", "Sol", "La", "Si", "Do+"];

//load musical scale sound files
function preload(){
  soundFile = loadSound ('assets/1_Do.wav');
  soundFile = loadSound ('assets/2_Re.wav');
  soundFile = loadSound ('assets/3_Mi.wav');
  soundFile = loadSound ('assets/4_Fa.wav');
  soundFile = loadSound ('assets/5_Sol.wav');
  soundFile = loadSound ('assets/6_La.wav');
  soundFile = loadSound ('assets/7_Si.wav');
  soundFile = loadSound ('assets/8_Do+.wav');
}

function setup() {
  createCanvas(1200,400);


  for(var i = 0; i <8; i++){
    var c = color(0);
    buttonArray[i] = new interfaces(i * 100 + 100, 200, 50, c, i+1);
  }

}



function draw() {
  background(255);

  for( var i =0; i < buttonArray.length; i ++){
    buttonArray[i].display();
    if(buttonArray[i].checkbutton(mouseX,mouseY)){
      console.log(musicalScale[i]);
    //  background(buttonArray[i].color);
    }
  }
}

//create an interface class
class interfaces{
  //constructor: characteristics for your object
  constructor(tempX, tempY, tempS, tempC, tempName){  // no limit to num of parameters

    this.x = tempX;
    this.y = tempY;
    this.size = tempS;
    this.color = tempC;
    this.name = tempName;
    this.overlay = false;
    //❗️❗️
    this.activated = false;
    // what inside the class won't affect what's outside the class
  }

  display(){//to draw buttons

    fill(this.color);
    rect(this.x, this.y, this.size, this.size);
    text(this.name, this.x+20, this.y+70);

    if(this.overlay == true){
      fill(150,150);
      rect(this.x, this.y, this.size, this.size);
    }

    if(this.activated == true){
      fill("orange");
      rect(this.x, this.y, this.size, this.size);
    }

    for(var a = 0; a < 8; a++){
      fill(0);
      textSize(16);
      text(musicalScale[a], a * 100 + 115, 190,);
    }
  }



  checkbutton(mX,mY){  //to check cursor hovering area
    if(mX > this.x && mX< this.x + this.size && mY >this.y && mY < this.y + this.size){
      this.overlay = true ;
      return true;
    }else {
      this.overlay = false ;
      return false;
    }
  }

//❗️❗️TBC, to check the key pressed
    checkKey(){
      if(keyCode == UP_ARROW){
        this.activated = true;
        return true;
      }else{
        this.activated = false;
        return false;
      }

    }



}





// function keyPressed(){
//   if (keyCode === 1){
//     fill
//   }
//
//
//
//
//
// }
