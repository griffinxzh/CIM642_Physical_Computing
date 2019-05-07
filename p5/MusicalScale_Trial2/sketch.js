var button1, button2, button3, button4, button5, button6, button7, button8;
var musicalScale = ["Do", "Re", "Mi", "Fa", "Sol", "La", "Si", "Do+"];
var tone = 0;

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

class interfaces{
  //constructor: characteristics for your object
  constructor(tempX, tempY, tempS, tempC, tempName){// no limit to num of parameters

    this.x = tempX;
    this.y = tempY;
    this.size = tempS;
    this.color = tempC;
    this.name = tempName;
    this.overlay = false;

    // what inside the class won't affect what's outside the class
  }

  display(){//to draw 8 buttons

    fill(this.color);
    rect(this.x, this.y, this.size, this.size);
    text(this.name, this.x+15, this.y-7);

    if(this.overlay == true){
      fill(127,127);
      rect(this.x, this.y, this.size, this.size);
    }



  }




  checkbutton(mX,mY){
    if(mX > this.x && mX< this.x + this.size && mY >this.y && mY < this.y + this.size){
      this.overlay = true ;
      return true;
    }else {
      this.overlay = false ;
      return false;
    }
  }



}



function setup() {
  createCanvas(1200,400);

                          //posX,posY,radius,color,name
  button1 = new interfaces(100,200,50,0,"Do"); //create a new button
  button2 = new interfaces(200,200,50,0,"Re");
  button3 = new interfaces(300,200,50,0,"Mi");
  button4 = new interfaces(400,200,50,0,"Fa");
  button5 = new interfaces(500,200,50,0,"Sol");
  button6 = new interfaces(600,200,50,0,"La");
  button7 = new interfaces(700,200,50,0,"Si");
  button8 = new interfaces(800,200,50,0,"Do+");
  }




function draw() {
  background(255);
    console.log(tone);


  button1.display();
  if(button1.checkbutton(mouseX,mouseY)){
    //console.log(button1.name);
  }



  button2.display();
  if(button2.checkbutton(mouseX,mouseY)){
    //console.log(button2.name);

  }

  button3.display();
  if(button3.checkbutton(mouseX,mouseY)){
    // console.log(button3.name);
  }

  button4.display();
  if(button4.checkbutton(mouseX,mouseY)){
    // console.log(button4.name);
  }

  button5.display();
  if(button5.checkbutton(mouseX,mouseY)){
    // console.log(button5.name);
  }

  button6.display();
  if(button6.checkbutton(mouseX,mouseY)){
    // console.log(button6.name);
  }

  button7.display();
  if(button7.checkbutton(mouseX,mouseY)){
    // console.log(button7.name);
  }

  button8.display();
  if(button8.checkbutton(mouseX,mouseY)){
    // console.log(button8.name);
  }



//display pitch name
  // for(var i = 0; i < 8; i++){
  //   fill(0);
  //   textSize(16);
  //   text(musicalScale[i], i * 100 + 115, 190,);
  //
  //   // strokeWeight(0);
  //   //
  //   // rect(i * 100 + 100, 200, 50,50);
  // }

}

function keyPressed(){
  if (key == "a") {
      tone = 1;
    } else {
      tone = 0;
    }

}
