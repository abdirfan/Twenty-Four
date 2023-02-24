//Program 1: TwentyFour
//Course: CS 211, Spring 2023, UIC
//System: Replit
//Name: Abdullah Irfan

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//outputs the welcome statements
void welcomeDisplay() {
  printf("Welcome to the Game of Twentyfour.");
  printf("Use each of the four numbers shown below exaclty once,");
  printf("combining them somehow with the basic mathematical operators(+, -, *, /)");
  printf("to yield the value twenty-four");
}

//performs calculations based on the operator selected by the user
double calculate(double numOne,char operator,double numTwo){
  if(operator == '+'){
    return numOne + numTwo;
  }
  else if(operator == '-'){
    return numOne - numTwo;
  }
  else if(operator == '*'){
    return numOne*numTwo;
  }
  else if(operator == '/'){
    return numOne/numTwo;
  }
  else {
      printf("Error! Invalid operator\n");
  }

  return 0.0;
}

void easyModeFunc(){
  double easyArray[10][4] = {{3, 9, 4, 1}, {8, 5, 8, 1}, {6, 1, 5, 1}, {2, 8, 7, 8}, {5, 2, 9, 2}, {2, 6, 8, 4}, {5, 5, 4, 3}, {6, 6, 2, 6}, {8, 4, 2, 6},{6, 2, 8, 1},};

  char input[10];
  int index;
  double numOne,numTwo,numThree,numFour;
       
  index = rand()%10;
       numOne = easyArray[index][0];
       numTwo = easyArray[index][1] ;
       numThree = easyArray[index][2] ;
       numFour = easyArray[index][3] ;
  
}

void hardModeFunc (){

  double allPuzzles[3188][4];
  char operators[4] = {'+','-','*','/'};
  int index = rand()%3188; 
  double numOne,numTwo,numThree,numFour;

  
       numOne = allPuzzles[index][0];
       numTwo = allPuzzles[index][1] ;
       numThree = allPuzzles[index][2] ;
       numFour = allPuzzles[index][3] ;
}

//get arguments for the debug mode, code was sourced from lab 2
void getArg(int  argc,char  *argv[],int *easyMode, int* debugMode)   {
			while ( (argc -= 2) > 0)  {	    // while there is another pair of strings 
				if (argv[ 1][ 0] == '-')	{
          switch (argv[ 1][1]) {		
	      			case 'e':  //e refers to easymode, and when selected it engages easy mode
							*easyMode = atoi(argv[2]); //converts a character string to an integer value
							break;
					    case 'd': //d refers to easymode, and when selected it engages debug mode
							*debugMode = atoi(argv[2]);  //converts a character string to an integer value
							break;
					default:
							break;
				} 
      }
				argv += 2;			
		} 
	} 





// generates all possible solutions of numbers from 1 to 9, gets recalled in main
void findSolutions(double allPuzzles[3188][4],char operators[4],int *debug){

  //three variables to store each computation
  double solOne;
  double solTwo;
  double solThree;

  int count=0; // keep tract of the number of solutions generated
  // finalResult results for each computation
  // looping for possible first numbers 
  for(double i=1;i<10;i++){
    // looping for possible second numbers 
    for(double j=1;j<10;j++){
      // looping for possible third numbers  
      for(double k =1;k<10;k++){
        // looping for possible fourth numbers
        for(double l=1;l<10;l++){
          // looping for possible operators between first two numbers
          for(int a =0;a<4;a++){
            solOne = calculate( i, operators[a],  j); 
            //looping for possible operators between the solOne and third number
            for(int b=0;b<4;b++){
              solTwo = calculate(solOne,  operators[b], k );
              // looping for possible operators between the solTwo and the fourth number
              for(int c=0;c<4;c++){
                solThree = calculate(solTwo,operators[c],l); //uses calculate funtion to compute the all possible results

                // checking if the result of calculations is 24
                if(((solThree- 24.0)<0.001) &&((solThree-24.0 )>=0)){
                  // the array with the numbers if solvable
                  allPuzzles[count][0] =i; 
                  allPuzzles[count][1] =j;
                  allPuzzles[count][2] =k;
                  allPuzzles[count][3] =l;
                  ++count;
                  
                  // checking if the debug mode is on then print all the solutions
                  if(*debug == 1){
                    printf("%d. %d%c%d%c%d%c%d\n",count,(int)i,operators[a],(int)j,operators[b],(int)k,operators[c],(int)l);
                  }
                  
                }
              }
            }
          }
        }
      }
    }
  }
}


