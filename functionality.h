/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */
#include<iostream>
using namespace std;
//---Piece Starts to Fall When Game Starts---//

void getNext(int& n1, int& nextColor){
n1=rand()%7;
nextColor=1+rand()%7;
}

void fallingPiece(float& timer, float& delay,int& colorNum, int& n,int& n1,int& nextColor){

    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }
        if (!anamoly()){
        for(int i=0;i<4;i++){
        gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
        }
        //colorNum=1+rand()%7;
        n=n1;
        colorNum=nextColor;
       getNext(n1,nextColor);
            //int n=rand()%7;
            //--- Un-Comment this Part When You Make BLOCKS array---//
            
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                }
            
        }
        else
        timer=0;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

void move(int x){
bool allow=1;
if(x>0){
for(int i=0;i<4;i++){
if(point_1[i][0]+1>=N){
allow=0;
}
}

if(allow){

for(int i=0;i<4;i++)
point_1[i][0]+=1;
}
}

else if(x<0){
for(int i=0;i<4;i++){
if(point_1[i][0]==0){
allow=0;
}
}

if(allow){

for(int i=0;i<4;i++)
point_1[i][0]-=1;
}
}
}

//---------------------------------------------------------------------------------

void clearLines(int& numScore){
	int row=0;
	for(int i=M-1; i>0; i--){  			//search row by row
		bool full=true;

		for(int j=0;j<N;j++){ 		//iterating through each col
			if(!(gameGrid[i][j]))
				full=false; 		 //will go false even if one value is zero
			}
			if(full)  {			//works only if none goes false
				row=i;
				numScore+=10;
			}
					}
					
	for(int i=row; i>0;i--){ 				//shift all rows above
		for(int j=0;j<N;j++){ 			//iterate through each col
		
			gameGrid[i][j]=gameGrid[i-1][j]; //bring one row down starting from the row with full blocks
			
					}
				}
			}
			

//--------------------------------------------------------------

void rotation(bool n,int shape){
bool allow=1;
	if(n){
		int py=point_1[1][1];
		int px=point_1[1][0];
for(int i=0;i<4;i++){
if(point_1[i][0]>=N-1 && (shape==0 ||shape==4 ||shape==5)){
allow=0;
}
if(point_1[i][0]==0 && (shape==0 ||shape==4 ||shape==5)){
allow=0;
}
}

if(allow){
		for(int i=0;i<4;i++){
			int x=point_1[i][1]-py;
			int y=point_1[i][0]-px;

			point_1[i][0]=px-x;
			point_1[i][1]=py+y;
					}
					}
	}
	
					
		}
	
	
//--------------------------------------------------------------

void restart(bool reset){
if(reset){

for(int i=0;i<M;i++){
for(int j=0;j<M;j++){
gameGrid[i][j]=0;
}
}
numScore=0;
}
}
//----------------------------------------------------------
void gameOver(){
for(int j=0;j<N;j++){
if(gameGrid[0][j]!=0)
restart(1);

}
}
//-------------------------------------------
void hardFall(bool jump){
if(jump){
int rows=M-point_1[3][1]-1;
for(int j=1;j<=rows;j++){
if((anamoly())){
for(int i=0;i<4;i++){
	point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;  
}
}
}


}
}
//-------------------------------------------
void make_shadow(){
int rows=M-point_1[3][1]-1;

for(int i=0;i<M;i++){
for(int j=0;j<2;j++){
cout<<"bye";
}
}

for(int j=0; j<rows;j++){
if(anamoly())
for(int i=0; i<4;i++){
shadow[i][0]=point_1[i][0];
shadow[i][1]=point_1[i][1]+rows;
}
}
}

//-----------------------------------------------

///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
