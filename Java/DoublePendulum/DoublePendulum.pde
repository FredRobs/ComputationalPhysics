float g = 1;
float friction = 0.9975;
particle p;

void setup(){
  fullScreen();
  noStroke();
  colorMode(HSB,360,100,100); 
  p = new particle();
}

void keyPressed(){
  p.angle = random(-PI,PI);
  p.angle2 = random(-PI,PI);
  p.angularVelocity = 0;
  p.angularAcceleration = 0;
  p.angularVelocity2 = 0;
  p.angularAcceleration2 = 0;
}

void draw(){
  background(0);  
  p.update();
  p.display();
}