int main(int argc,char *argv[]) {
  
  srand(1);	 //sets the starting point for producing a series of pseudo-random integers
  
  welcomeDisplay();
  
  double allPuzzles[3188][4];
  char operators[4] = {'+','-','*','/'};
  double easyArray[10][4] = {{3,9,4,1},{8,5,8,1},{6,1,5,1},{2,8,7,8},{5,2,9,2},{2,6,8,4},{5,5,4,3},{6,6,2,6},{8,4,2,6},{6,2,8,1}};
	int debugMode = 0;  // 0 refers to default debug mode is off
  int easyMode = 1;  // 1 refers to default easy mode is on

  // geting special arguments from the console
  getArg(argc,argv,&easyMode,&debugMode); 
  // generate all solutions 
  findSolutions(allPuzzles,operators,&debugMode);
  int notValid = 0; 
  int calcOne = 0;
  int calcTwo = 0;
  int finalCalc = 0;
  int game = 1;


  
  while(game != 0){
    char keepPlaying;
    char input[10];
    
    double numOne,numTwo,numThree,numFour;
    if(easyMode == 1){
     
       int index = rand()%10;
       numOne = easyArray[index][0];
       numTwo = easyArray[index][1] ;
       numThree = easyArray[index][2] ;
       numFour = easyArray[index][3] ;
    }
    if(easyMode == 0){
      
       int index = rand()%3188; 
       numOne = allPuzzles[index][0];
       numTwo = allPuzzles[index][1] ;
       numThree = allPuzzles[index][2] ;
       numFour = allPuzzles[index][3] ;
    }
      
      
      printf("The numbers to use are: %d, %d, %d, %d.\n",(int)numOne,(int)numTwo,(int)numThree,(int)numFour);
      printf("Enter the three operators to be used, in order (+,-,*, or /): ");
      scanf("%s",input);

    //checking if the length of the string 
    if(strlen(input)!=3){
      printf("Error! The number of operators is incorrect. Please try again.\n");
      continue; 
    }
    //checking if operators are valid
    for(int i=0;i<3;i++){
      if(input[i]=='+'||input[i]=='*'||input[i]=='-'||input[i]=='/'){
         notValid = 0;
      }else{
        notValid=1; 
      }
    }
    if (notValid == 1){
      printf("Error! Invalid operator entered. Please try again.\n");
      continue; 
    }
    //calculate the first line
    calcOne = calculate(numOne, input[0], numTwo);
    calcTwo = calculate(calcOne, input[1], numThree);
    finalCalc = calculate(calcTwo, input[2],  numFour);

    // print the output
    printf("%d %c %d = %d.\n",(int)numOne,input[0],(int)numTwo,calcOne);
    printf("%d %c %d = %d.\n",calcOne,input[1],(int)numThree,calcTwo);
    printf("%d %c %d = %d.\n",calcTwo,input[2],(int)numFour,finalCalc);
    // check if result is 24
    if(finalCalc == 24){
      printf("Well done! You are a math genius.\n\n"); 
    }else{
      printf("Sorry. Your solution did not evaluate to 24.\n"); 
    
    }
    printf("Would you like to play again? Enter N for no and any other character for yes.\n");
      
    scanf("%s",&keepPlaying);
    // stop playing if input is 'N'
    if(keepPlaying == 'N'){
      game = 0;  
    }
    
    
  }
  printf("Thanks for playing!\n");
  return 0;
  
}


  
