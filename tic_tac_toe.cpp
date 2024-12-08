#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;


int box[3][3] = {

   {0, 0, 0} ,
   {0, 0, 0} ,
   {0, 0, 0}
};




//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////draw
//////////////////////////////////////////////////////////////////////
void draw(void){


	for (int j=0;j<=2;j++){



		cout <<"   #   #\n";
		for(int i = 0; i <=2; i++) {



			cout <<' ';
			//X and O setter
			if(box[i][j]==0)
				cout <<' ';
			else if (box[i][j]==1)
				cout <<"O";
			else
				cout <<"X";

				cout<<' ';
			if (i!=2)
				cout <<'#';



		}
		cout <<"\n   #   #\n";
		if (j!=2)
		cout <<"###########\n";


	}
	cout<<"\n_________________________________________\n\n";




}//draw

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////winner
//////////////////////////////////////////////////////////////////////

bool winner(){

	if(box[0][0]!=0 && box[0][1]==box[0][0] && box[0][1]==box[0][2]){return true;}
	else if(box[1][0]!=0 && box[1][0]==box[1][1] && box[1][1]==box[1][2]){return true;}
	else if(box[2][0]!=0 && box[2][0]==box[2][1] && box[2][1]==box[2][2]){return true;}
	else if(box[0][0]!=0 && box[0][0]==box[1][0] && box[1][0]==box[2][0]){return true;}
	else if(box[0][1]!=0 && box[0][1]==box[1][1] && box[1][1]==box[2][1]){return true;}
	else if(box[0][2]!=0 && box[0][2]==box[1][2] && box[1][2]==box[2][2]){return true;}
	else if(box[0][0]!=0 && box[0][0]==box[1][1] && box[2][2]==box[1][1]){return true;}
	else if(box[0][2]!=0 && box[0][2]==box[1][1] && box[2][0]==box[1][1]){return true;}
	return false;

}//winner

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////pc
////////////////////////////////////////////////////////////////////

void pc(int player,int chose){

	int check;


//winning?
	for (int i=0;i<=2;i++){

		for (int j=0;j<=2;j++){
			if (box[i][j]==0){
				box[i][j]=player;
				if (winner()){return;}
				else
					box[i][j]=0;
			}
		}
	}





//losing?
	for (int i=0;i<=2;i++){

		for (int j=0;j<=2;j++){
			if (box[i][j]==0){
				box[i][j]=(player%2)+1;
				if (winner()){
					box[i][j]=player;return;}
				else{
					box[i][j]=0;
				}
			}
		}
	}
	//attack
	if (player==1){

//*
		if(box[0][0]==(player%2)+1||box[2][2]==(player%2)+1){

			 check=chose%2;
			for(int i=0;i<=1;i++){
				switch(check){
				case 0:

					if (box[0][2]==0){box[0][2]=player;return;}
					break;
				case 1:
					if (box[2][0]==0){box[2][0]=player;return;}
					break;
				}
				check=(check+1)%2;
			}



		}
		else if(box[0][2]==(player%2)+1||box[2][0]==(player%2)+1)
		{

			check=chose%2;
			for(int i=0;i<=1;i++){
				switch(check){
				case 0:
					if (box[0][0]==0){box[0][0]=player;return;}
					break;
				case 1:
					if (box[2][2]==0){box[2][2]=player;return;}
					break;
				}
				check=(check+1)%2;
			}
		}
		else {


			check=chose%4;
			for(int i=0;i<=3;i++){
				switch(check){
				case 0:

					if (box[0][2]==0){box[0][2]=player;return;}
					break;
				case 1:
					if (box[2][0]==0){box[2][0]=player;return;}
					break;
				case 2:
					if (box[0][0]==0){box[0][0]=player;return;}
					break;
				case 3:
					if (box[2][2]==0){box[2][2]=player;return;}
					break;
				}
				check=(check+1)%4;
			}
		}



//middle
		if (box[1][1]==0){box[1][1]=player;return;}
//+
			check=chose%4;
			for(int i=0;i<=3;i++){
				switch(check){
				case 0:
					if (box[1][2]==0){box[0][2]=player;return;}
					break;
				case 1:
					if (box[1][0]==0){box[2][0]=player;return;}
					break;
				case 2:
					if (box[0][1]==0){box[0][0]=player;return;}
					break;
				case 3:
					if (box[2][1]==0){box[2][2]=player;return;}
					break;
				}
				check=(check+1)%4;
			}
	}//attack
//defence
	if(player==2){

//middle
		if(box[1][1]==0){box[1][1]=player;return;}
//+
		check=chose%4;
		for(int i=0;i<=3;i++){
					switch(check){
					case 0:
						if (box[1][2]==0){box[1][2]=player;return;}
						break;
					case 1:
						if (box[1][0]==0){box[1][0]=player;return;}
						break;
					case 2:
						if (box[0][1]==0){box[0][1]=player;return;}
						break;
					case 3:
						if (box[2][1]==0){box[2][1]=player;return;}
						break;
					}
					check=(check+1)%4;
				}
//*
						check=chose%4;
				for(int i=0;i<=3;i++){
					switch(check){
					case 0:
						if (box[0][2]==0){box[0][2]=player;return;}
						break;
					case 1:
						if (box[2][0]==0){box[2][0]=player;return;}
						break;
					case 2:
						if (box[0][0]==0){box[0][0]=player;return;}
						break;
					case 3:
						if (box[2][2]==0){box[2][2]=player;return;}
						break;

					}
					check=(check+1)%4;
				}

	}//defence

}//pc









