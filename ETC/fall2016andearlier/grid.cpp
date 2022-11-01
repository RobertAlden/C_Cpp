#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

int main()
{
int gmx, gmy, gx, gy, mazeSize, dir;
srand (time(NULL));
gmx = 40;
gmy = 20;
mazeSize = gmx * gmy / 4;
gx = (rand() % (gmx-6)) + 3;
gy = (rand() % (gmy-6)) + 3;
char a[gmx][gmy];
for (int row=0; row<gmy; row++) {
    for (int col=0; col<gmx; col++) {
        a[row][col] = 0;
    }
}
a[gx][gy] = 2;

for (int i=0; i<mazeSize; i++) {
dir = rand() % 4 + 1;
switch (dir)
{
	case 1 :
	if (gy > 3)
	gy--;
	a[gx][gy] = 1;
	gy--;
	break;
	case 2 :
	if (gx < gmx - 4)
	{
	gx++;
	a[gx][gy] = 1;
	gx++;
	}
	break;
	case 3 :
	if (gy < gmy - 4)
	{
	gy++;
	a[gx][gy] = 1;
	gy++;
	}
	break;
	case 4 :
	if (gx > 3)
	{
	gx--;
	a[gx][gy] = 1;
	gx--;
	}
	break;
}
a[gx][gy] = 1;
}

for (int col=0; col<gmy; col++) {
    for (int row=0; row<gmx; row++) {
	usleep(5000);
        if (a[row][col] == 0)
		{
			cout << "# ";
		};
	if (a[row][col] == 1)
		{
			cout << ". ";
		};
	if (a[row][col] == 2)
		{
			cout << "@ ";
		};	
    }
	cout << endl;
}

return(0);
}

