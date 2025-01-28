float K = 0.05;
float friction = 0.85;
int numTypes = 6;
int colourStep = 360/numTypes;
int numParticles = 1000;
ArrayList<particle> particles;

float[][] forces;
float[][] minDistance;
float[][] radii;

void setup(){
  fullScreen();
  frameRate(120);
  colorMode(HSB,360,100,100); 
  noStroke();
  particles = new ArrayList<particle>();
  for(int i = 0; i < numParticles; i++){
    particles.add(new particle());
  }
  forces = new float[numTypes][numTypes];
  minDistance = new float[numTypes][numTypes];
  radii = new float[numTypes][numTypes];
  randomMatrix();
  print("Forces: ");
  printMatrix(forces);
  print("minDistance: ");
  printMatrix(minDistance);
  print("radii: ");
  printMatrix(radii);
}

void draw(){
  background(0);
  for(particle p: particles){
    p.update();
    p.display();
  }
}

void keyPressed(){
 randomMatrix(); 
  print("Forces: ");
  printMatrix(forces);
  print("minDistance: ");
  printMatrix(minDistance);
  print("radii: ");
  printMatrix(radii);
}

void printMatrix(float[][] matrix){
  for(int i = 0; i < numTypes; i++){
    println();
    for(int j = 0; j < numTypes; j++){
      print(matrix[i][j] + " ");
    }
  }
  println();
  println();
}

void randomMatrix(){
  for(int i = 0; i < numTypes; i++){
    for(int j = 0; j < numTypes; j++){
      forces[i][j] = random(0.3,1.0);
      if(random(100) < 50){
        forces[i][j] *= -1;
      }
      minDistance[i][j] = random(60,100);
      radii[i][j] = random(240,620);
    }
  }
}
