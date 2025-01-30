class particle {
  float angle;
  float angularVelocity;
  float angularAcceleration;
  float angle2;
  float angularVelocity2;
  float angularAcceleration2;
  float l1 = 300;
  float l2 = 300;
  PVector origin;
  PVector bob;
  PVector origin2;
  PVector bob2;
  float m1;
  float m2;
  float colour;
  float colour2;
  
  particle(){
    m1 = 1.7;
    m2 = 0.7;
    angle = (PI);
    angularVelocity = 0;
    angularAcceleration = 0;
    origin = new PVector(width / 2,(height / 2)-(l1/2)); // Set the pivot point
    bob = new PVector(origin.x + l1 * sin(angle),origin.y + l1 * cos(angle)); 
    angle2 = PI / 3;
    angularVelocity2 = 0;
    angularAcceleration2 = 0;
    origin2 = new PVector(bob.x,bob.y); // Set the pivot 2 point
    bob2 = new PVector(origin2.x + l2 * sin(angle2),origin2.y + l2 * cos(angle2)); 
  }
  
  void display(){
    stroke(255);
    strokeWeight(2);
    colour = constrain(angle * 180/PI, -360, 360);
    line(origin.x, origin.y, bob.x, bob.y); // String
    fill(colour,100,100);
    ellipse(bob.x, bob.y, 40*(m1), 40*(m1));
    line(origin2.x, origin2.y, bob2.x, bob2.y); // String
    fill(colour,100,100);
    ellipse(bob2.x, bob2.y, 40*(m2), 40*(m2));
  }
  

  
  void update(){ 
    origin2.x = bob.x;
    origin2.y = bob.y;
    
    float part1 = (-g * (2*m1 + m2)*sin(angle));
    float part2 = (-m2 * g * sin(angle - 2 * angle2));
    float part3 = (-2 * sin(angle -angle2) * m2 * (angularVelocity2 * angularVelocity2 * l2 + angularVelocity * angularVelocity * l1));
    
    float part4 = (2 * m1 + m2 - m2 * cos(2*angle - 2*angle2));
    
    float part5 = (2 * sin(angle - angle2));
    float part6 = (angularVelocity * angularVelocity * l1 * (m1 + m2));
    float part7 = (g * (m1 + m2) * cos(angle));
    float part8 = (angularVelocity2 * angularVelocity2 * l2 * m2 * cos(angle - angle2));
    
    angularAcceleration = (part1 + part2 + part3) / (l1 * part4);
    angularAcceleration2 = (part5 * (part6 + part7 + part8)) / (l2 * part4);
    
    angularVelocity += angularAcceleration;
    angularVelocity *= friction;
    angularVelocity2 += angularAcceleration2;
    angularVelocity2 *= friction;
    
    angle += angularVelocity;
    angle2 += angularVelocity2;

    bob.x = origin.x + l1 * sin(angle);
    bob.y = origin.y + l1 * cos(angle);
    bob2.x = origin2.x + l2 * sin(angle2);
    bob2.y = origin2.y + l2 * cos(angle2);
  }
}
