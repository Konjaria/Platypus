#include <iostream>
#include <time.h>
#include <conio.h>
#include <string>
//preprocessors
//const ( roughly means "I promise not to change this value" we're going to access the private 
char random_characters_generator()
{
	srand(time(NULL));
	return  rand() % 26 +'A';
} //useful for randomly setting the name of hatched Platypuses
char gender_generator()
{
	char genderInitializer[] = { 'm','f' };
	srand(time(NULL));
	int index = rand() % 2 + 0;
	return genderInitializer[index];
}//useful for tandomly generate the gender of hatched platypuses
double randomnumber(float LowerBound, float UpperBound) {
	srand(time(NULL));
	float random_Number = (float)rand() / RAND_MAX;

	return LowerBound + random_Number * (UpperBound - LowerBound);
}
class Platypus
{
private:
	float Weight_of_Platypus;//in grammes 
	short Age;//defined in months
	char NameInitial;//Firstname Initial
	char Gender;//male or female initial m -> male f ->  female
	bool Alive;//alive or dead if the platypus is alive we can write  Alive = true else Alive=false
	bool Mutant;//is mutant or not if the platypus is  mutant we can write Mutant =true else Mutant=false
public:
	Platypus() :Alive(false) {}//constr for dead platypus
	Platypus(float weight, short age, char name, char gender, bool alive=true, bool mutant=false)
	{
		if (weight < 0 || weight > 1500 || age < 0 || age > 20 || (gender != 'm' && gender != 'f' && gender != 'M' && gender != 'F'))
		{
			std::cerr << "\n\t Such type of Platypus doesn't exists \n\t  .....  Platypus is needed to be hatched  ..... " << std::endl;
			this->Alive = false; this->Weight_of_Platypus = 1;
			this->Age = 100; this->NameInitial = 'X';
			this->Gender = 'X'; this->Mutant = true;
		}
		else
		{
			this->Weight_of_Platypus = weight;	this->Age = age;
			this->NameInitial = name;		this->Gender = gender;
			this->Alive = alive;	this->Mutant = mutant;
		}
	}
	//explicit value constr with parameters according to the instruction
	
	//getter functions gives us the possibility to access the private data members
	short getage()const             { return Age;                        }
	char getnameinitial() const     { return NameInitial;                }
	float getweight()const          { return Weight_of_Platypus;         }
	char getgenderInitial()const    { return Gender;                     }
	bool isalive () const           { return Alive;                      }
	bool ismutant () const          { return Mutant;                     }
	//setter functions - mutators - gives us the possibility to modify contents of private data  memebrs
	void setweight(float weight)	{ this->Weight_of_Platypus = weight; }
	void setage   (short age )		{ this->Age = age;                   }
	void setname(char nameinit)		{ this->NameInitial = nameinit;      }
	void setgender(char genderinit) { this->Gender = genderinit;         }
	void setalive(bool alive)		{ this->Alive = alive;               }
	void setmutant(bool mutant)		{ this->Mutant= mutant;              }

