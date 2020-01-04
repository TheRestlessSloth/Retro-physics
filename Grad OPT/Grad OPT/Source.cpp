#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double e = 0.01;
double lmd = 0.01;
bool ostanova = false;
double sx[2], x[2];


double df_dx0(double x)
{
	return 18 * x;
}

double df_dx1(double x) {
	return 2 * x;
}

void gradfixed() {
	x[0] = 1;
	x[1] = 1;
	cout << "! " << x[0] << " " << x[1] << endl;
	int i = 0;

	do {
		sx[0] = x[0];
		sx[1] = x[1];

		x[0] = x[0] - lmd * df_dx0(x[0]);
		x[1] = x[1] - lmd * df_dx1(x[1]);

		i++;
		cout << setprecision(7) << fixed << "gi=" << i << "|\t" << x[0] << " " << x[1] << endl;
	} while ((sx[0] + sx[1]) - (x[0] + x[1]) > e);

	return;
}

void graddiv() {
	x[0] = 1;
	x[1] = 1;
	cout << "! " << x[0] << " " << x[1] << endl;
	int i = 0;

	do {
		sx[0] = x[0];
		sx[1] = x[1];

		x[0] = x[0] - lmd/2 * df_dx0(x[0]);
		x[1] = x[1] - lmd/2 * df_dx1(x[1]);

		i++;
		cout << setprecision(7) << fixed << "gi=" << i << "|\t" << x[0] << " " << x[1] << endl;
	} while ((sx[0] + sx[1]) - (x[0] + x[1]) > e);

	return;
}

void gradacceler() {
	x[0] = 1;
	x[1] = 1;
	cout << "! " << x[0] << " " << x[1] << endl;
	int i = 0;

	do {
		sx[0] = x[0];
		sx[1] = x[1];

		x[0] = x[0] - lmd/(i+1) * df_dx0(x[0]);
		x[1] = x[1] - lmd/(i+1) * df_dx1(x[1]);

		i++;
		cout << setprecision(7) << fixed << "gi=" << i << "|\t" << x[0] << " " << x[1] << endl;
	} while ((sx[0] + sx[1]) - (x[0] + x[1]) > e);

	return;
}

int main() {
	gradfixed();
	cout << "------------------------------------------------" << endl;
	graddiv();
	cout << "------------------------------------------------" << endl;
	gradacceler();
	cout << "------------------------------------------------" << endl;

}