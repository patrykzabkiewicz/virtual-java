/**
*
*  Control Version System (c) 2016 Patryk Zabkiewicz
*
*  e-mail: pzabkiewicz@gmail.com
*
*	main languge is C++
*
*  Purpose: Provide a secure way to edit codes in corporate enviroment
*  so that no-developer can steal code from you, and you have most of
*  the control what edited and what's not
*
*/

#include <stdlib.h>
#include <list>

#define SUCCESS 0
#define ERR_1 -1    /* IO error */
#define ERR_2 -2    /* Calculation error */

using namespace std;

struct File {
	int id;
	char hash[40];
	string path;
};

struct Change {
	int id;                 /* simple counter */
	int date;               /* date of the change */
	char hash[40];          /* hash id of the change */
	char prev[40];          /* hash of previous change */
	string description;     /* brief description of the change */
};

list<Change> * changeList;

void calculate_hash(Change * ch);

/*
 * scan files in the folder
 *  - check if the files were changed in some way
 */
void scan_files(string * path);

int main(int argc, char *argv[]) {

	// init
	changeList = new list<Change>();

	// open
	

	return SUCCESS;
}
