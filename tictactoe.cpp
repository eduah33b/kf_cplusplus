#include <iostream>
#include <string>

using namespace std;

string gm [9] = {".", ".", ".", ".", ".", ".", ".", ".", "."};
char gma [9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
string ap[9] = {"0","0","0","0","0","0","0","0","0"};
string pnm[2];

void printg()
{
	int b = 0;
     cout<<endl;
     for (int a = 0; a < 9;a++)
     {
		cout << "\t" <<gm[a] << "\t";
		if ((a % 3) == 2)
		{
			cout <<"\t\t\t\t";
			while(b < 9)
			{ 
				cout << "\t" <<gma [b] << "\t";
				b++;
				if ((b % 3) == 0)
				{
					cout <<"\n\n\n\n\n\n";
					break;
				}
			}
		}
     }
     cout<<endl;
}

int chkwin(string a)
{
	if(gm[0] == a && gm[1] == a && gm[2] == a)
		return 1;
	if(gm[3] == a && gm[4] == a && gm[5] == a)
		return 1;
	if(gm[6] == a && gm[7] == a && gm[8] == a)
		return 1;
	if(gm[0] == a && gm[4] == a && gm[8] == a)
		return 1;
	if(gm[0] == a && gm[3] == a && gm[6] == a)
		return 1;
	if(gm[1] == a && gm[4] == a && gm[7] == a)
		return 1;
	if(gm[2] == a && gm[5] == a && gm[8] == a)
		return 1;
	if(gm[2] == a && gm[4] == a && gm[6] == a)
		return 1;
	return 0;
}

int input(int b)
{
	string pp;
	int c = 0, w = 0, opl, pl;
	while( c < 2)
	{
		printg();
		w = chkwin(pp);
		if (w == 1)
		{
			cout << pp << " wins game!" << endl;
			return w;
		}
		
		pp = pnm[c];
		
		if(b > 3)
		{					
			cout << "\nMake your move player " << pp << endl << "Select the number you want to move." <<endl;
			cin >> opl;
			if(ap[--opl] != pp)
			{
				cout <<"Wrong input player " << pp << ". You have no dice there.\n";
				continue;
			}
			cout << "Select the number you want to move it to." <<endl;
			cin >> pl;
			
			if (pl < 1 || pl > 9 && opl < 1 || opl > 9)
			{
				   cout <<"Wrong input player " << pp << ". Please enter an integer from 1 to 9\n";
				   continue;
			}
			if(ap[--pl] != "0")
			{
					  cout << "That position has alredy benn filled by player " << ap[pl] << endl;
					  continue;
			}
			
			if((pl+1) == (opl -2) || (pl+1) == (opl + 4) || (pl+1) == (opl + 2) || (pl+1) == opl )
			{
				ap[pl] = pp;
				gm[pl] = pp;
				ap[opl] = "0";
				gm[opl] = ".";
			}else
			{
				if(opl==4 || pl == 4)
				{
					ap[pl] = pp;
					gm[pl] = pp;
					ap[opl] = "0";
					gm[opl] = ".";
				}else
				{
					continue;
				}
			}
		}else
		{				
			cout << "\nMake your move player " << pp <<endl;
			cin >> pl;
			
			if (pl < 1 || pl > 9)
			{
				   cout <<"Wrong input player " << pp << ". Please enter an integer from 1 to 9\n";
				   continue;
			}
			if(ap[--pl] != "0")
			{
				  cout << "That position has alredy benn filled by player " << ap[pl] << endl;
				  continue;
			}
			ap[pl] = pp;
			gm[pl] = pp;
		}
		
		w = chkwin(pp);
		if (w == 1)
		{
			cout << pp << " wins the game!" << endl;
			return w;
		}
		c++;
	}
}

void inpt ()
{
    int b = 1;
    int wn = 0;
	for(int i = 0; i < 2;i++)
	{
		cout<<"\nPlayer " << (i+1) << " enter initials\n";
		cin >> pnm[i];
	}
     while(wn != 1)
     {
            cout << "\nRound " << b << endl;
            wn = input(b);
            b++;
     }
}

int main(int argc, char *argv[])
{
    inpt();
    printg();
    cout <<"\n\n\nGame over\n\n";
    return 0;
}