	void Print()const 
		// the attributes of that platypus printed out with calling this function
	{
		//=============================================================
		// 
		//                     checking conditions 
		// e.i. if the Platypus is not checked ther is not any kind of an information 
		// we could know about him/her
		// 
		//=============================================================
		if (Alive == false &&  Weight_of_Platypus < 0 && Weight_of_Platypus >1500)
		{
			std::cout << "\n\tThe Platypus is not hatched yet or doesn't exists " << std::endl;
		}
		else
		{
			std::cout << "\n\t\t Attributes  \n";
			std::cout << " \t================================== \n " ;
			std::cout << "\n\tThe Name Initial       : " << getnameinitial() << std::endl;
			std::cout << "\n\tAlive                  : ";
			if (isalive() == true)
			{
				std::cout << "Yes" << std::endl;
			}
			else
			{
				std::cout << "No" << std::endl;
			}
			std::cout << "\n\tWeight                 : " << getweight() << " Pound(s)" << std::endl;
			std::cout << "\n\tAge(in Months)         : " << getage() << " Month(s) " << std::endl;
			std::cout << "\n\tGender                 : ";
			if (getgenderInitial() == 'm' || getgenderInitial() == 'M')
			{
				std::cout << "Male" << std::endl;
			}
			else if (getgenderInitial() == 'f' || getgenderInitial() == 'F')
			{
				std::cout << "Female" << std::endl;
			}
			std::cout << "\n\tMutant                 : ";
			if (ismutant() == true)
			{
				std::cout << "Yes" << std::endl;
			}
			else
			{
				std::cout << "No" << std::endl;
			}
			std::cout << "\n\t================================== \n "; 
		}
				
	}
	void age_me(short age)
	{
		double chance_mutant = 0;
		
		//===========================================
		//upward we mentioned that the age is considered by the month
		//so 0 month means that the platypus is  already dead
		//===========================================
		if (Age < 0)
			std::cerr << " \n \t Age incrementation Failed \n\t Reason :  Such Type of Platypus Doesn't Exist " << std::endl;
		else
		{
			double chance_killing = Weight_of_Platypus * 10;
			this->Age += age;//it is the same as this->Age=Age+age; binary operator
			chance_mutant += 0.02;//0+0.02=0.02 chance to  become mutant  is incrementing ;
			std::cout << "\n\t If you know the Background Story "
				<< "\n\tThen You can  say that the incrementing of the age  manually is possible obviously "
				<< "\n\t\t However ..... it has some disadvantages \n";
			std::cout << "\t**********************************************************************" << std::endl;
			std::cout << " \t\tThe chances of  the Platypus with name initial of " << getnameinitial() << std::endl;
			std::cout<< "\t\t... Possibility of becoming Mutant  : " << chance_mutant*100<<" %";
			if (this->Weight_of_Platypus >= 10)
			{
				chance_killing == 100;
				std::cout << "\t\t we are going to consider the platypus as dead  " << std::endl;
				std::cout << "\n\n\t ===================================================================== \n " << std::endl;
				std::cout << "\n\t  I think that Everyone deserves to live even with 100% chance of killing and  excess mass should not be our Destiny \n Unfortunately the life is cruel for such fat Platypuses " << std::endl;
			}
			else
			{
				 std::cout << "\t\t... Possibility of becoming dead  : " << chance_killing*100<<" %";
			}
		}
	}//chance to become dead and etc some impelmentations 
	Platypus& fight(Platypus& other)
	{
		float fight_ratio = (Weight_of_Platypus / other.Weight_of_Platypus) * 50;
		int randomnumber = rand() % 100 + 1;//i could use my function upward but it is more convenient in this case i think
		std::cout << "\n\t===========================  Battle Between  Platypuses  ===========================" << std::endl;
		if (this->Alive == true && other.Alive == true)
		{
			if (fight_ratio > randomnumber)
			{
				std::cout << "\n\tThe Platypus called : " << this->getnameinitial() << " Is winner in this Battle " << std::endl;
				Print();
				return *this;
			}
			else
			{
				std::cout << "\n\tThe Platypus called : " << other.getnameinitial() << " Is winner in this Battle " << std::endl;
				other.Print();
				return other;
			}
		}
		else if (this->Alive == true && other.Alive == false) {
			std::cout << "\n\tPlatypus called " << this->getnameinitial() << " is alone in this battle  \n\t Reason : The Oponent with name initial of  " << other.getnameinitial() << "  doesn't exist or Platypus is not alive \n";
			std::cout << "\n\t Winner -> " << this->getnameinitial() << std::endl;  Print();
			return *this;
		}
		else if (this->Alive == false && other.Alive == true) {
			std::cout << "\n\tPlatypus called " << other.getnameinitial() << " is alone in this battle  \n\t Reason : The Oponent with name initial of   "<<this->getnameinitial() << "  doesn't exist or Platypus is not alive \n";
			std::cout << "\n\t Winner -> " << other.getnameinitial() << std::endl; other.Print();
			return other;
		}
		else 
		{
			std::cout << "\n\tFight Could not be succeed between Platypuses that are not alive or doesn't exists because of some incorecct attributes " << std::endl;
			other = Platypus(1, 100, 'X', 'X', false, true);//the attributes of the dead platypuses will be retuned in this case
			other.Print();
			return other;
		}
	}
	void eat()
	{
		
		if (Alive == false)
		{
			std::cout << "\n\tSince the Platypus is dead we can't eat him physically " << std::endl;
		}
		else
		{
			std::cout << "\n\tBefore eating the Weight of the platypus was : " << Weight_of_Platypus;
			float temp = Weight_of_Platypus;
			Weight_of_Platypus += Weight_of_Platypus * randomnumber(0.001, 0.05);//here we are generating the random numbers
			std::cout << "\n\tAfter eating : " << Weight_of_Platypus << std::endl;
			std::cout << "\n\tWeight is incremented with " << Weight_of_Platypus - temp << std::endl;
		}
	}
	void hatch(char name = 0)
	{
		//it is important that the hatched  platypus should be alive and the weight should be zero 
		if (Alive == true && Weight_of_Platypus >= 0)
			std::cerr << "\n\tHatching Process Failed \n\t Reason:  Platypus is already Alive " << std::endl;
		else if (Alive == false && Weight_of_Platypus >= 0)
		{
			name = random_characters_generator();
			char tempgender = gender_generator();
			NameInitial = name;
			Alive = true;
			Mutant = false;
			Age = 0;
			Weight_of_Platypus = randomnumber(0.1, 1.0);
			Gender = tempgender;
			std::cout << "\n\tPlatypus has been hatched successfully " << std::endl;
		}
	}
};
void Background()
{
	std::cout << "Mr. Burns doesn't care about almost anything ... but himself and his money. \n"
		<< "So, when his power plant leaked radioactive gooo that caused several species of wildlife to go\n"
		<< "extinct, he was only concerned with the public perception as it might effect his incomeand\n"
		<< "possible jail time.\n\tAfter the appearance of the three - eyed fish, Blinky, other rumors surfaced"
		<< "around the Springfield Nuclear Power Plant.One of them is high concern over the mutation rate"
		<< "of the rare Springfield molted platypus.With barely more than 50 left in the wild, the word"
		<< "extinction has been tossed around.\n\tSo, to quell the media, Mr.Burns had 30 of them captured,"
		<< "dissected, and analysed to check for signs of mutation.He found that the mutation rate is 2 %"
		<< "each month, but when they do mutate, they become sterileand cannot reproduce.With this \n information, he wants to create one of those newfangled computer simulations that the press "
		<< "loves so much.\n\n\n\t\tThat's where our programme and we are  come in! " << std::endl;
}
void SystemMainDisplay()
{
	char Want_OR_NOT;
	int ErrorCounter =0;
	int Ifyes = 0;
	std::cout << std::endl;
	std::cout << "\t\t"<<"        Platypus        " << std::endl;
	std::cout << std::endl;
	std::cout << "\n\t Until we start our program in particular Do you want to know the Background of the Story?  " << std::endl;
	std::cout << "\n\t Please Input y or n (capital letters are welcomed as well) \n\t y -> yes \t n -> no" << std::endl;
	do {
			
			std::cout << "\n\t\tYour answer: "; std::cin >> Want_OR_NOT;
			switch (Want_OR_NOT)
			{
			case 'y': Background(); Ifyes++;  break;
			case 'Y': Background(); Ifyes++; break;
			case 'n': break;
			case 'N': break;
			case 'yes':std::cout << "\t\tThere is shown the background of the Story " << std::endl; Background();  break;
			default:std::cout << "\n\tPlease Input  y or n ( capital letters are welcomed as well ) \n\tPlease Provide only those letters \n\tI am not getting what are you saying \n " << std::endl; ErrorCounter++;
				std::cout << "\tYou have " << 2 - ErrorCounter << " attempts remaining" << std::endl; break; 
			}
			if (Ifyes == 1)
			{
				std::cout << "Do you want to get additional information abput the Platypuses? " << std::endl;
			}
			

	} while ( Want_OR_NOT != 'N' && Want_OR_NOT != 'n' && ErrorCounter!=2 && Ifyes!=2);
	system("cls");
	if (Ifyes == 2)
	{
		std::cout << "\n\n\t Follow me We Will travel in the world of Platypuses \n ===================================================================== \n " << std::endl;
	}
	else
		std::cout << "\n\n\t That's Okay Let's work with our general task \n ===================================================================== \n " << std::endl;
}
void yesornot()
{
	
	std::cout << "\n\t Please Input y or n (capital letters are welcomed as well) \n\t y -> yes \t n -> no";
	std::cout << "\n\t\tYour answer: ";
}
int main()
{
	char gender;
	short int age;
	float weight;
	std::string Yes_or_not;
	std::string vital_battle;

	int errorcounter = 0;
	int errorcounter1 = 0;
	int errorcounter2 = 0;
	system("color 4");
	SystemMainDisplay();
	system("color 6");
	/*(float weight, short age, char name, char gender, bool alive, bool mutant)*/

	Platypus First_Platypuse(1, 0, 'k', 'm', true, false );

	First_Platypuse.Print();

	std::cout << "\n\tDo you want to increase the age of  platypus ? ";

	yesornot();

	std::cin >> Yes_or_not;

	if (Yes_or_not == "y" || Yes_or_not == "yes" || Yes_or_not == "Y" || Yes_or_not == "YES" || Yes_or_not == "why not" || Yes_or_not == "WHY NOT")
	{
		short int age;
		std::cout << "Age to increment The platypus : "; std::cin >> age;
		First_Platypuse.age_me(age);
	}

	std::cout << "\t What about Lunch? " << std::endl;

	yesornot();

	std::cin >> Yes_or_not;

	if (Yes_or_not == "y" || Yes_or_not == "yes" || Yes_or_not == "Y" || Yes_or_not == "YES" || Yes_or_not == "why not" || Yes_or_not == "WHY NOT")
	{
		First_Platypuse.eat();
	}

	Platypus Second_Platypus                    ( 10,  11,   'T',     'f',   true, false);

	Second_Platypus.Print();
	Second_Platypus.age_me(2);

	std::cout << "\t\nAfter increasing the age : " << Second_Platypus.getage() << std::endl;
	std::cout << "\n\tThird Platypus " << std::endl;
	Platypus Third_Platypuse                    ( 12,  23,   'r',     'M',	 true, false);
	//invalid age
	std::cout << "\n\tage before setting " << Third_Platypuse.getage() << " \n after setting ";
	Third_Platypuse.setage(5);
	std::cout << " it becomes  " << Third_Platypuse.getage();
	Third_Platypuse.Print();
	Platypus Fourth_Platypus					( 0,   2,    'd',     'F',   false, false);
	std::cout << "\n\tFourth Platypus" << std::endl;
	Fourth_Platypus.eat();
	Fourth_Platypus.setalive(true);
	Fourth_Platypus.Print();
	Platypus Fifth_Platypus						( 5,   50,   'p',     'm',	 true, true);
	std::cout<<"\t\ngender initial of the  Fifth platypus is : "<<Fifth_Platypus.getgenderInitial()<<std::endl;
	Platypus Sixth_Platypus						( 56,  6,    'J',     'f',	 true, false);
	Sixth_Platypus.setmutant(true);
	std::cout << "\n\tIs Sixth Platypus Mutant? " << Sixth_Platypus.ismutant() << std::endl;
	Platypus Seventh_Platypus					( 2000,   'l',  'M',     'k',   false, true);
	Seventh_Platypus.Print();
	std::cout << "\n\tthere You Have inserted incorrectly  some Properties \n Do you want to set them  manually again?" << std::endl;
	yesornot();
	std::cin >> Yes_or_not;
	if (Yes_or_not == "y" || Yes_or_not == "yes" || Yes_or_not == "Y" || Yes_or_not == "YES" )
	{
		
		do {
			std::cout << "\n\tPlease only 'm' , 'M' ,'f'  or 'F" << std::endl;
			std::cout << "\n\tChange Gender : " ;
			std::cin >> gender; errorcounter++;
			if (gender != 'm' && gender != 'f' && gender != 'M' && gender != 'F')
			{
				errorcounter++;
			}
		} while (gender != 'm' && gender != 'f' && gender != 'M' && gender != 'F' && errorcounter!=2);
		if (errorcounter != 2)
		{
			Seventh_Platypus.setgender(gender);
			std::cout << "\n\tThe platypus  gender changed succesfully " << std::endl;
		}
		else
		{
			std::cout << "\n\tPlatypus gender changing Process Failed invalid input again " << std::endl;
		}

		std::cout << "\n\tChange Age : ";
		std::cin >> age;
		while (std::cin.fail() && errorcounter1 != 2)
		{
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
			std::cout << "\n\tInvalid age " << std::endl;
			std::cout << "\n\tChange Age : ";
			std::cin >> age;
			errorcounter1++;
		}
		if (errorcounter1 != 2)
		{
			std::cout << "\n\tThe platypus age changed succesfully " << std::endl;
			Seventh_Platypus.setage(age);
		}
		else
		{
			std::cout << "\n\tPlatypus age changing Process Failed invalid input again " << std::endl;
		}

		std::cout << "\n\tChange weight : ";
		std::cin >> age;
		while (std::cin.fail() && errorcounter2 != 2)
		{
			std::cin.clear();
			std::cin.ignore(1000000, '\n');
			std::cout << "\n\tInvalid input " << std::endl;
			std::cout << "\n\tChange Weight : ";
			std::cin >> age;
			errorcounter2++;
		}
		if (errorcounter2 != 2)
		{
			std::cout << "\n\tThe platypus weight changed succesfully " << std::endl;
			Seventh_Platypus.setage(age);
		}
		else
		{
			std::cout << "\n\tPlatypus weight changing Process Failed invalid input " << std::endl;
		}
		Seventh_Platypus.Print();
	}
	else
		{
			std::cout << std::endl;
		}

	Platypus Eight_Platypus						('m',  3,     1,     'l',    false, false);
	std::cout << "\n\tChange weight : ";
	std::cin >> age;
	while (std::cin.fail() && errorcounter2 != 2)
	{
		std::cin.clear();
		std::cin.ignore(1000000, '\n');
		std::cout << "\n\tInvalid input " << std::endl;
		std::cout << "\n\tChange Weight : ";
		std::cin >> age;
		errorcounter2++;
	}
	if (errorcounter2 != 2)
	{
		Eight_Platypus.setage(age);
	}
	else
	{
		std::cout << "\n\tPlatypus weight changing Process Failed invalid input again " << std::endl;
	}
	Eight_Platypus.Print();
	Platypus NInth_Platypus					( 4,   0,    'H',     'F',	 false, false);
	std::cout<<"\n\tName initial of NInth Platypus is : "<<NInth_Platypus.getnameinitial();
	Platypus tenth_Platypus;//without specifying parameters;
	tenth_Platypus.hatch();
	tenth_Platypus.age_me(3);
	
	std::cout << "\t\nTime to call the fight function  do you want to  follow me in vital battles  ? " ;
	std::cin >> vital_battle;
	if (vital_battle == "y" || vital_battle == "yes" || vital_battle == "Y" || vital_battle == "YES" || vital_battle == "why not" || vital_battle == "WHY NOT")
	{
		system("cls");
		std::cout << "\n\tFight between first and second Platypuses " << std::endl;
		First_Platypuse.fight(Second_Platypus);
		std::cout << std::endl << "\n\tFight between tenth and seventh Platypuses  " << std::endl;
		tenth_Platypus.fight(Seventh_Platypus);
		std::cout << std::endl << "\n\tFight between third  and sixth Platypuses  " << std::endl;
		Third_Platypuse.fight(Sixth_Platypus);
		std::cout << std::endl << "\n\tFight between second  and eight Platypuses  " << std::endl;
		Second_Platypus.fight(Eight_Platypus);
	}
	else
	{
		system("cls");
		std::cout << "\n\t Goodbye Dear user , I hope We meet each other again " << std::endl;
	}
	
	std::cout << "\n\t Goodbye Dear user , I hope We meet each other again " << std::endl;
	
	return 0;
}