////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////main
////////////////////////////////////////////////////////////////////


int main(){

	int gamemode,firstplayer,move,chose;
	string gamers[2];



	//in this program game will be choeseing who will start first.
	////////////////////////////////////////////////////////////////////randome the players
	srand(time(NULL));
	chose= rand();
	firstplayer= chose%2;


//////////////////////////////////////////////////////////////////guide and game mode
	cout <<"Hello, welcome to tic tak toa game.\n"
			"Please enter your game mode:\n\n"
			"1-player vs player\n"
			"2-player vs pc\n\n";

	cin >>gamemode;
	while (gamemode!=1 && gamemode!=2){
		cout<< "selected game mode is wrong.\n";
		cin >>gamemode;
	}




	cout<<"Here is a guide. \nchose your number and it will be filled.\n"
		"   #   #\n"
		" 1 # 2 # 3\n"
		"   #   #\n"
		"###########\n"
		"   #   #\n"
		" 4 # 5 # 6\n"
		"   #   #\n"
		"###########\n"
		"   #   #\n"
		" 7 # 8 # 9\n"
		"   #   #\n\n\n\n";



		if (gamemode==1){

			cout <<"Please enter players name:\n";
			cin >> gamers[firstplayer] >> gamers[((firstplayer)+1)%2];
			cout<< "player1 "<<gamers[0]<<endl;
			cout<< "player2 "<<gamers[1]<<endl;



		}
		else{
			cout <<"Please enter player name:\n";

			cin >> gamers[firstplayer];
			gamers[((firstplayer)+1)%2]="pc";
			cout<< "player1 "<<gamers[0]<<endl;
			cout<< "player2 "<<gamers[1]<<endl;


		}


		/////////////////////////////////////////////////////////////////game brain


		for(int i=1;i<=9; i++){
			//player1
			if ((i%2)==1){
				if (gamers[0]=="pc"){

					//pc brain
					pc(1,chose);
					cout<<"pc took a move.\n";


				}
				else{
					cout <<gamers[0]<<" please enter your move.\n";
					REPEATED1 :
					cin >>move;
					while (move>=10 || move<=0){
						cout <<"Your number is wrong!\nPlease enter your number again.\n";
						cin>>move;
					}

					if ((move==1||move==2||move==3)&&box[move-1][0]==0){box[move-1][0]=1;}
					else if ((move==4||move==5||move==6)&&box[move-4][1]==0){box[move-4][1]=1;}
					else if(box[move-7][2]==0) {box[move-7][2]=1;}
					else {
						cout<<"This box is filled, please enter a new number.\n";
						goto REPEATED1;
					}



				}


				draw();
				if(i>=5){
					if (winner()){
					cout <<"the winner is "<<gamers[0]<<"!\n";
						break;
					}

				}
			}//if
			else{



				//player2
				if (gamers[1]=="pc"){

					//pc brain
					pc(2,chose);
					cout<<"pc took a move.\n";

				}
				else{
					cout <<gamers[1]<<" please enter your move.\n";
					REPEATED2:
					cin >>move;

					while (move>=10 || move<=0){
					cout <<"Your number is wrong!\nPlease enter your number again.\n";
					cin >>move;
					}

					if ((move==1||move==2||move==3)&&box[move-1][0]==0){box[move-1][0]=2;}
					else if ((move==4||move==5||move==6)&&box[move-4][1]==0){box[move-4][1]=2;}
					else if(box[move-7][2]==0) {box[move-7][2]=2;}
					else {
						cout<<"This box is filled, please enter a new number.\n";
						goto REPEATED2;
					}
				}


				draw();
				if(i>5){
					if (winner()){
						cout <<"the winner is "<<gamers[1]<<"!\n";
						break;

					}
				}

		}//for
		if(!winner())cout<<"this mach is draw and has no winner!";
	}







	return 0;
}//main








